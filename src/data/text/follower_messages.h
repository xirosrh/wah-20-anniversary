extern const u8 EventScript_FollowerIsShivering[];
extern const u8 EventScript_FollowerNostalgia[];
extern const u8 EventScript_FollowerHopping[];
extern const u8 EventScript_FollowerJumpOnPlayer[];
extern const u8 EventScript_FollowerCuddling[];
extern const u8 EventScript_FollowerShiverCuddling[];
extern const u8 EventScript_FollowerGetCloser[];
extern const u8 EventScript_FollowerPokingPlayer[];
extern const u8 EventScript_FollowerLookAround[];
extern const u8 EventScript_FollowerLookAway[];
extern const u8 EventScript_FollowerLookAwayBark[];
extern const u8 EventScript_FollowerLookAwayPoke[];
extern const u8 EventScript_FollowerPokeGround[];
extern const u8 EventScript_FollowerStartled[];
extern const u8 EventScript_FollowerFastHopping[];
extern const u8 EventScript_FollowerDizzy[];
extern const u8 EventScript_FollowerLookAroundScared[];
extern const u8 EventScript_FollowerDance[];
extern const u8 EventScript_FollowerLookUp[];

// 'Generic', unconditional happy messages
static const u8 sHappyMsg00[] = _("{STR_VAR_1} is tickling\nyour belly!");
static const u8 sHappyMsg01[] = _("{STR_VAR_1} is happy, but hiding.");
static const u8 sHappyMsg02[] = _("{STR_VAR_1} is doing great.");
static const u8 sHappyMsg03[] = _("{STR_VAR_1} moves so serenely.");
static const u8 sHappyMsg04[] = _("You can tell {STR_VAR_1} loves\nwalking with you!");
static const u8 sHappyMsg05[] = _("{STR_VAR_1} is beaming.");
static const u8 sHappyMsg06[] = _("{STR_VAR_1} seems very happy.");
static const u8 sHappyMsg07[] = _("{STR_VAR_1} is trying hard.");
static const u8 sHappyMsg08[] = _("{STR_VAR_1} is sniffing\nthe surroundings.");
static const u8 sHappyMsg09[] = _("{STR_VAR_1} is jumping for joy!");
static const u8 sHappyMsg10[] = _("{STR_VAR_1} is still very cheerful!");
static const u8 sHappyMsg11[] = _("{STR_VAR_1} caught a\nspecial scent.");
static const u8 sHappyMsg12[] = _("{STR_VAR_1} nudges at \nyour shirt.");
static const u8 sHappyMsg13[] = _("Your {STR_VAR_1} is\nstretching and relaxing.");
static const u8 sHappyMsg14[] = _("{STR_VAR_1} likes to lead!");
static const u8 sHappyMsg15[] = _("{STR_VAR_1} is giving it\nall to stay with you.");
static const u8 sHappyMsg16[] = _("{STR_VAR_1} is happily\nsnuggling with you!");
static const u8 sHappyMsg17[] = _("{STR_VAR_1} is all energy!");
static const u8 sHappyMsg18[] = _("{STR_VAR_1} is very happy!");
static const u8 sHappyMsg19[] = _("{STR_VAR_1} is so happy\nit's prancing!");
static const u8 sHappyMsg20[] = _("{STR_VAR_1} nodded slowly.");
static const u8 sHappyMsg21[] = _("{STR_VAR_1} is very eager!");
static const u8 sHappyMsg22[] = _("{STR_VAR_1} is wandering and\nlistening to the sounds.");
static const u8 sHappyMsg23[] = _("{STR_VAR_1} seems interested\nin something.");
static const u8 sHappyMsg24[] = _("{STR_VAR_1} is striving\nto keep going.");
static const u8 sHappyMsg25[] = _("{STR_VAR_1} looks at you, beaming!");
static const u8 sHappyMsg26[] = _("{STR_VAR_1} looks at you happily\nand seems to smile.");
static const u8 sHappyMsg27[] = _("{STR_VAR_1} enjoys the scent\nof the flowers.");
static const u8 sHappyMsg28[] = _("{STR_VAR_1} loves having\nyou by its side!");
static const u8 sHappyMsg29[] = _("{STR_VAR_1} looked at you\nand smiled.");
static const u8 sHappyMsg30[] = _("{STR_VAR_1} snuggles up to you…");
// Conditional messages begin here, index 31
static const u8 sHappyMsg31[] = _("Your {STR_VAR_1} seems to enjoy\nthe nice weather.");
static const u8 sHappyMsg32[] = _("{STR_VAR_1} trusts you!");

