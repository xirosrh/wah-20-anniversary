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
#include "overworld.h"
#include "event_data.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"
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

static void LoadBgs(void)
{
    InitBgsFromTemplates(0, CreditsBgTemplates, ARRAY_COUNT(CreditsBgTemplates));

    LZ77UnCompVram(WahCredits_Tileset, (void*) BG_CHAR_ADDR(CreditsBgTemplates[BG_LOGO].charBaseIndex));
    LZ77UnCompVram(WahCredits_Tilemap, (u16*) BG_SCREEN_ADDR(CreditsBgTemplates[BG_LOGO].mapBaseIndex));

    LoadPalette(WahCredits_Palette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);

    ResetAllBgsCoordinates(); 

    ShowBg(BG_CREDITS);
    ShowBg(BG_LOGO);
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
#define TIMER_CREDITS 150

const u8 sTextColorWhiteCreditsWah[]= {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY};
const u8 sTextColor2CreditsWah[]= {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_RED, TEXT_COLOR_DARK_GRAY};

struct WahCredits
{
    const u8 *title;
    const u8 *sListCredits[30];
};

static const struct WahCredits sWahCreditsSections[] =
{
    {
        .title = COMPOUND_STRING("CREDITOS"),
        .sListCredits =
        {
            COMPOUND_STRING("Alex"),
            COMPOUND_STRING("Bruno"),
            COMPOUND_STRING("Carlos"),
            COMPOUND_STRING("Dante"),
            COMPOUND_STRING("Ethan"),
            COMPOUND_STRING("Fabio"),
            COMPOUND_STRING("Gael"),
            COMPOUND_STRING("Hector"),
            COMPOUND_STRING("Ivan"),
            COMPOUND_STRING("Javier"),
            COMPOUND_STRING("Kevin"),
            COMPOUND_STRING("Leo"),
            COMPOUND_STRING("Marco"),
            COMPOUND_STRING("Nico"),
            COMPOUND_STRING("Oscar"),
            COMPOUND_STRING("Pablo"),
            NULL
        }
    },
    {
        .title = COMPOUND_STRING("AGRADECIMIENTOS"),
        .sListCredits =
        {
            COMPOUND_STRING("XXX"),
            COMPOUND_STRING("Pret"),
            COMPOUND_STRING("WAH"),
            NULL
        }
    },
    {
        .title = COMPOUND_STRING("ESPECIALES"),
        .sListCredits =
        {
            COMPOUND_STRING("AAA"),
            COMPOUND_STRING("BBBB"),
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
    {TRAINER_PIC_OMEGA, TRAINER_PIC_XIROS},
    {TRAINER_PIC_CHEVE, TRAINER_PIC_EING},
    {TRAINER_PIC_REONEKY, TRAINER_PIC_KATHERINE},
    {TRAINER_PIC_DRIVE, TRAINER_PIC_ANGEL},
    {TRAINER_PIC_SCAREX, TRAINER_PIC_COSARARA},
    {TRAINER_PIC_ZERO, TRAINER_PIC_AGUIAR},
    {TRAINER_PIC_BARO, TRAINER_PIC_GOCE},
    {TRAINER_PIC_PKPOWER, TRAINER_PIC_KLEIN},
    {TRAINER_PIC_JACK_JOHNSON, TRAINER_PIC_SAYER},
    {TRAINER_PIC_BLAX, TRAINER_PIC_OZUMAS},
    {TRAINER_PIC_WAR, TRAINER_PIC_DRIVE},
    {TRAINER_PIC_GALLEGO, TRAINER_PIC_KATHERINE},
    {TRAINER_PIC_JAVS, TRAINER_PIC_BOO},
    {TRAINER_PIC_SERGIO, TRAINER_NONE}
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
#define tTrainerId1 data[2]
#define tTrainerId2 data[3]
#define tIndexTrainer data[4]
#define tNumCreditsSteps data[5]
#define tSpriteTimer data[6]
#define tTimer data[7]

static void Task_TrainnerSlice(u8 taskId);


static u8 DestroySpriteTrainners(u8 trainerId)
{
    //Destruir los sprites de los trainners
    if(trainerId != 0xFF) {
        DestroySpriteAndFreeResources(&gSprites[trainerId]);
        return 0xFF;
    }
    
    return trainerId;
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
                gTasks[taskId2].tTrainerId1 = DestroySpriteTrainners(gTasks[taskId2].tTrainerId1);
                gTasks[taskId2].tTrainerId2 = DestroySpriteTrainners(gTasks[taskId2].tTrainerId2);
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
    u8 i = 0;
    u8 x = 120;

    if (gTasks[taskId].tTimer++ % TIMER_TRAINER_SPRITE != 0)
        return;

    gTasks[taskId].tTrainerId1 = DestroySpriteTrainners(gTasks[taskId].tTrainerId1);
    gTasks[taskId].tTrainerId2 = DestroySpriteTrainners(gTasks[taskId].tTrainerId2);

    if(gTasks[taskId].tIndexTrainer >= ARRAY_COUNT(trainnerWahList) - 1)
        gTasks[taskId].tIndexTrainer = 0;

    //Crear los sprites
    if(trainnerWahList[gTasks[taskId].tIndexTrainer][1] != TRAINER_NONE)
        x = 100;

    gTasks[taskId].tTrainerId1 = CreateTrainerSprite(trainnerWahList[gTasks[taskId].tIndexTrainer][0], x, 60, 0, NULL);

    if(trainnerWahList[gTasks[taskId].tIndexTrainer][1] != TRAINER_NONE)
        gTasks[taskId].tTrainerId2 = CreateTrainerSprite(trainnerWahList[gTasks[taskId].tIndexTrainer][1], x+30, 60, 0, NULL);

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
    
    if (totalSprites == 0) return;

    spriteStepInterval =  (TIMER_CREDITS*gTasks[taskId].tNumCreditsSteps) / totalSprites;


    // Incrementar contador de sprites
    gTasks[taskId].tSpriteTimer++;

    if (gTasks[taskId].tSpriteTimer >= spriteStepInterval)
    {
        gTasks[taskId].tSpriteTimer = 0;

        // -----------------------------
        // Destruir sprites anteriores
        // -----------------------------
        gTasks[taskId].tTrainerId1 = DestroySpriteTrainners(gTasks[taskId].tTrainerId1);
        gTasks[taskId].tTrainerId2 = DestroySpriteTrainners(gTasks[taskId].tTrainerId2);

        // -----------------------------
        // Crear nuevos sprites
        // -----------------------------
        if (trainnerWahList[gTasks[taskId].tIndexTrainer][1] != TRAINER_NONE)
            x = 100;

        gTasks[taskId].tTrainerId1 = CreateTrainerSprite(trainnerWahList[gTasks[taskId].tIndexTrainer][0], x, 60, 0, NULL);
        if (trainnerWahList[gTasks[taskId].tIndexTrainer][1] != TRAINER_NONE)
            gTasks[taskId].tTrainerId2 = CreateTrainerSprite(trainnerWahList[gTasks[taskId].tIndexTrainer][1], x + 30, 60, 0, NULL);

        gTasks[taskId].tIndexTrainer++;
        if (gTasks[taskId].tIndexTrainer >= totalSprites)
            gTasks[taskId].tIndexTrainer = totalSprites - 1; // mantener el último sprite
    }

    // -----------------------------
    // Comprobar fin de créditos
    // -----------------------------
    if (gTasks[taskId].tSection >= ARRAY_COUNT(sWahCreditsSections))
        gTasks[taskId].func = Task_EndCredits;
}


static void Task_EndCredits(u8 taskId)
{
    // Limpiar ventana
    FillWindowPixelBuffer(WINDOW_CREDITS, PIXEL_FILL(0));
    CopyWindowToVram(WINDOW_CREDITS, COPYWIN_FULL);

    // Destruir sprites finales
    gTasks[taskId].tTrainerId1 = DestroySpriteTrainners(gTasks[taskId].tTrainerId1);
    gTasks[taskId].tTrainerId2 = DestroySpriteTrainners(gTasks[taskId].tTrainerId2);

    // Destruir task
    DestroyTask(taskId);
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
        ResetPaletteFade();
        DmaClearLarge16(3, (void *) VRAM, VRAM_SIZE, 4096);
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
        FadeOutAndPlayNewMapMusic(MUS_CREDITS, 4); 
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
        x = (trainnerWahList[gTasks[taskId].tIndexTrainer][1] != TRAINER_NONE) ? X_TRAINER_POS-20 : X_TRAINER_POS;
        gTasks[taskId].tTrainerId1 =  (trainnerWahList[gTasks[taskId].tIndexTrainer][0] != TRAINER_NONE) ? CreateTrainerSprite(trainnerWahList[gTasks[taskId].tIndexTrainer][0], x, 60, 0, NULL) : 0xFF;
        gTasks[taskId].tTrainerId2 = (trainnerWahList[gTasks[taskId].tIndexTrainer][1] != TRAINER_NONE) ? CreateTrainerSprite(trainnerWahList[gTasks[taskId].tIndexTrainer][1], x + 30, 60, 0, NULL) : 0xFF;
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