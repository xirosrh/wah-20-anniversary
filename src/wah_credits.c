#include "global.h"
#include "strings.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "list_menu.h"
#include "item_icon.h"
#include "item_use.h"
#include "international_string_util.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trainer_pokemon_sprites.h"
#include "overworld.h"
#include "event_data.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "constants/species.h"
#include "sprite.h"
#include "window.h"


const u32 WahCredits_Tileset[] = INCBIN_U32("graphics/wah_credits/wahCredits_tiles.4bpp.lz");
const u32 WahCredits_Tilemap[] = INCBIN_U32("graphics/wah_credits/wahCredits_map.bin.lz");
const u16 WahCredits_Palette[] = INCBIN_U16("graphics/wah_credits/wahCredits.gbapal");

enum{
    BG_CREDITS,
    BG_LOGO
};

static const struct BgTemplate CreditsBgTemplates[] =
{
    [BG_CREDITS] = 
    {
        .bg = 0, 
        .charBaseIndex = 0, 
        .mapBaseIndex = 25, 
        .priority = 0 
    },
    [BG_LOGO] =
    {
        .bg = 1,
        .charBaseIndex = 3,
        .mapBaseIndex = 31,
        .priority = 2
    }
};

//========== SECCIÓN: FUNCIONES DE CARGA DE BGS ==========//

static void ResetGpuAndVram(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);

    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);

    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);

    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
    DmaFill16(3, 0, (void *)(PLTT + 2), PLTT_SIZE - 2);
}

static void LoadBgs(void)
{
    InitBgsFromTemplates(0, CreditsBgTemplates, ARRAY_COUNT(CreditsBgTemplates));

    LZ77UnCompVram(WahCredits_Tileset, (void*) BG_CHAR_ADDR(CreditsBgTemplates[BG_LOGO].charBaseIndex));
    LZ77UnCompVram(WahCredits_Tilemap, (u16*) BG_SCREEN_ADDR(CreditsBgTemplates[BG_LOGO].mapBaseIndex));

    LoadPalette(WahCredits_Palette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);

    ResetAllBgsCoordinates(); 

    ShowBg(BG_CREDITS);
    ShowBg(BG_LOGO);
    /* ResetGpuAndVram pone DISPCNT a 0; ShowBg solo ajusta bits de fondo, no OBJ. */
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
}