const struct FollowerMsgInfo gFollowerHappyMessages[] = {
    {sHappyMsg00, EventScript_FollowerPokingPlayer},
    {sHappyMsg01}, {sHappyMsg02}, {sHappyMsg03}, {sHappyMsg04}, {sHappyMsg05}, {sHappyMsg06}, {sHappyMsg07},
    {sHappyMsg08, EventScript_FollowerLookAround},
    {sHappyMsg09, EventScript_FollowerHopping},
    {sHappyMsg10}, {sHappyMsg11},
    {sHappyMsg12, EventScript_FollowerPokingPlayer},
    {sHappyMsg13, EventScript_FollowerLookAround},
    {sHappyMsg14}, {sHappyMsg15},
    {sHappyMsg16, EventScript_FollowerCuddling},
    {sHappyMsg17}, {sHappyMsg18},
    {sHappyMsg19, EventScript_FollowerFastHopping},
    {sHappyMsg20}, {sHappyMsg21}, {sHappyMsg22}, {sHappyMsg23}, {sHappyMsg24}, {sHappyMsg25}, {sHappyMsg26}, {sHappyMsg27}, {sHappyMsg28}, {sHappyMsg29},
    {sHappyMsg30, EventScript_FollowerCuddling},
    {sHappyMsg31}, {sHappyMsg32},
};

// Unconditional neutral messages
static const u8 sNeutralMsg00[] = _("{STR_VAR_1} keeps pecking\nat the ground.");
static const u8 sNeutralMsg01[] = _("{STR_VAR_1} is on guard.");
static const u8 sNeutralMsg02[] = _("{STR_VAR_1} is staring at\nnothing.");
static const u8 sNeutralMsg03[] = _("{STR_VAR_1} is wandering.");
static const u8 sNeutralMsg04[] = _("{STR_VAR_1} yawns\nvery loudly!");
static const u8 sNeutralMsg05[] = _("{STR_VAR_1} looks all\naround restlessly.");
static const u8 sNeutralMsg06[] = _("{STR_VAR_1} is looking at you,\nsmiling.");
static const u8 sNeutralMsg07[] = _("{STR_VAR_1} is looking around\nuneasily.");
static const u8 sNeutralMsg08[] = _("{STR_VAR_1} let out a battle cry.");
static const u8 sNeutralMsg09[] = _("{STR_VAR_1} danced a\nwonderful dance!");
static const u8 sNeutralMsg10[] = _("{STR_VAR_1} is very restless.");
static const u8 sNeutralMsg11[] = _("{STR_VAR_1} is staring\ninto the distance.");
static const u8 sNeutralMsg12[] = _("{STR_VAR_1} is alert!");
static const u8 sNeutralMsg13[] = _("{STR_VAR_1} looked afar and barked!");

const struct FollowerMsgInfo gFollowerNeutralMessages[] = {
    {sNeutralMsg00, EventScript_FollowerPokeGround},
    {sNeutralMsg01},
    {sNeutralMsg02, EventScript_FollowerLookAway},
    {sNeutralMsg03, EventScript_FollowerLookAround},
    {sNeutralMsg04},
    {sNeutralMsg05, EventScript_FollowerLookAround},
    {sNeutralMsg06}, {sNeutralMsg07}, {sNeutralMsg08},
    {sNeutralMsg09, EventScript_FollowerDance},
    {sNeutralMsg10},
    {sNeutralMsg11, EventScript_FollowerLookAway},
    {sNeutralMsg12},
    {sNeutralMsg13, EventScript_FollowerLookAwayBark},
};

// Unconditional sad messages
static const u8 sSadMsg00[] = _("{STR_VAR_1} got dizzy.");
static const u8 sSadMsg01[] = _("{STR_VAR_1} is stepping on\nyour feet!");
static const u8 sSadMsg02[] = _("{STR_VAR_1} seems to be tiring.");
// Mensajes condicionales comienzan, índice 3
static const u8 sSadMsg03[] = _("{STR_VAR_1} isn't happy.");
static const u8 sSadMsg04[] = _("{STR_VAR_1} is stumbling around!\n");
static const u8 sSadMsg05[] = _("It looks like {STR_VAR_1}\nis about to fall over!");
static const u8 sSadMsg06[] = _("{STR_VAR_1} tries hard\n to keep up with you…");
static const u8 sSadMsg07[] = _("{STR_VAR_1} seems like a\nbundle of nerves.");

const struct FollowerMsgInfo gFollowerSadMessages[] = {
    {sSadMsg00, EventScript_FollowerDizzy},
    {sSadMsg01}, {sSadMsg02},
    {sSadMsg03}, {sSadMsg04}, {sSadMsg05}, {sSadMsg06}, {sSadMsg07},
};

// Mensajes de molestia incondicionales
static const u8 sUpsetMsg00[] = _("{STR_VAR_1} seems sad…");
static const u8 sUpsetMsg01[] = _("{STR_VAR_1} is pouting…");
static const u8 sUpsetMsg02[] = _("{STR_VAR_1} is freezing…");
// Mensajes condicionales, índice 3
static const u8 sUpsetMsg03[] = _("{STR_VAR_1} shelters from the rain\nwith the grass.");

const struct FollowerMsgInfo gFollowerUpsetMessages[] = {
    {sUpsetMsg00}, {sUpsetMsg01},
    {sUpsetMsg02, EventScript_FollowerIsShivering},
    {sUpsetMsg03},
};

// Unconditional angry messages
static const u8 sAngryMsg00[] = _("{STR_VAR_1} is roaring!");
static const u8 sAngryMsg01[] = _("{STR_VAR_1} is making\nan angry face!");
static const u8 sAngryMsg02[] = _("Something seems to be\nmaking {STR_VAR_1} angry.");
static const u8 sAngryMsg03[] = _("{STR_VAR_1} turns its face away,\ndefiant.");
static const u8 sAngryMsg04[] = _("{STR_VAR_1} is whimpering");

const struct FollowerMsgInfo gFollowerAngryMessages[] = {
    {sAngryMsg00}, {sAngryMsg01}, {sAngryMsg02},
    {sAngryMsg03, EventScript_FollowerLookAway},
    {sAngryMsg04},
};

// Unconditional pensive messages
static const u8 sPensiveMsg00[] = _("{STR_VAR_1} watches the ground\nintently.");
static const u8 sPensiveMsg01[] = _("{STR_VAR_1} is surveying the area.");
static const u8 sPensiveMsg02[] = _("{STR_VAR_1} is looking down.");
static const u8 sPensiveMsg03[] = _("{STR_VAR_1} is somehow\nfighting off sleep…");
static const u8 sPensiveMsg04[] = _("{STR_VAR_1} seems to be wandering.");
static const u8 sPensiveMsg05[] = _("{STR_VAR_1} looks around,\npaying no mind.");
static const u8 sPensiveMsg06[] = _("{STR_VAR_1} yawned very loudly!");
static const u8 sPensiveMsg07[] = _("{STR_VAR_1} is relaxed.");
static const u8 sPensiveMsg08[] = _("{STR_VAR_1} stares right\nat your face.");
static const u8 sPensiveMsg09[] = _("{STR_VAR_1} looks intently\nat your face.");
static const u8 sPensiveMsg10[] = _("{STR_VAR_1} is focusing its\nattention on you.");
static const u8 sPensiveMsg11[] = _("{STR_VAR_1} is staring into\nthe void.");
static const u8 sPensiveMsg12[] = _("{STR_VAR_1} is sniffing the\nground.");
static const u8 sPensiveMsg13[] = _("Your POKéMON is gazing\nwith a lost look.");
static const u8 sPensiveMsg14[] = _("{STR_VAR_1} has a piercing\ngaze!");
static const u8 sPensiveMsg15[] = _("{STR_VAR_1} is focused.");
static const u8 sPensiveMsg16[] = _("{STR_VAR_1} looked over here\nand nodded.");
static const u8 sPensiveMsg17[] = _("{STR_VAR_1} seems nervous…");
static const u8 sPensiveMsg18[] = _("{STR_VAR_1} is watching your steps.");
static const u8 sPensiveMsg19[] = _("{STR_VAR_1} is staring at you.");
const struct FollowerMsgInfo gFollowerPensiveMessages[] = {
    {sPensiveMsg00},
    {sPensiveMsg01, EventScript_FollowerLookAround},
    {sPensiveMsg02}, {sPensiveMsg03}, {sPensiveMsg04},
    {sPensiveMsg05, EventScript_FollowerLookAround},
    {sPensiveMsg06}, {sPensiveMsg07}, {sPensiveMsg08}, {sPensiveMsg09}, {sPensiveMsg10},
    {sPensiveMsg11, EventScript_FollowerLookAway},
    {sPensiveMsg12, EventScript_FollowerPokeGround},
    {sPensiveMsg13, EventScript_FollowerLookAway},
    {sPensiveMsg14}, {sPensiveMsg15}, {sPensiveMsg16}, {sPensiveMsg17}, {sPensiveMsg18}, {sPensiveMsg19},
};