static void VBlank_CB_Credits(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_Credits(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

//========== SECCIÓN: FUNCIONES DE CARGA DE WINDOWS ==========//

enum
{
    WINDOW_CREDITS,
    WINDOW_COUNT,
};

static const struct WindowTemplate sWindowTemplatesCredits[] =
{
    [WINDOW_CREDITS]
    {
        .bg = 0, 
        .tilemapLeft = 5, 
        .tilemapTop = 13, 
        .width = 20, 
        .height = 10, 
        .paletteNum = 15, 
        .baseBlock = 1 
    },
    DUMMY_WIN_TEMPLATE,
};

static void InitWindowCredits(void)
{
	InitWindows(sWindowTemplatesCredits);
    DeactivateAllTextPrinters();
	LoadPalette(GetOverworldTextboxPalettePtr(), BG_PLTT_ID(15), PLTT_SIZE_4BPP); 

    PutWindowTilemap(WINDOW_CREDITS);
    CopyWindowToVram(WINDOW_CREDITS, 3);
}

#include "field_effect.h"

#define LINES_GROUP 6
#define TIMER_TRAINER_SPRITE 100
#define TIMER_CREDITS 120
#define TIMER_CREDITS_SPRITE_SYNC 150

const u8 sTextColorWhiteCreditsWah[]= {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY};
const u8 sTextColor2CreditsWah[]= {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_RED, TEXT_COLOR_DARK_GRAY};

struct WahCredits
{
    const u8 *title;
    const u8 *sListCredits[50];
};

static const struct WahCredits sWahCreditsSections[] =
{
    {
        .title = COMPOUND_STRING("CREADORES PRINCIPALES"),
        .sListCredits =
        {
            COMPOUND_STRING("Caco5400 & Xiros"),
            NULL
        }
    },
    {
        .title = COMPOUND_STRING("COLABORADORES"),
        .sListCredits = 
        { 
            COMPOUND_STRING("Gameboy_cl"),
            COMPOUND_STRING("Gosuto"),
            COMPOUND_STRING(""), //Empty on purpose
            
            COMPOUND_STRING("Erkey830"),
            COMPOUND_STRING("Micolo"),
            COMPOUND_STRING(""), //Empty on purpose


            COMPOUND_STRING("Alexmad"),
            COMPOUND_STRING("MrNightology"),
            COMPOUND_STRING("Acimut"),
            
            COMPOUND_STRING("Kaktus"),
            COMPOUND_STRING("Ryuzaki"),
            COMPOUND_STRING(""), //Empty on purpose
            NULL
        },
    },
    {
        .title = COMPOUND_STRING("CREDITOS"),
        .sListCredits =
        {
            COMPOUND_STRING("Star Gazaar"),
            COMPOUND_STRING("X-TERRA"),
            COMPOUND_STRING("liovy"),

            COMPOUND_STRING("Samu"),
            COMPOUND_STRING("CompuMax"),
            COMPOUND_STRING("Axel Loquendo"),


            COMPOUND_STRING("Howdy"),
            COMPOUND_STRING("RevkenHack"),
            COMPOUND_STRING("Hedara"),

            COMPOUND_STRING("Mudskip"),
            COMPOUND_STRING("Archie"),
            COMPOUND_STRING("Lykeron"),


            COMPOUND_STRING("Juanjo"),
            COMPOUND_STRING("Luna"),
            COMPOUND_STRING("ghoulslash"),

            COMPOUND_STRING("aethestode"),
            COMPOUND_STRING("gogglesdegiraffe"),
            COMPOUND_STRING(""), //Empty on purpose
            
            
            COMPOUND_STRING("Big Snort"),
            COMPOUND_STRING("TheXaman"),
            COMPOUND_STRING("Retro NC"),
            
            COMPOUND_STRING("Boxheadpaint"),
            COMPOUND_STRING("Galton"),
            COMPOUND_STRING("DestvoL"),
            

            COMPOUND_STRING("Lmburningsoul"),
            COMPOUND_STRING("Tiempillo"),
            COMPOUND_STRING("Oom"),

            NULL
        }
    },
    {
        .title = COMPOUND_STRING("AGRADECIMIENTOS"),
        .sListCredits =
        {
            COMPOUND_STRING("Pret"),
            COMPOUND_STRING("RHH"),
            COMPOUND_STRING("PBH"),

            COMPOUND_STRING("WAH"),
            COMPOUND_STRING("Huderlem"),
            COMPOUND_STRING("grunt-lucas"),


            COMPOUND_STRING("Baro"),
            COMPOUND_STRING("Serg!o"),
            COMPOUND_STRING("eing"),

            COMPOUND_STRING("Scarex"),
            COMPOUND_STRING("Tokyn"),
            COMPOUND_STRING("Gallego13"),


            COMPOUND_STRING("cosarara97"),
            COMPOUND_STRING("Helix Boo"),
            COMPOUND_STRING("Angel"),

            COMPOUND_STRING("Cheve"),
            COMPOUND_STRING("Javi4315"),
            COMPOUND_STRING("Katherine"),


            COMPOUND_STRING("ReoNeky"),
            COMPOUND_STRING("Sayer"),
            COMPOUND_STRING("BLAx501!"),

            COMPOUND_STRING("KleinStudio"),
            COMPOUND_STRING("DavZero"),
            COMPOUND_STRING("War"),


            COMPOUND_STRING("PkPower"),
            COMPOUND_STRING("Drive"),
            COMPOUND_STRING("Aguiar"),

            COMPOUND_STRING("Jack Johnson"),
            COMPOUND_STRING("Omega"),
            COMPOUND_STRING("Javs"),


            COMPOUND_STRING("Ozumas"),
            COMPOUND_STRING("MAIDEN"),
            COMPOUND_STRING("Dragonsden"),

            COMPOUND_STRING("Morti"),
            COMPOUND_STRING("Kakarotto"),
            COMPOUND_STRING("Criisss"),


            COMPOUND_STRING("Ivantxo"),
            COMPOUND_STRING("Seven7hNight"),
            COMPOUND_STRING(""), //Empty on purpose

            COMPOUND_STRING("CALENTADASTCG"),
            COMPOUND_STRING(""), //Empty on purpose
            COMPOUND_STRING(""), //Empty on purpose

            NULL
        }
    },
    {   
        .title = COMPOUND_STRING("EN MEMORIA DE"),
        .sListCredits =
        {
            COMPOUND_STRING("Cope"),
            NULL
        }
    },
    {   
        .title = COMPOUND_STRING("ESTO FUE UNA CELEBRACIÓN DE"),
        .sListCredits =
        {
            COMPOUND_STRING("21 años de Whack a Hack"),
            NULL
        }
    }
};

// static const u8 trainnerWahList[][2] =
// {
//     {TRAINER_PIC_OMEGA, TRAINER_NONE},
//     {TRAINER_PIC_XIROS, TRAINER_NONE},
//     {TRAINER_PIC_GALLEGO, TRAINER_PIC_KATHERINE},
//     {TRAINER_PIC_DRIVE, TRAINER_NONE},
//     {TRAINER_PIC_BOO, TRAINER_NONE},
//     {TRAINER_PIC_SERGIO, TRAINER_NONE},
//     {TRAINER_PIC_REONEKY, TRAINER_NONE},
//     {TRAINER_PIC_JAVS, TRAINER_NONE},
//     {TRAINER_PIC_OZUMAS, TRAINER_NONE},
//     {TRAINER_PIC_SAYER, TRAINER_NONE},
//     {TRAINER_PIC_DRIVE, TRAINER_NONE},
//     {TRAINER_PIC_JACK_JOHNSON, TRAINER_NONE},
//     {TRAINER_PIC_ZERO, TRAINER_NONE}
// };

static const u8 trainnerWahList[][2] =
{
    {TRAINER_PIC_CACO, TRAINER_PIC_XIROS},
    {TRAINER_PIC_CHEVE, TRAINER_PIC_EING},
    {TRAINER_PIC_REONEKY, TRAINER_PIC_KATHERINE},
    {TRAINER_PIC_DRIVE, TRAINER_PIC_ANGEL},
    {TRAINER_PIC_SCAREX, TRAINER_PIC_COSARARA},
    {TRAINER_PIC_ZERO, TRAINER_PIC_AGUIAR},
    {TRAINER_PIC_BARO, TRAINER_PIC_GOCE},
    {TRAINER_PIC_PKPOWER, TRAINER_PIC_KLEIN},
    {TRAINER_PIC_OMEGA, TRAINER_NONE},
    {TRAINER_PIC_JACK_JOHNSON, TRAINER_PIC_SAYER},
    {TRAINER_PIC_BLAX, TRAINER_PIC_OZUMAS},
    {TRAINER_PIC_DRIVE, TRAINER_PIC_WAR},
    {TRAINER_PIC_GALLEGO, TRAINER_PIC_KATHERINE},
    {TRAINER_PIC_JAVS, TRAINER_PIC_BOO},
    {TRAINER_PIC_SERGIO, TRAINER_NONE},
    {TRAINER_PIC_GAMEBOY_CL, TRAINER_PIC_ALEXMAD},
    {TRAINER_PIC_GOSUTO, TRAINER_PIC_ACIMUT},
    {TRAINER_PIC_MICOLO, TRAINER_PIC_ERKEY },
    {TRAINER_PIC_ROXAS, TRAINER_PIC_RYUZAKI},
    {TRAINER_PIC_KAKTUS, TRAINER_PIC_MRNIGHTOLOGY},
};

static const u16 sWahCreditsPokemonList[] =
{
    SPECIES_ELECTRODES,
    SPECIES_PLUGOINK,
    SPECIES_EING,
    SPECIES_DIRAEI,
    SPECIES_ARMORED_MEWTWO,
    SPECIES_VENUSAUR_C,
    SPECIES_CHARIZARD_C,
    SPECIES_BLASTOISE_C,
    SPECIES_FREECH,
    SPECIES_DRAGONITE_MEGA,
    SPECIES_GRENINJA_R,
    SPECIES_GOROCHU,
    SPECIES_DUN,
    SPECIES_LATIKEN,
    SPECIES_FERALIGATR_MEGA,
    SPECIES_JARDINO,
    SPECIES_OCEADINO,
    SPECIES_TYRADINO,
    SPECIES_GRENINJA_MEGA,
    SPECIES_MOLTRES,
};


u8 PrintCredits(u8 windowId, u8 sectionId, u8 indexToContinue)
{
    u8 i;
    u8 x = 0;
    u8 y = 0;
    u8 count = 0;

    const u8 gText_SpaceBetweenNames[] = _("  ");

    FillWindowPixelBuffer(windowId, PIXEL_FILL(0));

    x = GetStringCenterAlignXOffset(FONT_NORMAL, sWahCreditsSections[sectionId].title, sWindowTemplatesCredits[0].width*8);
    AddTextPrinterParameterized3(windowId, FONT_NORMAL, x, y, sTextColor2CreditsWah, 0, sWahCreditsSections[sectionId].title);

    y += 14;
    gStringVar1[0] = EOS;

    for ( i = indexToContinue;  sWahCreditsSections[sectionId].sListCredits[i] != NULL; i++)
    {   
        if(count == LINES_GROUP || sWahCreditsSections[sectionId].sListCredits[i] == NULL)
            break;

        StringAppend(gStringVar1, sWahCreditsSections[sectionId].sListCredits[i]);
        count += 1;

        if( (i+1) % 3 == 0 || sWahCreditsSections[sectionId].sListCredits[i+1] == NULL)
        {
            x = GetStringCenterAlignXOffset(FONT_NORMAL, gStringVar1, sWindowTemplatesCredits[0].width*8);
            AddTextPrinterParameterized3(windowId, FONT_NORMAL, x, y, sTextColorWhiteCreditsWah, 0, gStringVar1);
            y += 14;
            gStringVar1[0] = EOS;
            continue;
        }

        StringAppend(gStringVar1, gText_SpaceBetweenNames);
    }
    
    CopyWindowToVram(windowId, COPYWIN_FULL);

    return i;
}

#define tIndex data[0]
#define tSection data[1]
#define tTrainerSpriteId1 data[2]
#define tTrainerSpriteId2 data[3]
#define tIndexTrainer data[4]
#define tNumCreditsSteps data[5]
#define tSpriteTimer data[6]
#define tTimer data[7]
#define tTrainerPicId1 data[8]
#define tTrainerPicId2 data[9]
#define tSpriteMode data[10]
#define tIndexPokemon data[11]

enum
{
    CREDITS_SPRITE_MODE_TRAINER,
    CREDITS_SPRITE_MODE_POKEMON,
};

static void Task_TrainnerSlice(u8 taskId);


static void CreateCreditsTrainerSprite(u8 trainerPicId, s16 x, s16 y, s16 *spriteId, s16 *storedTrainerPicId)
{
    *storedTrainerPicId = trainerPicId;
    *spriteId = CreateTrainerSprite(trainerPicId, x, y, 0, NULL);
}

static void DestroyCreditsTrainerSprite(s16 *spriteId, s16 *trainerPicId)
{
    if (*spriteId != 0xFF)
    {
        if (*trainerPicId != 0xFF)
        {
            FreeSpriteTilesByTag(*trainerPicId);
            FreeSpritePaletteByTag(*trainerPicId);
        }
        DestroySprite(&gSprites[*spriteId]);
    }

    *spriteId = 0xFF;
    *trainerPicId = 0xFF;
}

static void CreateCreditsPokemonSprite(u16 species, s16 x, s16 y, s16 *spriteId)
{
    u16 createdSpriteId = CreateMonPicSprite(species, FALSE, 0, TRUE, x, y, 0, TAG_NONE);

    *spriteId = (createdSpriteId == 0xFFFF) ? 0xFF : createdSpriteId;
}

static void DestroyCreditsPokemonSprite(s16 *spriteId)
{
    if (*spriteId != 0xFF)
        FreeAndDestroyMonPicSprite(*spriteId);

    *spriteId = 0xFF;
}

static void DestroyActiveCreditsSprites(u8 taskId)
{
    if (gTasks[taskId].tSpriteMode == CREDITS_SPRITE_MODE_POKEMON)
    {
        DestroyCreditsPokemonSprite(&gTasks[taskId].tTrainerSpriteId1);
        gTasks[taskId].tTrainerSpriteId2 = 0xFF;
        gTasks[taskId].tTrainerPicId1 = 0xFF;
        gTasks[taskId].tTrainerPicId2 = 0xFF;
    }
    else
    {
        DestroyCreditsTrainerSprite(&gTasks[taskId].tTrainerSpriteId1, &gTasks[taskId].tTrainerPicId1);
        DestroyCreditsTrainerSprite(&gTasks[taskId].tTrainerSpriteId2, &gTasks[taskId].tTrainerPicId2);
    }
}

static void Task_ShowCreditsWAH(u8 taskId)
{
    u8 taskId2 = 0;

    if(gTasks[taskId].tTimer % TIMER_CREDITS == 0)
    {   
        if(sWahCreditsSections[gTasks[taskId].tSection].sListCredits[gTasks[taskId].tIndex] == NULL)
        {
            gTasks[taskId].tSection += 1;
            gTasks[taskId].tIndex = 0;
        }

        if(gTasks[taskId].tSection >= ARRAY_COUNT(sWahCreditsSections) - 1)
        {
            taskId2 = FindTaskIdByFunc(Task_TrainnerSlice);
            
            FillWindowPixelBuffer(WINDOW_CREDITS, PIXEL_FILL(0));
            CopyWindowToVram(WINDOW_CREDITS, COPYWIN_FULL);

            if(taskId2 !=  TASK_NONE) 
            {
                DestroyCreditsTrainerSprite(&gTasks[taskId2].tTrainerSpriteId1, &gTasks[taskId2].tTrainerPicId1);
                DestroyCreditsTrainerSprite(&gTasks[taskId2].tTrainerSpriteId2, &gTasks[taskId2].tTrainerPicId2);
                DestroyTask(taskId2);
            }
            
            DestroyTask(taskId);
        }

        gTasks[taskId].tIndex = PrintCredits(WINDOW_CREDITS, gTasks[taskId].tSection, gTasks[taskId].tIndex);
    }

    gTasks[taskId].tTimer += 1;
}



static void Task_TrainnerSlice(u8 taskId)
{
    u8 x = 120;

    if (gTasks[taskId].tTimer++ % TIMER_TRAINER_SPRITE != 0)
        return;

    DestroyCreditsTrainerSprite(&gTasks[taskId].tTrainerSpriteId1, &gTasks[taskId].tTrainerPicId1);
    DestroyCreditsTrainerSprite(&gTasks[taskId].tTrainerSpriteId2, &gTasks[taskId].tTrainerPicId2);

    if(gTasks[taskId].tIndexTrainer >= ARRAY_COUNT(trainnerWahList) - 1)
        gTasks[taskId].tIndexTrainer = 0;

    //Crear los sprites
    if(trainnerWahList[gTasks[taskId].tIndexTrainer][1] != TRAINER_NONE)
        x = 100;

    CreateCreditsTrainerSprite(trainnerWahList[gTasks[taskId].tIndexTrainer][0], x, 60,
                               &gTasks[taskId].tTrainerSpriteId1, &gTasks[taskId].tTrainerPicId1);

    if(trainnerWahList[gTasks[taskId].tIndexTrainer][1] != TRAINER_NONE)
        CreateCreditsTrainerSprite(trainnerWahList[gTasks[taskId].tIndexTrainer][1], x+30, 60,
                                   &gTasks[taskId].tTrainerSpriteId2, &gTasks[taskId].tTrainerPicId2);

    gTasks[taskId].tIndexTrainer += 1;
}


static void Task_EndCredits(u8 taskId);


static u8 GetTotalCreditsSteps(void)
{
    u16 totalSteps = 0;

    for (u8 section = 0; section < ARRAY_COUNT(sWahCreditsSections); section++)
    {
        u16 linesInSection = 0;

        // Contar líneas de esta sección
        for (u16 i = 0; sWahCreditsSections[section].sListCredits[i] != NULL; i++)
            linesInSection++;

        // Calcular grupos de 6 para ESTA sección
        u16 stepsInSection = linesInSection / LINES_GROUP;
        if (linesInSection % LINES_GROUP != 0)
            stepsInSection++; // último grupo incompleto

        totalSteps += stepsInSection;
    }

    return totalSteps;
}

#define X_TRAINER_POS 120

static void Task_ShowCreditsAndTrainers(u8 taskId)
{
    u8 x = X_TRAINER_POS;
    u8 spriteStepInterval = 0;
    u8 totalSprites = ARRAY_COUNT(trainnerWahList);
    u8 totalSpriteSlots = totalSprites + ARRAY_COUNT(sWahCreditsPokemonList);

    // Incrementar timer
    gTasks[taskId].tTimer++;

    // Avanzar texto cada TIMER_CREDITS ticks
    if (gTasks[taskId].tTimer % TIMER_CREDITS == 0)
    {
        // -----------------------------
        // Avanzar texto
        // -----------------------------
        if (sWahCreditsSections[gTasks[taskId].tSection].sListCredits[gTasks[taskId].tIndex] != NULL)
        {
            gTasks[taskId].tIndex = PrintCredits(WINDOW_CREDITS, gTasks[taskId].tSection, gTasks[taskId].tIndex);
        }
        else
        {
            // Pasar a la siguiente sección
            gTasks[taskId].tSection++;
            gTasks[taskId].tIndex = 0;
        }
    }

    // -----------------------------
    // Calcular la sincronización proporcional de sprites
    // -----------------------------
    
    if (totalSpriteSlots == 0) return;

    spriteStepInterval =  (TIMER_CREDITS_SPRITE_SYNC*gTasks[taskId].tNumCreditsSteps) / totalSpriteSlots;


    // Incrementar contador de sprites
    gTasks[taskId].tSpriteTimer++;

    if (gTasks[taskId].tSpriteTimer >= spriteStepInterval)
    {
        gTasks[taskId].tSpriteTimer = 0;

        // -----------------------------
        // Destruir sprites anteriores
        // -----------------------------
        DestroyActiveCreditsSprites(taskId);

        if (gTasks[taskId].tSpriteMode == CREDITS_SPRITE_MODE_TRAINER
         && gTasks[taskId].tIndexTrainer >= totalSprites)
        {
            gTasks[taskId].tSpriteMode = CREDITS_SPRITE_MODE_POKEMON;
            gTasks[taskId].tIndexPokemon = 0;
        }

        // -----------------------------
        // Crear nuevos sprites
        // -----------------------------
        if (gTasks[taskId].tSpriteMode == CREDITS_SPRITE_MODE_POKEMON)
        {
            CreateCreditsPokemonSprite(sWahCreditsPokemonList[gTasks[taskId].tIndexPokemon],
                                       X_TRAINER_POS, 60, &gTasks[taskId].tTrainerSpriteId1);
            gTasks[taskId].tIndexPokemon++;
            if (gTasks[taskId].tIndexPokemon >= ARRAY_COUNT(sWahCreditsPokemonList))
                gTasks[taskId].tIndexPokemon = 0;
        }
        else
        {
            if (trainnerWahList[gTasks[taskId].tIndexTrainer][1] != TRAINER_NONE)
                x = 100;

            CreateCreditsTrainerSprite(trainnerWahList[gTasks[taskId].tIndexTrainer][0], x, 60,
                                       &gTasks[taskId].tTrainerSpriteId1, &gTasks[taskId].tTrainerPicId1);
            if (trainnerWahList[gTasks[taskId].tIndexTrainer][1] != TRAINER_NONE)
                CreateCreditsTrainerSprite(trainnerWahList[gTasks[taskId].tIndexTrainer][1], x + 30, 60,
                                           &gTasks[taskId].tTrainerSpriteId2, &gTasks[taskId].tTrainerPicId2);

            gTasks[taskId].tIndexTrainer++;
        }
    }

    // -----------------------------
    // Comprobar fin de créditos
    // -----------------------------
    if (gTasks[taskId].tSection >= ARRAY_COUNT(sWahCreditsSections))
        gTasks[taskId].func = Task_EndCredits;
}


static void Task_WahCreditsSoftReset(u8 taskId)
{
    if (!gPaletteFade.active)
        SoftReset(RESET_ALL);
}

static void Task_EndCredits(u8 taskId)
{
    // Limpiar ventana
    FillWindowPixelBuffer(WINDOW_CREDITS, PIXEL_FILL(0));
    CopyWindowToVram(WINDOW_CREDITS, COPYWIN_FULL);

    // Destruir sprites finales
    DestroyActiveCreditsSprites(taskId);

    FadeOutBGM(4);
    BeginNormalPaletteFade(PALETTES_ALL, 8, 0, 16, RGB_WHITEALPHA);
    gTasks[taskId].func = Task_WahCreditsSoftReset;
}


void CB2_InitCreditsSetUp(void)
{
    u8 x = X_TRAINER_POS;
    u8 taskId = 0;

    switch (gMain.state)
    {
    case 0:
        SetVBlankHBlankCallbacksToNull();
        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        ResetAllPicSprites();
        ResetPaletteFade();
        ResetGpuAndVram();
        FreeAllSpritePalettes();
        gMain.state++;
    case 1:
        VBlank_CB_Credits();
        CB2_Credits();
        gMain.state++;
        break;
    case 2:
        LoadBgs();
        InitWindowCredits();
        FadeOutAndPlayNewMapMusic(MUS_TV_GOTTA_CATCH_EM_ALL, 4);
        gMain.state++;
        break;
    case 3:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;

    default:
        SetVBlankCallback(VBlank_CB_Credits);
        SetMainCallback2(CB2_Credits);

        taskId = CreateTask(Task_ShowCreditsAndTrainers, 1);
        gTasks[taskId].tTimer = TIMER_CREDITS - 1;
        gTasks[taskId].tIndex = 0;
        gTasks[taskId].tSection = 0;
        gTasks[taskId].tIndexTrainer = 0;
        gTasks[taskId].tSpriteTimer = 0;
        gTasks[taskId].tNumCreditsSteps = GetTotalCreditsSteps();
        gTasks[taskId].tTrainerSpriteId1 = 0xFF;
        gTasks[taskId].tTrainerSpriteId2 = 0xFF;
        gTasks[taskId].tTrainerPicId1 = 0xFF;
        gTasks[taskId].tTrainerPicId2 = 0xFF;
        gTasks[taskId].tSpriteMode = CREDITS_SPRITE_MODE_TRAINER;
        gTasks[taskId].tIndexPokemon = 0;
        x = (trainnerWahList[gTasks[taskId].tIndexTrainer][1] != TRAINER_NONE) ? X_TRAINER_POS-20 : X_TRAINER_POS;
        if (trainnerWahList[gTasks[taskId].tIndexTrainer][0] != TRAINER_NONE)
            CreateCreditsTrainerSprite(trainnerWahList[gTasks[taskId].tIndexTrainer][0], x, 60,
                                       &gTasks[taskId].tTrainerSpriteId1, &gTasks[taskId].tTrainerPicId1);
        if (trainnerWahList[gTasks[taskId].tIndexTrainer][1] != TRAINER_NONE)
            CreateCreditsTrainerSprite(trainnerWahList[gTasks[taskId].tIndexTrainer][1], x + 30, 60,
                                       &gTasks[taskId].tTrainerSpriteId2, &gTasks[taskId].tTrainerPicId2);
        gTasks[taskId].tIndexTrainer++;
    }
}

bool8 StartCredits_CB2(void)
{
    if (!gPaletteFade.active)
    {
        gMain.state = 0;
        CleanupOverworldWindowsAndTilemaps();
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetMainCallback2(CB2_InitCreditsSetUp);

        return TRUE;
    }

    return FALSE;
}