// All 'love' messages are unconditional
static const u8 sLoveMsg00[] = _("{STR_VAR_1} started to come closer!");
static const u8 sLoveMsg01[] = _("{STR_VAR_1}'s cheeks\nare rosy!");
static const u8 sLoveMsg02[] = _("Wow! {STR_VAR_1} hugged you!");
static const u8 sLoveMsg03[] = _("Wow! {STR_VAR_1} is playful!");
static const u8 sLoveMsg04[] = _("{STR_VAR_1} is rubbing against\nyour legs!");
static const u8 sLoveMsg05[] = _("{STR_VAR_1} blushes.");
static const u8 sLoveMsg06[] = _("Aww! {STR_VAR_1} hugs you!");
static const u8 sLoveMsg07[] = _("{STR_VAR_1} looks at you with\nadoration!");
static const u8 sLoveMsg08[] = _("{STR_VAR_1} moved closer to you.");
static const u8 sLoveMsg09[] = _("{STR_VAR_1} is close to\nyour feet.");

const struct FollowerMsgInfo gFollowerLoveMessages[] = {
    {sLoveMsg00, EventScript_FollowerGetCloser},
    {sLoveMsg01},
    {sLoveMsg02, EventScript_FollowerCuddling},
    {sLoveMsg03},
    {sLoveMsg04, EventScript_FollowerCuddling},
    {sLoveMsg05},
    {sLoveMsg06, EventScript_FollowerCuddling},
    {sLoveMsg07},
    {sLoveMsg08, EventScript_FollowerGetCloser},
    {sLoveMsg09},
};

// Unconditional surprised messages
static const u8 sSurpriseMsg00[] = _("{STR_VAR_1} is in danger of\nfalling!");
static const u8 sSurpriseMsg01[] = _("{STR_VAR_1} bumped into you!");
static const u8 sSurpriseMsg02[] = _("{STR_VAR_1} isn't used to\nits name.");
static const u8 sSurpriseMsg03[] = _("{STR_VAR_1} is looking down.");
static const u8 sSurpriseMsg04[] = _("Your POKéMON tripped and\nalmost fell!");
static const u8 sSurpriseMsg05[] = _("{STR_VAR_1} sensed something\nand howls!");
static const u8 sSurpriseMsg06[] = _("{STR_VAR_1} seems revitalized!");
static const u8 sSurpriseMsg07[] = _("{STR_VAR_1} suddenly turned around\nand started barking!");
static const u8 sSurpriseMsg08[] = _("{STR_VAR_1} suddenly turned around!");
static const u8 sSurpriseMsg09[] = _("Your POKéMON was startled you\nspoke to it so suddenly!");
static const u8 sSurpriseMsg10[] = _("Sniff sniff, something smells\nreally good!");
static const u8 sSurpriseMsg11[] = _("{STR_VAR_1} has renewed\nenergy!");
static const u8 sSurpriseMsg12[] = _("{STR_VAR_1} is wobbling and\nseems about to fall.");
static const u8 sSurpriseMsg13[] = _("{STR_VAR_1} is in danger of\nfalling.");
static const u8 sSurpriseMsg14[] = _("{STR_VAR_1} is walking\ncautiously.");
static const u8 sSurpriseMsg15[] = _("{STR_VAR_1} is tensing up\nfrom nervous energy.");
static const u8 sSurpriseMsg16[] = _("{STR_VAR_1} felt something strange\nand was startled!");
static const u8 sSurpriseMsg17[] = _("{STR_VAR_1} is scared and\nsnuggled up to you!");
static const u8 sSurpriseMsg18[] = _("{STR_VAR_1} is sensing an\nunusual presence…");
static const u8 sSurpriseMsg19[] = _("{STR_VAR_1} is tensing up\nfrom nervous energy.");
// Conditional messages, index 20
static const u8 sSurpriseMsg20[] = _("{STR_VAR_1} seems surprised\nby the rain!");

const struct FollowerMsgInfo gFollowerSurpriseMessages[] = {
    {sSurpriseMsg00},
    {sSurpriseMsg01, EventScript_FollowerPokingPlayer},
    {sSurpriseMsg02}, {sSurpriseMsg03}, {sSurpriseMsg04}, {sSurpriseMsg05}, {sSurpriseMsg06},
    {sSurpriseMsg07, EventScript_FollowerLookAwayBark},
    {sSurpriseMsg08, EventScript_FollowerLookAway},
    {sSurpriseMsg09},
    {sSurpriseMsg10, EventScript_FollowerLookAround},
    {sSurpriseMsg11}, {sSurpriseMsg12}, {sSurpriseMsg13}, {sSurpriseMsg14}, {sSurpriseMsg15}, {sSurpriseMsg16},
    {sSurpriseMsg17, EventScript_FollowerCuddling},
    {sSurpriseMsg18},
    {sSurpriseMsg19, EventScript_FollowerLookAround},
    {sSurpriseMsg20},
};

// Unconditional curious messages
static const u8 sCuriousMsg00[] = _("It looks like {STR_VAR_1} is\ndesperately looking for something!");
static const u8 sCuriousMsg01[] = _("Your POKéMON wasn't watching\nwhere it went and bumped you!");
static const u8 sCuriousMsg02[] = _("{STR_VAR_1} keeps sniffing.\nIs something nearby?");
static const u8 sCuriousMsg03[] = _("{STR_VAR_1} is playfully rolling\na little pebble.");
static const u8 sCuriousMsg04[] = _("{STR_VAR_1} looks around\nfor something…");
static const u8 sCuriousMsg05[] = _("{STR_VAR_1} is sniffing you.");
static const u8 sCuriousMsg06[] = _("{STR_VAR_1} seems a little\nunsure…");

const struct FollowerMsgInfo gFollowerCuriousMessages[] = {
    {sCuriousMsg00, EventScript_FollowerLookAround},
    {sCuriousMsg01, EventScript_FollowerPokingPlayer},
    {sCuriousMsg02}, {sCuriousMsg03},
    {sCuriousMsg04, EventScript_FollowerLookAround},
    {sCuriousMsg05}, {sCuriousMsg06},
};

// Unconditional music messages
static const u8 sMusicMsg00[] = _("{STR_VAR_1} is showing off\nits agility!");
static const u8 sMusicMsg01[] = _("{STR_VAR_1} is moving about\ncheerfully!");
static const u8 sMusicMsg02[] = _("Wow! {STR_VAR_1} suddenly started\ndancing with joy!");
static const u8 sMusicMsg03[] = _("{STR_VAR_1} is keeping pace!");
static const u8 sMusicMsg04[] = _("{STR_VAR_1} seems to want to\nplay with you.");
static const u8 sMusicMsg05[] = _("{STR_VAR_1} is jumping for joy.");
static const u8 sMusicMsg06[] = _("{STR_VAR_1} is singing and humming.");
static const u8 sMusicMsg07[] = _("{STR_VAR_1} is nibbling at\nyour feet!");
static const u8 sMusicMsg08[] = _("{STR_VAR_1} turns around\nand looks at you.");
static const u8 sMusicMsg09[] = _("{STR_VAR_1} strains to show\nits great power!");
static const u8 sMusicMsg10[] = _("Wow! {STR_VAR_1} suddenly danced\nwith joy!");
static const u8 sMusicMsg11[] = _("{STR_VAR_1} is cheerful!");
static const u8 sMusicMsg12[] = _("{STR_VAR_1} is hopping about\ncarefree!");
static const u8 sMusicMsg13[] = _("A familiar scent seems\nto reach {STR_VAR_1}…");
// Conditional music messages, index 14
static const u8 sMusicMsg14[] = _("{STR_VAR_1} loves the rain.");

const struct FollowerMsgInfo gFollowerMusicMessages[] = {
    {sMusicMsg00, EventScript_FollowerLookAround},
    {sMusicMsg01},
    {sMusicMsg02, EventScript_FollowerDance},
    {sMusicMsg03},
    {sMusicMsg04, EventScript_FollowerHopping},
    {sMusicMsg05, EventScript_FollowerHopping},
    {sMusicMsg06}, {sMusicMsg07}, {sMusicMsg08}, {sMusicMsg09},
    {sMusicMsg10, EventScript_FollowerDance},
    {sMusicMsg11},
    {sMusicMsg12, EventScript_FollowerHopping},
    {sMusicMsg13, EventScript_FollowerNostalgia},
    {sMusicMsg14}
};


static const u8 sPoisonedMsg00[] = _("{STR_VAR_1} is trembling from\nthe poison.");

const struct FollowerMsgInfo gFollowerPoisonedMessages[] = {
    {sPoisonedMsg00, EventScript_FollowerIsShivering},
};
