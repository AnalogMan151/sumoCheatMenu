#define arrSz(a) (sizeof(a)/sizeof(*a))
typedef enum LOOKUP_SIZE {
    ITEM_COUNT = 921,
    ABILITY_COUNT = 233,
    NATURE_COUNT = 25,
    MOVE_COUNT = 720
} LOOKUP_SIZE;

static const char *ITEM_LOOKUP[] = {
    "[No Item]", "Master Ball", "Ultra Ball", "Great Ball", "Poké Ball",
    "Safari Ball", "Net Ball", "Dive Ball", "Nest Ball", "Repeat Ball",
    "Timer Ball", "Luxury Ball", "Premier Ball", "Dusk Ball", "Heal Ball",
    "Quick Ball", "Cherish Ball", "Potion", "Antidote", "Burn Heal", "Ice Heal",
    "Awakening", "Paralyze Heal", "Full Restore", "Max Potion", "Hyper Potion",
    "Super Potion", "Full Heal", "Revive", "Max Revive", "Fresh Water",
    "Soda Pop", "Lemonade", "Moomoo Milk", "Energy Powder", "Energy Root",
    "Heal Powder", "Revival Herb", "Ether", "Max Ether", "Elixir", "Max Elixir",
    "Lava Cookie", "Berry Juice", "Sacred Ash", "HP Up", "Protein", "Iron",
    "Carbos", "Calcium", "Rare Candy", "PP Up", "Zinc", "PP Max", "Old Gateau",
    "Guard Spec.", "Dire Hit", "X Attack", "X Defense", "X Speed", "X Accuracy",
    "X Sp. Atk", "X Sp. Def", "Poké Doll", "Fluffy Tail", "Blue Flute",
    "Yellow Flute", "Red Flute", "Black Flute", "White Flute", "Shoal Salt",
    "Shoal Shell", "Red Shard", "Blue Shard", "Yellow Shard", "Green Shard",
    "Super Repel", "Max Repel", "Escape Rope", "Repel", "Sun Stone",
    "Moon Stone", "Fire Stone", "Thunder Stone", "Water Stone", "Leaf Stone",
    "Tiny Mushroom", "Big Mushroom", "Pearl", "Big Pearl", "Stardust",
    "Star Piece", "Nugget", "Heart Scale", "Honey", "Growth Mulch",
    "Damp Mulch", "Stable Mulch", "Gooey Mulch", "Root Fossil", "Claw Fossil",
    "Helix Fossil", "Dome Fossil", "Old Amber", "Armor Fossil", "Skull Fossil",
    "Rare Bone", "Shiny Stone", "Dusk Stone", "Dawn Stone", "Oval Stone",
    "Odd Keystone", "Griseous Orb", "???", "???", "???", "Douse Drive",
    "Shock Drive", "Burn Drive", "Chill Drive", "???", "???", "???", "???",
    "???", "???", "???", "???", "???", "???", "???", "???", "???", "???",
    "Sweet Heart", "Adamant Orb", "Lustrous Orb", "Greet Mail", "Favored Mail",
    "RSVP Mail", "Thanks Mail", "Inquiry Mail", "Like Mail", "Reply Mail",
    "Bridge Mail S", "Bridge Mail D", "Bridge Mail T", "Bridge Mail V",
    "Bridge Mail M", "Cheri Berry", "Chesto Berry", "Pecha Berry",
    "Rawst Berry", "Aspear Berry", "Leppa Berry", "Oran Berry", "Persim Berry",
    "Lum Berry", "Sitrus Berry", "Figy Berry", "Wiki Berry", "Mago Berry",
    "Aguav Berry", "Iapapa Berry", "Razz Berry", "Bluk Berry", "Nanab Berry",
    "Wepear Berry", "Pinap Berry", "Pomeg Berry", "Kelpsy Berry",
    "Qualot Berry", "Hondew Berry", "Grepa Berry", "Tamato Berry",
    "Cornn Berry", "Magost Berry", "Rabuta Berry", "Nomel Berry",
    "Spelon Berry", "Pamtre Berry", "Watmel Berry", "Durin Berry",
    "Belue Berry", "Occa Berry", "Passho Berry", "Wacan Berry", "Rindo Berry",
    "Yache Berry", "Chople Berry", "Kebia Berry", "Shuca Berry", "Coba Berry",
    "Payapa Berry", "Tanga Berry", "Charti Berry", "Kasib Berry", "Haban Berry",
    "Colbur Berry", "Babiri Berry", "Chilan Berry", "Liechi Berry",
    "Ganlon Berry", "Salac Berry", "Petaya Berry", "Apicot Berry",
    "Lansat Berry", "Starf Berry", "Enigma Berry", "Micle Berry",
    "Custap Berry", "Jaboca Berry", "Rowap Berry", "Bright Powder",
    "White Herb", "Macho Brace", "Exp. Share", "Quick Claw", "Soothe Bell",
    "Mental Herb", "Choice Band", "King's Rock", "Silver Powder", "Amulet Coin",
    "Cleanse Tag", "Soul Dew", "Deep Sea Tooth", "Deep Sea Scale", "Smoke Ball",
    "Everstone", "Focus Band", "Lucky Egg", "Scope Lens", "Metal Coat",
    "Leftovers", "Dragon Scale", "Light Ball", "Soft Sand", "Hard Stone",
    "Miracle Seed", "Black Glasses", "Black Belt", "Magnet", "Mystic Water",
    "Sharp Beak", "Poison Barb", "Never-Melt Ice", "Spell Tag", "Twisted Spoon",
    "Charcoal", "Dragon Fang", "Silk Scarf", "Up-Grade", "Shell Bell",
    "Sea Incense", "Lax Incense", "Lucky Punch", "Metal Powder", "Thick Club",
    "Stick", "Red Scarf", "Blue Scarf", "Pink Scarf", "Green Scarf",
    "Yellow Scarf", "Wide Lens", "Muscle Band", "Wise Glasses", "Expert Belt",
    "Light Clay", "Life Orb", "Power Herb", "Toxic Orb", "Flame Orb",
    "Quick Powder", "Focus Sash", "Zoom Lens", "Metronome", "Iron Ball",
    "Lagging Tail", "Destiny Knot", "Black Sludge", "Icy Rock", "Smooth Rock",
    "Heat Rock", "Damp Rock", "Grip Claw", "Choice Scarf", "Sticky Barb",
    "Power Bracer", "Power Belt", "Power Lens", "Power Band", "Power Anklet",
    "Power Weight", "Shed Shell", "Big Root", "Choice Specs", "Flame Plate",
    "Splash Plate", "Zap Plate", "Meadow Plate", "Icicle Plate", "Fist Plate",
    "Toxic Plate", "Earth Plate", "Sky Plate", "Mind Plate", "Insect Plate",
    "Stone Plate", "Spooky Plate", "Draco Plate", "Dread Plate", "Iron Plate",
    "Odd Incense", "Rock Incense", "Full Incense", "Wave Incense",
    "Rose Incense", "Luck Incense", "Pure Incense", "Protector", "Electirizer",
    "Magmarizer", "Dubious Disc", "Reaper Cloth", "Razor Claw", "Razor Fang",
    "TM01", "TM02", "TM03", "TM04", "TM05", "TM06", "TM07", "TM08", "TM09",
    "TM10", "TM11", "TM12", "TM13", "TM14", "TM15", "TM16", "TM17", "TM18",
    "TM19", "TM20", "TM21", "TM22", "TM23", "TM24", "TM25", "TM26", "TM27",
    "TM28", "TM29", "TM30", "TM31", "TM32", "TM33", "TM34", "TM35", "TM36",
    "TM37", "TM38", "TM39", "TM40", "TM41", "TM42", "TM43", "TM44", "TM45",
    "TM46", "TM47", "TM48", "TM49", "TM50", "TM51", "TM52", "TM53", "TM54",
    "TM55", "TM56", "TM57", "TM58", "TM59", "TM60", "TM61", "TM62", "TM63",
    "TM64", "TM65", "TM66", "TM67", "TM68", "TM69", "TM70", "TM71", "TM72",
    "TM73", "TM74", "TM75", "TM76", "TM77", "TM78", "TM79", "TM80", "TM81",
    "TM82", "TM83", "TM84", "TM85", "TM86", "TM87", "TM88", "TM89", "TM90",
    "TM91", "TM92", "HM01", "HM02", "HM03", "HM04", "HM05", "HM06", "???",
    "???", "Explorer Kit", "Loot Sack", "Rule Book", "Poké Radar", "Point Card",
    "Journal", "Seal Case", "Fashion Case", "Seal Bag", "Pal Pad", "Works Key",
    "Old Charm", "Galactic Key", "Red Chain", "Town Map", "Vs. Seeker",
    "Coin Case", "Old Rod", "Good Rod", "Super Rod", "Sprayduck", "Poffin Case",
    "Bike", "Suite Key", "Oak's Letter", "Lunar Wing", "Member Card",
    "Azure Flute", "S.S. Ticket", "Contest Pass", "Magma Stone", "Parcel",
    "Coupon 1", "Coupon 2", "Coupon 3", "Storage Key", "Secret Potion",
    "Vs. Recorder", "Gracidea", "Secret Key", "Apricorn Box", "Unown Report",
    "Berry Pots", "Dowsing Machine", "Blue Card", "Slowpoke Tail", "Clear Bell",
    "Card Key", "Basement Key", "Squirt Bottle", "Red Scale", "Lost Item",
    "Pass", "Machine Part", "Silver Wing", "Rainbow Wing", "Mystery Egg",
    "Red Apricorn", "Blue Apricorn", "Yellow Apricorn", "Green Apricorn",
    "Pink Apricorn", "White Apricorn", "Black Apricorn", "Fast Ball",
    "Level Ball", "Lure Ball", "Heavy Ball", "Love Ball", "Friend Ball",
    "Moon Ball", "Sport Ball", "Park Ball", "Photo Album", "GB Sounds",
    "Tidal Bell", "Rage Candy Bar", "Data Card 01", "Data Card 02",
    "Data Card 03", "Data Card 04", "Data Card 05", "Data Card 06",
    "Data Card 07", "Data Card 08", "Data Card 09", "Data Card 10",
    "Data Card 11", "Data Card 12", "Data Card 13", "Data Card 14",
    "Data Card 15", "Data Card 16", "Data Card 17", "Data Card 18",
    "Data Card 19", "Data Card 20", "Data Card 21", "Data Card 22",
    "Data Card 23", "Data Card 24", "Data Card 25", "Data Card 26",
    "Data Card 27", "Jade Orb", "Lock Capsule", "Red Orb", "Blue Orb",
    "Enigma Stone", "Prism Scale", "Eviolite", "Float Stone", "Rocky Helmet",
    "Air Balloon", "Red Card", "Ring Target", "Binding Band", "Absorb Bulb",
    "Cell Battery", "Eject Button", "Fire Gem", "Water Gem", "Electric Gem",
    "Grass Gem", "Ice Gem", "Fighting Gem", "Poison Gem", "Ground Gem",
    "Flying Gem", "Psychic Gem", "Bug Gem", "Rock Gem", "Ghost Gem",
    "Dragon Gem", "Dark Gem", "Steel Gem", "Normal Gem", "Health Wing",
    "Muscle Wing", "Resist Wing", "Genius Wing", "Clever Wing", "Swift Wing",
    "Pretty Wing", "Cover Fossil", "Plume Fossil", "Liberty Pass", "Pass Orb",
    "Dream Ball", "Poké Toy", "Prop Case", "Dragon Skull", "Balm Mushroom",
    "Big Nugget", "Pearl String", "Comet Shard", "Relic Copper", "Relic Silver",
    "Relic Gold", "Relic Vase", "Relic Band", "Relic Statue", "Relic Crown",
    "Casteliacone", "Dire Hit 2", "X Speed 2", "X Sp. Atk 2", "X Sp. Def 2",
    "X Defense 2", "X Attack 2", "X Accuracy 2", "X Speed 3", "X Sp. Atk 3",
    "X Sp. Def 3", "X Defense 3", "X Attack 3", "X Accuracy 3", "X Speed 6",
    "X Sp. Atk 6", "X Sp. Def 6", "X Defense 6", "X Attack 6", "X Accuracy 6",
    "Ability Urge", "Item Drop", "Item Urge", "Reset Urge", "Dire Hit 3",
    "Light Stone", "Dark Stone", "TM93", "TM94", "TM95", "Xtransceiver", "???",
    "Gram 1", "Gram 2", "Gram 3", "Xtransceiver", "Medal Box", "DNA Splicers",
    "DNA Splicers", "Permit", "Oval Charm", "Shiny Charm", "Plasma Card",
    "Grubby Hanky", "Colress Machine", "Dropped Item", "Dropped Item",
    "Reveal Glass", "Weakness Policy", "Assault Vest", "Holo Caster",
    "Prof's Letter", "Roller Skates", "Pixie Plate", "Ability Capsule",
    "Whipped Dream", "Sachet", "Luminous Moss", "Snowball", "Safety Goggles",
    "Poké Flute", "Rich Mulch", "Surprise Mulch", "Boost Mulch", "Amaze Mulch",
    "Gengarite", "Gardevoirite", "Ampharosite", "Venusaurite", "Charizardite X",
    "Blastoisinite", "Mewtwonite X", "Mewtwonite Y", "Blazikenite",
    "Medichamite", "Houndoominite", "Aggronite", "Banettite", "Tyranitarite",
    "Scizorite", "Pinsirite", "Aerodactylite", "Lucarionite", "Abomasite",
    "Kangaskhanite", "Gyaradosite", "Absolite", "Charizardite Y", "Alakazite",
    "Heracronite", "Mawilite", "Manectite", "Garchompite", "Latiasite",
    "Latiosite", "Roseli Berry", "Kee Berry", "Maranga Berry", "Sprinklotad",
    "TM96", "TM97", "TM98", "TM99", "TM100", "Power Plant Pass", "Mega Ring",
    "Intriguing Stone", "Common Stone", "Discount Coupon", "Elevator Key",
    "TMV Pass", "Honor of Kalos", "Adventure Rules", "Strange Souvenir",
    "Lens Case", "Makeup Bag", "Travel Trunk", "Lumiose Galette",
    "Shalour Sable", "Jaw Fossil", "Sail Fossil", "Looker Ticket", "Bike",
    "Holo Caster", "Fairy Gem", "Mega Charm", "Mega Glove", "Mach Bike",
    "Acro Bike", "Wailmer Pail", "Devon Parts", "Soot Sack", "Basement Key",
    "Pokéblock Kit", "Letter", "Eon Ticket", "Scanner", "Go-Goggles",
    "Meteorite", "Key to Room 1", "Key to Room 2", "Key to Room 4",
    "Key to Room 6", "Storage Key", "Devon Scope", "S.S. Ticket",
    "HM07", "Devon Scuba Gear", "Contest Costume", "Contest Costume",
    "Magma Suit", "Aqua Suit", "Pair of Tickets", "Mega Bracelet",
    "Mega Pendant", "Mega Glasses", "Mega Anchor", "Mega Stickpin",
    "Mega Tiara", "Mega Anklet", "Meteorite", "Swampertite", "Sceptilite",
    "Sablenite", "Altarianite", "Galladite", "Audinite", "Metagrossite",
    "Sharpedonite", "Slowbronite", "Steelixite", "Pidgeotite", "Glalitite",
    "Diancite", "Prison Bottle", "Mega Cuff", "Cameruptite", "Lopunnite",
    "Salamencite", "Beedrillite", "Meteorite", "Meteorite", "Key Stone",
    "Meteorite Shard", "Eon Flute", "Normalium Z", "Firium Z", "Waterium Z",
    "Electrium Z", "Grassium Z", "Icium Z", "Fightinium Z", "Poisonium Z",
    "Groundium Z", "Flyinium Z", "Psychium Z", "Buginium Z", "Rockium Z",
    "Ghostium Z", "Dragonium Z", "Darkinium Z", "Steelium Z", "Fairium Z",
    "Pikanium Z", "Bottle Cap", "Gold Bottle Cap", "Z-Ring", "Decidium Z",
    "Incinium Z", "Primarium Z", "Tapunium Z", "Marshadium Z", "Aloraichium Z",
    "Snorlium Z", "Eevium Z", "Mewnium Z", "Normalium Z", "Firium Z",
    "Waterium Z", "Electrium Z", "Grassium Z", "Icium Z", "Fightinium Z",
    "Poisonium Z", "Groundium Z", "Flyinium Z", "Psychium Z", "Buginium Z",
    "Rockium Z", "Ghostium Z", "Dragonium Z", "Darkinium Z", "Steelium Z",
    "Fairium Z", "Pikanium Z", "Decidium Z", "Incinium Z", "Primarium Z",
    "Tapunium Z", "Marshadium Z", "Aloraichium Z", "Snorlium Z", "Eevium Z",
    "Mewnium Z", "Pikashunium Z", "Pikashunium Z", "???", "???", "???", "???",
    "Forage Bag", "Fishing Rod", "Professor's Mask", "Festival Ticket",
    "Sparkling Stone", "Adrenaline Orb", "Zygarde Cube", "???", "Ice Stone",
    "Ride Pager", "Beast Ball", "Big Malasada", "Red Nectar", "Yellow Nectar",
    "Pink Nectar", "Purple Nectar", "Sun Flute", "Moon Flute", "???",
    "Enigmatic Card", "???", "???", "???", "???", "???", "???", "???", "???",
    "???", "???", "???", "???", "???", "???", "???", "???", "???", "???",
    "Terrain Extender", "Protective Pads", "Electric Seed", "Psychic Seed",
    "Misty Seed", "Grassy Seed", "???", "???", "???", "???", "???", "???",
    "???", "???", "???", "???", "???", "???", "???", "???", "???", "???", "???",
    "???", "???", "Fighting Memory", "Flying Memory", "Poison Memory",
    "Ground Memory", "Rock Memory", "Bug Memory", "Ghost Memory",
    "Steel Memory", "Fire Memory", "Water Memory", "Grass Memory",
    "Electric Memory", "Psychic Memory", "Ice Memory", "Dragon Memory",
    "Dark Memory", "Fairy Memory"
};
static const char *ABILITY_LOOKUP[] = {
    "[Unknown]", "Stench", "Drizzle", "Speed Boost", "Battle Armor", "Sturdy",
    "Damp", "Limber", "Sand Veil", "Static", "Volt Absorb", "Water Absorb",
    "Oblivious", "Cloud Nine", "Compound Eyes", "Insomnia", "Color Change",
    "Immunity", "Flash Fire", "Shield Dust", "Own Tempo", "Suction Cups",
    "Intimidate", "Shadow Tag", "Rough Skin", "Wonder Guard", "Levitate",
    "Effect Spore", "Synchronize", "Clear Body", "Natural Cure",
    "Lightning Rod", "Serene Grace", "Swift Swim", "Chlorophyll",
    "Illuminate", "Trace", "Huge Power", "Poison Point", "Inner Focus",
    "Magma Armor", "Water Veil", "Magnet Pull", "Soundproof", "Rain Dish",
    "Sand Stream", "Pressure", "Thick Fat", "Early Bird", "Flame Body",
    "Run Away", "Keen Eye", "Hyper Cutter", "Pickup", "Truant", "Hustle",
    "Cute Charm", "Plus", "Minus", "Forecast", "Sticky Hold", "Shed Skin",
    "Guts", "Marvel Scale", "Liquid Ooze", "Overgrow", "Blaze", "Torrent",
    "Swarm", "Rock Head", "Drought", "Arena Trap", "Vital Spirit",
    "White Smoke", "Pure Power", "Shell Armor", "Air Lock", "Tangled Feet",
    "Motor Drive", "Rivalry", "Steadfast", "Snow Cloak", "Gluttony",
    "Anger Point", "Unburden", "Heatproof", "Simple", "Dry Skin", "Download",
    "Iron Fist", "Poison Heal", "Adaptability", "Skill Link", "Hydration",
    "Solar Power", "Quick Feet", "Normalize", "Sniper", "Magic Guard",
    "No Guard", "Stall", "Technician", "Leaf Guard", "Klutz", "Mold Breaker",
    "Super Luck", "Aftermath", "Anticipation", "Forewarn", "Unaware",
    "Tinted Lens", "Filter", "Slow Start", "Scrappy", "Storm Drain", "Ice Body",
    "Solid Rock", "Snow Warning", "Honey Gather", "Frisk", "Reckless",
    "Multitype", "Flower Gift", "Bad Dreams", "Pickpocket", "Sheer Force",
    "Contrary", "Unnerve", "Defiant", "Defeatist", "Cursed Body", "Healer",
    "Friend Guard", "Weak Armor", "Heavy Metal", "Light Metal", "Multiscale",
    "Toxic Boost", "Flare Boost", "Harvest", "Telepathy", "Moody", "Overcoat",
    "Poison Touch", "Regenerator", "Big Pecks", "Sand Rush", "Wonder Skin",
    "Analytic", "Illusion", "Imposter", "Infiltrator", "Mummy", "Moxie",
    "Justified", "Rattled", "Magic Bounce", "Sap Sipper", "Prankster",
    "Sand Force", "Iron Barbs", "Zen Mode", "Victory Star", "Turboblaze",
    "Teravolt", "Aroma Veil", "Flower Veil", "Cheek Pouch", "Protean",
    "Fur Coat", "Magician", "Bulletproof", "Competitive", "Strong Jaw",
    "Refrigerate", "Sweet Veil", "Stance Change", "Gale Wings", "Mega Launcher",
    "Grass Pelt", "Symbiosis", "Tough Claws", "Pixilate", "Gooey", "Aerilate",
    "Parental Bond", "Dark Aura", "Fairy Aura", "Aura Break", "Primordial Sea",
    "Desolate Land", "Delta Stream", "Stamina", "Wimp Out", "Emergency Exit",
    "Water Compaction", "Merciless", "Shields Down", "Stakeout", "Water Bubble",
    "Steelworker", "Berserk", "Slush Rush", "Long Reach", "Liquid Voice",
    "Triage", "Galvanize", "Surge Surfer", "Schooling", "Disguise", "Battle Bond",
    "Power Construct", "Corrosion", "Comatose", "Queenly Majesty", "Innards Out",
    "Dancer", "Battery", "Fluffy", "Dazzling", "Soul-Heart", "Tangling Hair",
    "Receiver", "Power of Alchemy", "Beast Boost", "RKS System",
    "Electric Surge", "Psychic Surge", "Misty Surge", "Grassy Surge",
    "Full Metal Body", "Shadow Shield", "Prism Armor"
 };
static const char *NATURE_LOOKUP[] = {
    "Hardy", "Lonely", "Brave", "Adamant", "Naughty", "Bold", "Docile",
    "Relaxed", "Impish", "Lax", "Timid", "Hasty", "Serious", "Jolly", "Naive",
    "Modest", "Mild", "Quiet", "Bashful", "Rash", "Calm", "Gentle", "Sassy",
    "Careful", "Quirky"
};
static const char *MOVE_LOOKUP[] = {
    " ", "Pound", "Karate Chop", "Double Slap", "Comet Punch",
    "Mega Punch", "Pay Day", "Fire Punch", "Ice Punch", "Thunder Punch",
    "Scratch", "Vice Grip", "Guillotine", "Razor Wind", "Swords Dance", "Cut",
    "Gust", "Wing Attack", "Whirlwind", "Fly", "Bind", "Slam", "Vine Whip",
    "Stomp", "Double Kick", "Mega Kick", "Jump Kick", "Rolling Kick",
    "Sand Attack", "Headbutt", "Horn Attack", "Fury Attack", "Horn Drill",
    "Tackle", "Body Slam", "Wrap", "Take Down", "Thrash", "Double-Edge",
    "Tail Whip", "Poison Sting", "Twineedle", "Pin Missile", "Leer", "Bite",
    "Growl", "Roar", "Sing", "Supersonic", "Sonic Boom", "Disable", "Acid",
    "Ember", "Flamethrower", "Mist", "Water Gun", "Hydro Pump", "Surf",
    "Ice Beam", "Blizzard", "Psybeam", "Bubble Beam", "Aurora Beam",
    "Hyper Beam", "Peck", "Drill Peck", "Submission", "Low Kick", "Counter",
    "Seismic Toss", "Strength", "Absorb", "Mega Drain", "Leech Seed", "Growth",
    "Razor Leaf", "Solar Beam", "Poison Powder", "Stun Spore", "Sleep Powder",
    "Petal Dance", "String Shot", "Dragon Rage", "Fire Spin", "Thunder Shock",
    "Thunderbolt", "Thunder Wave", "Thunder", "Rock Throw", "Earthquake",
    "Fissure", "Dig", "Toxic", "Confusion", "Psychic", "Hypnosis", "Meditate",
    "Agility", "Quick Attack", "Rage", "Teleport", "Night Shade", "Mimic",
    "Screech", "Double Team", "Recover", "Harden", "Minimize", "Smokescreen",
    "Confuse Ray", "Withdraw", "Defense Curl", "Barrier", "Light Screen",
    "Haze", "Reflect", "Focus Energy", "Bide", "Metronome", "Mirror Move",
    "Self-Destruct", "Egg Bomb", "Lick", "Smog", "Sludge", "Bone Club",
    "Fire Blast", "Waterfall", "Clamp", "Swift", "Skull Bash", "Spike Cannon",
    "Constrict", "Amnesia", "Kinesis", "Soft-Boiled", "High Jump Kick", "Glare",
    "Dream Eater", "Poison Gas", "Barrage", "Leech Life", "Lovely Kiss",
    "Sky Attack", "Transform", "Bubble", "Dizzy Punch", "Spore", "Flash",
    "Psywave", "Splash", "Acid Armor", "Crabhammer", "Explosion", "Fury Swipes",
    "Bonemerang", "Rest", "Rock Slide", "Hyper Fang", "Sharpen", "Conversion",
    "Tri Attack", "Super Fang", "Slash", "Substitute", "Struggle", "Sketch",
    "Triple Kick", "Thief", "Spider Web", "Mind Reader", "Nightmare",
    "Flame Wheel", "Snore", "Curse", "Flail", "Conversion 2", "Aeroblast",
    "Cotton Spore", "Reversal", "Spite", "Powder Snow", "Protect", "Mach Punch",
    "Scary Face", "Feint Attack", "Sweet Kiss", "Belly Drum", "Sludge Bomb",
    "Mud-Slap", "Octazooka", "Spikes", "Zap Cannon", "Foresight",
    "Destiny Bond", "Perish Song", "Icy Wind", "Detect", "Bone Rush",
    "Lock-On", "Outrage", "Sandstorm", "Giga Drain", "Endure", "Charm",
    "Rollout", "False Swipe", "Swagger", "Milk Drink", "Spark", "Fury Cutter",
    "Steel Wing", "Mean Look", "Attract", "Sleep Talk", "Heal Bell", "Return",
    "Present", "Frustration", "Safeguard", "Pain Split", "Sacred Fire",
    "Magnitude", "Dynamic Punch", "Megahorn", "Dragon Breath", "Baton Pass",
    "Encore", "Pursuit", "Rapid Spin", "Sweet Scent", "Iron Tail", "Metal Claw",
    "Vital Throw", "Morning Sun", "Synthesis", "Moonlight", "Hidden Power",
    "Cross Chop", "Twister", "Rain Dance", "Sunny Day", "Crunch", "Mirror Coat",
    "Psych Up", "Extreme Speed", "Ancient Power", "Shadow Ball", "Future Sight",
    "Rock Smash", "Whirlpool", "Beat Up", "Fake Out", "Uproar", "Stockpile",
    "Spit Up", "Swallow", "Heat Wave", "Hail", "Torment", "Flatter",
    "Will-O-Wisp", "Memento", "Facade", "Focus Punch", "Smelling Salts",
    "Follow Me", "Nature Power", "Charge", "Taunt", "Helping Hand", "Trick",
    "Role Play", "Wish", "Assist", "Ingrain", "Superpower", "Magic Coat",
    "Recycle", "Revenge", "Brick Break", "Yawn", "Knock Off", "Endeavor",
    "Eruption", "Skill Swap", "Imprison", "Refresh", "Grudge", "Snatch",
    "Secret Power", "Dive", "Arm Thrust", "Camouflage", "Tail Glow",
    "Luster Purge", "Mist Ball", "Feather Dance", "Teeter Dance", "Blaze Kick",
    "Mud Sport", "Ice Ball", "Needle Arm", "Slack Off", "Hyper Voice",
    "Poison Fang", "Crush Claw", "Blast Burn", "Hydro Cannon", "Meteor Mash",
    "Astonish", "Weather Ball", "Aromatherapy", "Fake Tears", "Air Cutter",
    "Overheat", "Odor Sleuth", "Rock Tomb", "Silver Wind", "Metal Sound",
    "Grass Whistle", "Tickle", "Cosmic Power", "Water Spout", "Signal Beam",
    "Shadow Punch", "Extrasensory", "Sky Uppercut", "Sand Tomb", "Sheer Cold",
    "Muddy Water", "Bullet Seed", "Aerial Ace", "Icicle Spear", "Iron Defense",
    "Block", "Howl", "Dragon Claw", "Frenzy Plant", "Bulk Up", "Bounce",
    "Mud Shot", "Poison Tail", "Covet", "Volt Tackle", "Magical Leaf",
    "Water Sport", "Calm Mind", "Leaf Blade", "Dragon Dance", "Rock Blast",
    "Shock Wave", "Water Pulse", "Doom Desire", "Psycho Boost", "Roost",
    "Gravity", "Miracle Eye", "Wake-Up Slap", "Hammer Arm", "Gyro Ball",
    "Healing Wish", "Brine", "Natural Gift", "Feint", "Pluck", "Tailwind",
    "Acupressure", "Metal Burst", "U-turn", "Close Combat", "Payback",
    "Assurance", "Embargo", "Fling", "Psycho Shift", "Trump Card", "Heal Block",
    "Wring Out", "Power Trick", "Gastro Acid", "Lucky Chant", "Me First",
    "Copycat", "Power Swap", "Guard Swap", "Punishment", "Last Resort",
    "Worry Seed", "Sucker Punch", "Toxic Spikes", "Heart Swap", "Aqua Ring",
    "Magnet Rise", "Flare Blitz", "Force Palm", "Aura Sphere", "Rock Polish",
    "Poison Jab", "Dark Pulse", "Night Slash", "Aqua Tail", "Seed Bomb",
    "Air Slash", "X-Scissor", "Bug Buzz", "Dragon Pulse", "Dragon Rush",
    "Power Gem", "Drain Punch", "Vacuum Wave", "Focus Blast", "Energy Ball",
    "Brave Bird", "Earth Power", "Switcheroo", "Giga Impact", "Nasty Plot",
    "Bullet Punch", "Avalanche", "Ice Shard", "Shadow Claw", "Thunder Fang",
    "Ice Fang", "Fire Fang", "Shadow Sneak", "Mud Bomb", "Psycho Cut",
    "Zen Headbutt", "Mirror Shot", "Flash Cannon", "Rock Climb", "Defog",
    "Trick Room", "Draco Meteor", "Discharge", "Lava Plume", "Leaf Storm",
    "Power Whip", "Rock Wrecker", "Cross Poison", "Gunk Shot", "Iron Head",
    "Magnet Bomb", "Stone Edge", "Captivate", "Stealth Rock", "Grass Knot",
    "Chatter", "Judgment", "Bug Bite", "Charge Beam", "Wood Hammer", "Aqua Jet",
    "Attack Order", "Defend Order", "Heal Order", "Head Smash", "Double Hit",
    "Roar of Time", "Spacial Rend", "Lunar Dance", "Crush Grip", "Magma Storm",
    "Dark Void", "Seed Flare", "Ominous Wind", "Shadow Force", "Hone Claws",
    "Wide Guard", "Guard Split", "Power Split", "Wonder Room", "Psyshock",
    "Venoshock", "Autotomize", "Rage Powder", "Telekinesis", "Magic Room",
    "Smack Down", "Storm Throw", "Flame Burst", "Sludge Wave", "Quiver Dance",
    "Heavy Slam", "Synchronoise", "Electro Ball", "Soak", "Flame Charge",
    "Coil", "Low Sweep", "Acid Spray", "Foul Play", "Simple Beam",
    "Entrainment", "After You", "Round", "Echoed Voice", "Chip Away",
    "Clear Smog", "Stored Power", "Quick Guard", "Ally Switch", "Scald",
    "Shell Smash", "Heal Pulse", "Hex", "Sky Drop", "Shift Gear",
    "Circle Throw", "Incinerate", "Quash", "Acrobatics", "Reflect Type",
    "Retaliate", "Final Gambit", "Bestow", "Inferno", "Water Pledge",
    "Fire Pledge", "Grass Pledge", "Volt Switch", "Struggle Bug", "Bulldoze",
    "Frost Breath", "Dragon Tail", "Work Up", "Electroweb", "Wild Charge",
    "Drill Run", "Dual Chop", "Heart Stamp", "Horn Leech", "Sacred Sword",
    "Razor Shell", "Heat Crash", "Leaf Tornado", "Steamroller", "Cotton Guard",
    "Night Daze", "Psystrike", "Tail Slap", "Hurricane", "Head Charge",
    "Gear Grind", "Searing Shot", "Techno Blast", "Relic Song", "Secret Sword",
    "Glaciate", "Bolt Strike", "Blue Flare", "Fiery Dance", "Freeze Shock",
    "Ice Burn", "Snarl", "Icicle Crash", "V-create", "Fusion Flare",
    "Fusion Bolt", "Flying Press", "Mat Block", "Belch", "Rototiller",
    "Sticky Web", "Fell Stinger", "Phantom Force", "Trick-or-Treat",
    "Noble Roar", "Ion Deluge", "Parabolic Charge", "Forest's Curse",
    "Petal Blizzard", "Freeze-Dry", "Disarming Voice", "Parting Shot",
    "Topsy-Turvy", "Draining Kiss", "Crafty Shield", "Flower Shield",
    "Grassy Terrain", "Misty Terrain", "Electrify", "Play Rough", "Fairy Wind",
    "Moonblast", "Boomburst", "Fairy Lock", "King's Shield", "Play Nice",
    "Confide", "Diamond Storm", "Steam Eruption", "Hyperspace Hole",
    "Water Shuriken", "Mystical Fire", "Spiky Shield", "Aromatic Mist",
    "Eerie Impulse", "Venom Drench", "Powder", "Geomancy", "Magnetic Flux",
    "Happy Hour", "Electric Terrain", "Dazzling Gleam", "Celebrate",
    "Hold Hands", "Baby-Doll Eyes", "Nuzzle", "Hold Back", "Infestation",
    "Power-Up Punch", "Oblivion Wing", "Thousand Arrows", "Thousand Waves",
    "Land's Wrath", "Light of Ruin", "Origin Pulse", "Precipice Blades",
    "Dragon Ascent", "Hyperspace Fury", "Breakneck Blitz", "Breakneck Blitz",
    "All-Out Pummeling", "All-Out Pummeling", "Supersonic Skystrike",
    "Supersonic Skystrike", "Acid Downpour", "Acid Downpour", "Tectonic Rage",
    "Tectonic Rage", "Continental Crush", "Continental Crush",
    "Savage Spin-Out", "Savage Spin-Out", "Never-Ending Nightmare",
    "Never-Ending Nightmare", "Corkscrew Crash", "Corkscrew Crash",
    "Inferno Overdrive", "Inferno Overdrive", "Hydro Vortex", "Hydro Vortex",
    "Bloom Doom", "Bloom Doom", "Gigavolt Havoc", "Gigavolt Havoc",
    "Shattered Psyche", "Shattered Psyche", "Subzero Slammer",
    "Subzero Slammer", "Devastating Drake", "Devastating Drake",
    "Black Hole Eclipse", "Black Hole Eclipse", "Twinkle Tackle",
    "Twinkle Tackle", "Catastropika", "Shore Up", "First Impression",
    "Baneful Bunker", "Spirit Shackle", "Darkest Lariat", "Sparkling Aria",
    "Ice Hammer", "Floral Healing", "High Horsepower", "Strength Sap",
    "Solar Blade", "Leafage", "Spotlight", "Toxic Thread", "Laser Focus",
    "Gear Up", "Throat Chop", "Pollen Puff", "Anchor Shot", "Psychic Terrain",
    "Lunge", "Fire Lash", "Power Trip", "Burn Up", "Speed Swap", "Smart Strike",
    "Purify", "Revelation Dance", "Core Enforcer", "Trop Kick", "Instruct",
    "Beak Blast", "Clanging Scales", "Dragon Hammer", "Brutal Swing",
    "Aurora Veil", "Sinister Arrow Raid", "Malicious Moonsault",
    "Oceanic Operetta", "Guardian of Alola", "Soul-Stealing 7-Star Strike",
    "Stoked Sparksurfer", "Pulverizing Pancake", "Extreme Evoboost",
    "Genesis Supernova", "Shell Trap", "Fleur Cannon", "Psychic Fangs",
    "Stomping Tantrum", "Shadow Bone", "Accelerock", "Liquidation",
    "Prismatic Laser", "Spectral Thief", "Sunsteel Strike", "Moongeist Beam",
    "Tearful Look", "Zing Zap", "Nature's Madness", "Multi-Attack",
    "10,000,000 Volt Thunderbolt"
};


// COMPRESS COMPRESS COMPRESS
// POKEMON FORMS IS SIZE OF ARRAY
// BASE STATS PER POKEMON PER FORM X6, COLOR, TYPE1, TYPE2
static const char P_001[][9] = {
    { 45 , 49 , 49 , 65 , 65 , 45 , 5 , 12 , 4 }  // No.  1   // Bulbasaur Grass Poison
};
static const char P_002[][9] = {
    { 60 , 62 , 63 , 80 , 80 , 60 , 5 , 12 , 4 }  // No.  2   // Ivysaur Grass Poison
};
static const char P_003[][9] = {
    { 80 , 82 , 83 , 100 , 100 , 80 , 5 , 12 , 4 },  // No.  3   // Venusaur Grass Poison
    { 80 , 100 , 123 , 122 , 120 , 80 , 5 , 12 , 4 }  // No.  3   // Venusaur Grass Poison
};
static const char P_004[][9] = {
    { 39 , 52 , 43 , 60 , 50 , 65 , 8 , 10 , 0 }  // No.  4   // Charmander Fire
};
static const char P_005[][9] = {
    { 58 , 64 , 58 , 80 , 65 , 80 , 8 , 10 , 0 }  // No.  5   // Charmeleon Fire
};
static const char P_006[][9] = {
    { 78 , 84 , 78 , 109 , 85 , 100 , 8 , 10 , 3 },  // No.  6   // Charizard Fire Flying
    { 78 , 130 , 111 , 130 , 85 , 100 , 1 , 10 , 16 },  // No.  6   // Charizard Fire Dragon
    { 78 , 104 , 78 , 159 , 115 , 100 , 8 , 10 , 3 }  // No.  6   // Charizard Fire Flying
};
static const char P_007[][9] = {
    { 44 , 48 , 65 , 50 , 64 , 43 , 2 , 11 , 0 }  // No.  7   // Squirtle Water
};
static const char P_008[][9] = {
    { 59 , 63 , 80 , 65 , 80 , 58 , 2 , 11 , 0 }  // No.  8   // Wartortle Water
};
static const char P_009[][9] = {
    { 79 , 83 , 100 , 85 , 105 , 78 , 2 , 11 , 0 },  // No.  9   // Blastoise Water
    { 79 , 103 , 120 , 135 , 115 , 78 , 2 , 11 , 0 }  // No.  9   // Blastoise Water
};
static const char P_010[][9] = {
    { 45 , 30 , 35 , 20 , 20 , 45 , 5 , 7 , 0 }  // No.  10   // Caterpie Bug
};
static const char P_011[][9] = {
    { 50 , 20 , 55 , 25 , 25 , 30 , 5 , 7 , 0 }  // No.  11   // Metapod Bug
};
static const char P_012[][9] = {
    { 60 , 45 , 50 , 90 , 80 , 70 , 9 , 7 , 3 }  // No.  12   // Butterfree Bug Flying
};
static const char P_013[][9] = {
    { 40 , 35 , 30 , 20 , 20 , 50 , 3 , 7 , 4 }  // No.  13   // Weedle Bug Poison
};
static const char P_014[][9] = {
    { 45 , 25 , 50 , 25 , 25 , 35 , 10 , 7 , 4 }  // No.  14   // Kakuna Bug Poison
};
static const char P_015[][9] = {
    { 65 , 90 , 40 , 45 , 80 , 75 , 10 , 7 , 4 },  // No.  15   // Beedrill Bug Poison
    { 65 , 150 , 40 , 15 , 80 , 145 , 10 , 7 , 4 }  // No.  15   // Beedrill Bug Poison
};
static const char P_016[][9] = {
    { 40 , 45 , 40 , 35 , 35 , 56 , 3 , 1 , 3 }  // No.  16   // Pidgey Normal Flying
};
static const char P_017[][9] = {
    { 63 , 60 , 55 , 50 , 50 , 71 , 3 , 1 , 3 }  // No.  17   // Pidgeotto Normal Flying
};
static const char P_018[][9] = {
    { 83 , 80 , 75 , 70 , 70 , 101 , 3 , 1 , 3 },  // No.  18   // Pidgeot Normal Flying
    { 83 , 80 , 80 , 135 , 80 , 121 , 3 , 1 , 3 }  // No.  18   // Pidgeot Normal Flying
};
static const char P_019[][9] = {
    { 30 , 56 , 35 , 25 , 35 , 72 , 7 , 1 , 0 },  // No.  19   // Rattata Normal
    { 30 , 56 , 35 , 25 , 35 , 72 , 1 , 17 , 1 }  // No.  19   // Rattata Dark Normal
};
static const char P_020[][9] = {
    { 55 , 81 , 60 , 50 , 70 , 97 , 3 , 1 , 0 },  // No.  20   // Raticate Normal
    { 75 , 71 , 70 , 40 , 80 , 77 , 1 , 17 , 1 }  // No.  20   // Raticate Dark Normal
};
static const char P_021[][9] = {
    { 40 , 60 , 30 , 31 , 31 , 70 , 3 , 1 , 3 }  // No.  21   // Spearow Normal Flying
};
static const char P_022[][9] = {
    { 65 , 90 , 65 , 61 , 61 , 100 , 3 , 1 , 3 }  // No.  22   // Fearow Normal Flying
};
static const char P_023[][9] = {
    { 35 , 60 , 44 , 40 , 54 , 55 , 7 , 4 , 0 }  // No.  23   // Ekans Poison
};
static const char P_024[][9] = {
    { 60 , 95 , 69 , 65 , 79 , 80 , 7 , 4 , 0 }  // No.  24   // Arbok Poison
};
static const char P_025[][9] = {
    { 35 , 55 , 40 , 50 , 50 , 90 , 10 , 13 , 0 },  // No.  25   // Pikachu Default Electric
    { 35 , 55 , 40 , 50 , 50 , 90 , 10 , 13 , 0 },  // No.  25   // Pikachu Ori cap Electric
    { 35 , 55 , 40 , 50 , 50 , 90 , 10 , 13 , 0 },  // No.  25   // Pikachu Hoenn Cap Electric
    { 35 , 55 , 40 , 50 , 50 , 90 , 10 , 13 , 0 },  // No.  25   // Pikachu Sinnoh Cap Electric
    { 35 , 55 , 40 , 50 , 50 , 90 , 10 , 13 , 0 },  // No.  25   // Pikachu Unova Cap Electric
    { 35 , 55 , 40 , 50 , 50 , 90 , 10 , 13 , 0 },  // No.  25   // Pikachu Kalos Cap Electric
    { 35 , 55 , 40 , 50 , 50 , 90 , 10 , 13 , 0 }  // No.  25   // Pikachu Alola Cap Electric
};
static const char P_026[][9] = {
    { 60 , 90 , 55 , 90 , 80 , 110 , 10 , 13 , 0 },  // No.  26   // Raichu Electric
    { 60 , 85 , 50 , 95 , 85 , 110 , 3 , 13 , 14 }  // No.  26   // Raichu Electric Psychic
};
static const char P_027[][9] = {
    { 50 , 75 , 85 , 20 , 30 , 40 , 10 , 5 , 0 },  // No.  27   // Sandshrew Ground
    { 50 , 75 , 90 , 10 , 35 , 40 , 9 , 15 , 9 }  // No.  27   // Sandshrew Ice Steel
};
static const char P_028[][9] = {
    { 75 , 100 , 110 , 45 , 55 , 65 , 10 , 5 , 0 },  // No.  28   // Sandslash Ground
    { 75 , 100 , 120 , 25 , 65 , 65 , 9 , 15 , 9 }  // No.  28   // Sandslash Ice Steel
};
static const char P_029[][9] = {
    { 55 , 47 , 52 , 40 , 40 , 41 , 2 , 4 , 0 }  // No.  29   // Nidoran♀ Poison
};
static const char P_030[][9] = {
    { 70 , 62 , 67 , 55 , 55 , 56 , 2 , 4 , 0 }  // No.  30   // Nidorina Poison
};
static const char P_031[][9] = {
    { 90 , 92 , 87 , 75 , 85 , 76 , 2 , 4 , 5 }  // No.  31   // Nidoqueen Poison Ground
};
static const char P_032[][9] = {
    { 46 , 57 , 40 , 40 , 40 , 50 , 7 , 4 , 0 }  // No.  32   // Nidoran♂ Poison
};
static const char P_033[][9] = {
    { 61 , 72 , 57 , 55 , 55 , 65 , 7 , 4 , 0 }  // No.  33   // Nidorino Poison
};
static const char P_034[][9] = {
    { 81 , 102 , 77 , 85 , 75 , 85 , 7 , 4 , 5 }  // No.  34   // Nidoking Poison Ground
};
static const char P_035[][9] = {
    { 70 , 45 , 48 , 60 , 65 , 35 , 6 , 18 , 0 }  // No.  35   // Clefairy Fairy
};
static const char P_036[][9] = {
    { 95 , 70 , 73 , 95 , 90 , 60 , 6 , 18 , 0 }  // No.  36   // Clefable Fairy
};
static const char P_037[][9] = {
    { 38 , 41 , 40 , 50 , 65 , 65 , 3 , 10 , 0 },  // No.  37   // Vulpix Fire
    { 38 , 41 , 40 , 50 , 65 , 65 , 9 , 15 , 0 }  // No.  37   // Vulpix Ice
};
static const char P_038[][9] = {
    { 73 , 76 , 75 , 81 , 100 , 100 , 10 , 10 , 0 },  // No.  38   // Ninetales Fire
    { 73 , 67 , 75 , 81 , 100 , 109 , 2 , 15 , 18 }  // No.  38   // Ninetales Ice Fairy
};
static const char P_039[][9] = {
    { 115 , 45 , 20 , 45 , 25 , 20 , 6 , 1 , 18 }  // No.  39   // Jigglypuff Normal Fairy
};
static const char P_040[][9] = {
    { 140 , 70 , 45 , 85 , 50 , 45 , 6 , 1 , 18 }  // No.  40   // Wigglytuff Normal Fairy
};
static const char P_041[][9] = {
    { 40 , 45 , 35 , 30 , 40 , 55 , 7 , 4 , 3 }  // No.  41   // Zubat Poison Flying
};
static const char P_042[][9] = {
    { 75 , 80 , 70 , 65 , 75 , 90 , 7 , 4 , 3 }  // No.  42   // Golbat Poison Flying
};
static const char P_043[][9] = {
    { 45 , 50 , 55 , 75 , 65 , 30 , 2 , 12 , 4 }  // No.  43   // Oddish Grass Poison
};
static const char P_044[][9] = {
    { 60 , 65 , 70 , 85 , 75 , 40 , 2 , 12 , 4 }  // No.  44   // Gloom Grass Poison
};
static const char P_045[][9] = {
    { 75 , 80 , 85 , 110 , 90 , 50 , 8 , 12 , 4 }  // No.  45   // Vileplume Grass Poison
};
static const char P_046[][9] = {
    { 35 , 70 , 55 , 45 , 55 , 25 , 8 , 7 , 12 }  // No.  46   // Paras Bug Grass
};
static const char P_047[][9] = {
    { 60 , 95 , 80 , 60 , 80 , 30 , 8 , 7 , 12 }  // No.  47   // Parasect Bug Grass
};
static const char P_048[][9] = {
    { 60 , 55 , 50 , 40 , 55 , 45 , 7 , 7 , 4 }  // No.  48   // Venonat Bug Poison
};
static const char P_049[][9] = {
    { 70 , 65 , 60 , 90 , 75 , 90 , 7 , 7 , 4 }  // No.  49   // Venomoth Bug Poison
};
static const char P_050[][9] = {
    { 10 , 55 , 25 , 35 , 45 , 95 , 3 , 5 , 0 },  // No.  50   // Diglett Ground
    { 10 , 55 , 30 , 35 , 45 , 90 , 3 , 5 , 9 }  // No.  50   // Diglett Ground Steel
};
static const char P_051[][9] = {
    { 35 , 100 , 50 , 50 , 70 , 120 , 3 , 5 , 0 },  // No.  51   // Dugtrio Ground
    { 35 , 100 , 60 , 50 , 70 , 110 , 3 , 5 , 9 }  // No.  51   // Dugtrio Ground Steel
};
static const char P_052[][9] = {
    { 40 , 45 , 35 , 40 , 40 , 90 , 10 , 1 , 0 },  // No.  52   // Meowth Normal
    { 40 , 35 , 35 , 50 , 40 , 90 , 2 , 17 , 0 }  // No.  52   // Meowth Dark
};
static const char P_053[][9] = {
    { 65 , 70 , 60 , 65 , 65 , 115 , 10 , 1 , 0 },  // No.  53   // Persian Normal
    { 65 , 60 , 60 , 75 , 65 , 115 , 2 , 17 , 0 }  // No.  53   // Persian Dark
};
static const char P_054[][9] = {
    { 50 , 52 , 48 , 65 , 50 , 55 , 10 , 11 , 0 }  // No.  54   // Psyduck Water
};
static const char P_055[][9] = {
    { 80 , 82 , 78 , 95 , 80 , 85 , 2 , 11 , 0 }  // No.  55   // Golduck Water
};
static const char P_056[][9] = {
    { 40 , 80 , 35 , 35 , 45 , 70 , 3 , 2 , 0 }  // No.  56   // Mankey Fighting
};
static const char P_057[][9] = {
    { 65 , 105 , 60 , 60 , 70 , 95 , 3 , 2 , 0 }  // No.  57   // Primeape Fighting
};
static const char P_058[][9] = {
    { 55 , 70 , 45 , 70 , 50 , 60 , 3 , 10 , 0 }  // No.  58   // Growlithe Fire
};
static const char P_059[][9] = {
    { 90 , 110 , 80 , 100 , 80 , 95 , 3 , 10 , 0 }  // No.  59   // Arcanine Fire
};
static const char P_060[][9] = {
    { 40 , 50 , 40 , 40 , 40 , 90 , 2 , 11 , 0 }  // No.  60   // Poliwag Water
};
static const char P_061[][9] = {
    { 65 , 65 , 65 , 50 , 50 , 90 , 2 , 11 , 0 }  // No.  61   // Poliwhirl Water
};
static const char P_062[][9] = {
    { 90 , 95 , 95 , 70 , 90 , 70 , 2 , 11 , 2 }  // No.  62   // Poliwrath Water Fighting
};
static const char P_063[][9] = {
    { 25 , 20 , 15 , 105 , 55 , 90 , 3 , 14 , 0 }  // No.  63   // Abra Psychic
};
static const char P_064[][9] = {
    { 40 , 35 , 30 , 120 , 70 , 105 , 3 , 14 , 0 }  // No.  64   // Kadabra Psychic
};
static const char P_065[][9] = {
    { 55 , 50 , 45 , 135 , 95 , 120 , 3 , 14 , 0 },  // No.  65   // Alakazam Psychic
    { 55 , 50 , 65 , 175 , 105 , 150 , 3 , 14 , 0 }   // No.  65   // Alakazam Psychic
};
static const char P_066[][9] = {
    { 70 , 80 , 50 , 35 , 35 , 35 , 4 , 2 , 0 }   // No.  66   // Machop Fighting
};
static const char P_067[][9] = {
    { 80 , 100 , 70 , 50 , 60 , 45 , 4 , 2 , 0 }   // No.  67   // Machoke Fighting
};
static const char P_068[][9] = {
    { 90 , 130 , 80 , 65 , 85 , 55 , 4 , 2 , 0 }  // No.  68   // Machamp Fighting
};
static const char P_069[][9] = {
    { 50 , 75 , 35 , 70 , 30 , 40 , 5 , 12 , 4 }  // No.  69   // Bellsprout Grass Poison
};
static const char P_070[][9] = {
    { 65 , 90 , 50 , 85 , 45 , 55 , 5 , 12 , 4 }   // No.  70   // Weepinbell Grass Poison
};
static const char P_071[][9] = {
    { 80 , 105 , 65 , 100 , 70 , 70 , 5 , 12 , 4 }   // No.  71   // Victreebel Grass Poison
};
static const char P_072[][9] = {
    { 40 , 40 , 35 , 50 , 100 , 70 , 2 , 11 , 4 }   // No.  72   // Tentacool Water Poison
};
static const char P_073[][9] = {
    { 80 , 70 , 65 , 80 , 120 , 100 , 2 , 11 , 4 }   // No.  73   // Tentacruel Water Poison
};
static const char P_074[][9] = {
    { 40 , 80 , 100 , 30 , 30 , 20 , 3 , 6 , 5 },   // No.  74   // Geodude Rock Ground
    { 40 , 80 , 100 , 30 , 30 , 20 , 4 , 6 , 13 }   // No.  74   // Geodude Rock Electric
};
static const char P_075[][9] = {
    { 55 , 95 , 115 , 45 , 45 , 35 , 3 , 6 , 5 },  // No.  75   // Graveler Rock Ground
    { 55 , 95 , 115 , 45 , 45 , 35 , 4 , 6 , 13 }   // No.  75   // Graveler Rock Electric
};
static const char P_076[][9] = {
    { 80 , 120 , 130 , 55 , 65 , 45 , 3 , 6 , 5 },   // No.  76   // Golem Rock Ground
    { 80 , 120 , 130 , 55 , 65 , 45 , 4 , 6 , 13 }   // No.  76   // Golem Rock Electric
};
static const char P_077[][9] = {
    { 50 , 85 , 55 , 65 , 65 , 90 , 10 , 10 , 0 }   // No.  77   // Ponyta Fire
};
static const char P_078[][9] = {
    { 65 , 100 , 70 , 80 , 80 , 105 , 10 , 10 , 0 }  // No.  78   // Rapidash Fire
};
static const char P_079[][9] = {
    { 90 , 65 , 65 , 40 , 40 , 15 , 6 , 11 , 14 }  // No.  79   // Slowpoke Water Psychic
};
static const char P_080[][9] = {
    { 95 , 75 , 110 , 100 , 80 , 30 , 6 , 11 , 14 },  // No.  80   // Slowbro Water Psychic
    { 95 , 75 , 180 , 130 , 80 , 30 , 6 , 11 , 14 }  // No.  80   // Mega Slowbro Water Psychic
};
static const char P_081[][9] = {
    { 25 , 35 , 70 , 95 , 55 , 45 , 4 , 13 , 9 }  // No.  81   // Magnemite Electric Steel
};
static const char P_082[][9] = {
    { 50 , 60 , 95 , 120 , 70 , 70 , 4 , 13 , 9 }  // No.  82   // Magneton Electric Steel
};
static const char P_083[][9] = {
    { 52 , 90 , 55 , 58 , 62 , 60 , 3 , 1 , 3 }  // No.  83   // Farfetch'd Normal Flying
};
static const char P_084[][9] = {
    { 35 , 85 , 45 , 35 , 35 , 75 , 3 , 1 , 3 }  // No.  84   // Doduo Normal Flying
};
static const char P_085[][9] = {
    { 60 , 110 , 70 , 60 , 60 , 110 , 3 , 1 , 3 }  // No.  85   // Dodrio Normal Flying
};
static const char P_086[][9] = {
    { 65 , 45 , 55 , 45 , 70 , 45 , 9 , 11 , 0 }  // No.  86   // Seel Water
};
static const char P_087[][9] = {
    { 90 , 70 , 80 , 70 , 95 , 70 , 9 , 11 , 15 }  // No.  87   // Dewgong Water Ice
};
static const char P_088[][9] = {
    { 80 , 80 , 50 , 40 , 50 , 25 , 7 , 4 , 0 },  // No.  88   // Grimer Poison
    { 80 , 80 , 50 , 40 , 50 , 25 , 5 , 4 , 17 }  // No.  88   // Grimer Poison Dark
};
static const char P_089[][9] = {
    { 105 , 105 , 75 , 65 , 100 , 50 , 7 , 4 , 0 },  // No.  89   // Muk Poison
    { 105 , 105 , 75 , 65 , 100 , 50 , 5 , 4 , 17 }  // No.  89   // Muk Poison Dark
};
static const char P_090[][9] = {
    { 30 , 65 , 100 , 45 , 25 , 40 , 7 , 11 , 0 }  // No.  90   // Shellder Water
};
static const char P_091[][9] = {
    { 50 , 95 , 180 , 85 , 45 , 70 , 7 , 11 , 15 }  // No.  91   // Cloyster Water Ice
};
static const char P_092[][9] = {
    { 30 , 35 , 30 , 100 , 35 , 80 , 7 , 8 , 4 }  // No.  92   // Gastly Ghost Poison
};
static const char P_093[][9] = {
    { 45 , 50 , 45 , 115 , 55 , 95 , 7 , 8 , 4 }  // No.  93   // Haunter Ghost Poison
};
static const char P_094[][9] = {
    { 60 , 65 , 60 , 130 , 75 , 110 , 7 , 8 , 4 },  // No.  94   // Gengar Ghost Poison
    { 60 , 65 , 80 , 170 , 95 , 130 , 7 , 8 , 4 }  // No.  94   // Gengar Ghost Poison
};
static const char P_095[][9] = {
    { 35 , 45 , 160 , 30 , 45 , 70 , 4 , 6 , 5 }  // No.  95   // Onix Rock Ground
};
static const char P_096[][9] = {
    { 60 , 48 , 45 , 43 , 90 , 42 , 10 , 14 , 0 }  // No.  96   // Drowzee Psychic
};
static const char P_097[][9] = {
    { 85 , 73 , 70 , 73 , 115 , 67 , 10 , 14 , 0 }  // No.  97   // Hypno Psychic
};
static const char P_098[][9] = {
    { 30 , 105 , 90 , 25 , 25 , 50 , 8 , 11 , 0 }  // No.  98   // Krabby Water
};
static const char P_099[][9] = {
    { 55 , 130 , 115 , 50 , 50 , 75 , 8 , 11 , 0 }  // No.  99   // Kingler Water
};
static const char P_100[][9] = {
    { 40 , 30 , 50 , 55 , 55 , 100 , 8 , 13 , 0 }  // No.  100   // Voltorb Electric
};
static const char P_101[][9] = {
    { 60 , 50 , 70 , 80 , 80 , 150 , 8 , 13 , 0 }  // No.  101   // Electrode Electric
};
static const char P_102[][9] = {
    { 60 , 40 , 80 , 60 , 45 , 40 , 6 , 12 , 14 }  // No.  102   // Exeggcute Grass Psychic
};
static const char P_103[][9] = {
    { 95 , 95 , 85 , 125 , 75 , 55 , 10 , 12 , 14 },  // No.  103   // Exeggutor Grass Psychic
    { 95 , 105 , 85 , 125 , 75 , 45 , 10 , 12 , 16 }  // No.  103   // Exeggutor Grass Dragon
};
static const char P_104[][9] = {
    { 50 , 50 , 95 , 40 , 50 , 35 , 3 , 5 , 0 }  // No.  104   // Cubone Ground
};
static const char P_105[][9] = {
    { 60 , 80 , 110 , 50 , 80 , 45 , 3 , 5 , 0 },  // No.  105   // Marowak Ground
    { 60 , 80 , 110 , 50 , 80 , 45 , 7 , 10 , 8 }  // No.  105   // Marowak Fire Ghost
};
static const char P_106[][9] = {
    { 50 , 120 , 53 , 35 , 110 , 87 , 3 , 2 , 0 }  // No.  106   // Hitmonlee Fighting
};
static const char P_107[][9] = {
    { 50 , 105 , 79 , 35 , 110 , 76 , 3 , 2 , 0 }  // No.  107   // Hitmonchan Fighting
};
static const char P_108[][9] = {
    { 90 , 55 , 75 , 60 , 75 , 30 , 6 , 1 , 0 }  // No.  108   // Lickitung Normal
};
static const char P_109[][9] = {
    { 40 , 65 , 95 , 60 , 45 , 35 , 7 , 4 , 0 }  // No.  109   // Koffing Poison
};
static const char P_110[][9] = {
    { 65 , 90 , 120 , 85 , 70 , 60 , 7 , 4 , 0 }  // No.  110   // Weezing Poison
};
static const char P_111[][9] = {
    { 80 , 85 , 95 , 30 , 30 , 25 , 4 , 5 , 6 }  // No.  111   // Rhyhorn Ground Rock
};
static const char P_112[][9] = {
    { 105 , 130 , 120 , 45 , 45 , 40 , 4 , 5 , 6 }  // No.  112   // Rhydon Ground Rock
};
static const char P_113[][9] = {
    { 250 , 5 , 5 , 35 , 105 , 50 , 6 , 1 , 0 }  // No.  113   // Chansey Normal
};
static const char P_114[][9] = {
    { 65 , 55 , 115 , 100 , 40 , 60 , 2 , 12 , 0 }  // No.  114   // Tangela Grass
};
static const char P_115[][9] = {
    { 105 , 95 , 80 , 40 , 80 , 90 , 3 , 1 , 0 },  // No.  115   // Kangaskhan Normal
    { 105 , 125 , 100 , 60 , 100 , 100 , 3 , 1 , 0 }  // No.  115   // Kangaskhan Normal
};
static const char P_116[][9] = {
    { 30 , 40 , 70 , 70 , 25 , 60 , 2 , 11 , 0 }  // No.  116   // Horsea Water
};
static const char P_117[][9] = {
    { 55 , 65 , 95 , 95 , 45 , 85 , 2 , 11 , 0 }  // No.  117   // Seadra Water
};
static const char P_118[][9] = {
    { 45 , 67 , 60 , 35 , 50 , 63 , 8 , 11 , 0 }  // No.  118   // Goldeen Water
};
static const char P_119[][9] = {
    { 80 , 92 , 65 , 65 , 80 , 68 , 8 , 11 , 0 }  // No.  119   // Seaking Water
};
static const char P_120[][9] = {
    { 30 , 45 , 55 , 70 , 55 , 85 , 3 , 11 , 0 }  // No.  120   // Staryu Water
};
static const char P_121[][9] = {
    { 60 , 75 , 85 , 100 , 85 , 115 , 7 , 11 , 14 }  // No.  121   // Starmie Water Psychic
};
static const char P_122[][9] = {
    { 40 , 45 , 65 , 100 , 120 , 90 , 6 , 14 , 18 }  // No.  122   // Mr. Mime Psychic Fairy
};
static const char P_123[][9] = {
    { 70 , 110 , 80 , 55 , 80 , 105 , 5 , 7 , 3 }  // No.  123   // Scyther Bug Flying
};
static const char P_124[][9] = {
    { 65 , 50 , 35 , 115 , 95 , 95 , 8 , 15 , 14 }  // No.  124   // Jynx Ice Psychic
};
static const char P_125[][9] = {
    { 65 , 83 , 57 , 95 , 85 , 105 , 10 , 13 , 0 }  // No.  125   // Electabuzz Electric
};
static const char P_126[][9] = {
    { 65 , 95 , 57 , 100 , 85 , 93 , 8 , 10 , 0 }  // No.  126   // Magmar Fire
};
static const char P_127[][9] = {
    { 65 , 125 , 100 , 55 , 70 , 85 , 3 , 7 , 0 },  // No.  127   // Pinsir Bug
    { 65 , 155 , 120 , 65 , 90 , 105 , 3 , 7 , 0 }  // No.  127   // Pinsir Bug
};
static const char P_128[][9] = {
    { 75 , 100 , 95 , 40 , 70 , 110 , 3 , 1 , 0 }  // No.  128   // Tauros Normal
};
static const char P_129[][9] = {
    { 20 , 10 , 55 , 15 , 20 , 80 , 8 , 11 , 0 }  // No.  129   // Magikarp Water
};
static const char P_130[][9] = {
    { 95 , 125 , 79 , 60 , 100 , 81 , 2 , 11 , 3 },  // No.  130   // Gyarados Water Flying
    { 95 , 155 , 109 , 70 , 130 , 81 , 2 , 11 , 3 }  // No.  130   // Gyarados Water Flying
};
static const char P_131[][9] = {
    { 130 , 85 , 80 , 85 , 95 , 60 , 2 , 11 , 15 }  // No.  131   // Lapras Water Ice
};
static const char P_132[][9] = {
    { 48 , 48 , 48 , 48 , 48 , 48 , 7 , 1 , 0 }  // No.  132   // Ditto Normal
};
static const char P_133[][9] = {
    { 55 , 55 , 50 , 45 , 65 , 55 , 3 , 1 , 0 }  // No.  133   // Eevee Normal
};
static const char P_134[][9] = {
    { 130 , 65 , 60 , 110 , 95 , 65 , 2 , 11 , 0 }  // No.  134   // Vaporeon Water
};
static const char P_135[][9] = {
    { 65 , 65 , 60 , 110 , 95 , 130 , 10 , 13 , 0 }  // No.  135   // Jolteon Electric
};
static const char P_136[][9] = {
    { 65 , 130 , 60 , 95 , 110 , 65 , 8 , 10 , 0 }  // No.  136   // Flareon Fire
};
static const char P_137[][9] = {
    { 65 , 60 , 70 , 85 , 75 , 40 , 6 , 1 , 0 }  // No.  137   // Porygon Normal
};
static const char P_138[][9] = {
    { 35 , 40 , 100 , 90 , 55 , 35 , 2 , 6 , 11 }  // No.  138   // Omanyte Rock Water
};
static const char P_139[][9] = {
    { 70 , 60 , 125 , 115 , 70 , 55 , 2 , 6 , 11 }  // No.  139   // Omastar Rock Water
};
static const char P_140[][9] = {
    { 30 , 80 , 90 , 55 , 45 , 55 , 3 , 6 , 11 }  // No.  140   // Kabuto Rock Water
};
static const char P_141[][9] = {
    { 60 , 115 , 105 , 65 , 70 , 80 , 3 , 6 , 11 }  // No.  141   // Kabutops Rock Water
};
static const char P_142[][9] = {
    { 80 , 105 , 65 , 60 , 75 , 130 , 7 , 6 , 3 },  // No.  142   // Aerodactyl Rock Flying
    { 80 , 135 , 85 , 70 , 95 , 150 , 7 , 6 , 3 }  // No.  142   // Aerodactyl Rock Flying
};
static const char P_143[][9] = {
    { 160 , 110 , 65 , 65 , 110 , 30 , 1 , 1 , 0 }  // No.  143   // Snorlax Normal
};
static const char P_144[][9] = {
    { 90 , 85 , 100 , 95 , 125 , 85 , 2 , 15 , 3 }  // No.  144   // Articuno Ice Flying
};
static const char P_145[][9] = {
    { 90 , 90 , 85 , 125 , 90 , 100 , 10 , 13 , 3 }  // No.  145   // Zapdos Electric Flying
};
static const char P_146[][9] = {
    { 90 , 100 , 90 , 125 , 85 , 90 , 10 , 10 , 3 }  // No.  146   // Moltres Fire Flying
};
static const char P_147[][9] = {
    { 41 , 64 , 45 , 50 , 50 , 50 , 2 , 16 , 0 }  // No.  147   // Dratini Dragon
};
static const char P_148[][9] = {
    { 61 , 84 , 65 , 70 , 70 , 70 , 2 , 16 , 0 }  // No.  148   // Dragonair Dragon
};
static const char P_149[][9] = {
    { 91 , 134 , 95 , 100 , 100 , 80 , 3 , 16 , 3 }  // No.  149   // Dragonite Dragon Flying
};
static const char P_150[][9] = {
    { 106 , 110 , 90 , 154 , 90 , 130 , 7 , 14 , 0 },  // No.  150   // Mewtwo Psychic
    { 106 , 190 , 100 , 154 , 100 , 130 , 7 , 14 , 0 },  // No.  150   // Mewtwo MEGA X Psychic
    { 106 , 150 , 70 , 194 , 120 , 140 , 7 , 14 , 0 }  // No.  150   // Mewtwo MEGA Y Psychic
};
static const char P_151[][9] = {
    { 100 , 100 , 100 , 100 , 100 , 100 , 6 , 14 , 0 }  // No.  151   // Mew Psychic
};
static const char P_152[][9] = {
    { 45 , 49 , 65 , 49 , 65 , 45 , 5 , 12 , 0 }  // No.  152   // Chikorita Grass
};
static const char P_153[][9] = {
    { 60 , 62 , 80 , 63 , 80 , 60 , 5 , 12 , 0 }  // No.  153   // Bayleef Grass
};
static const char P_154[][9] = {
    { 80 , 82 , 100 , 83 , 100 , 80 , 5 , 12 , 0 }  // No.  154   // Meganium Grass
};
static const char P_155[][9] = {
    { 39 , 52 , 43 , 60 , 50 , 65 , 10 , 10 , 0 }  // No.  155   // Cyndaquil Fire
};
static const char P_156[][9] = {
    { 58 , 64 , 58 , 80 , 65 , 80 , 10 , 10 , 0 }  // No.  156   // Quilava Fire
};
static const char P_157[][9] = {
    { 78 , 84 , 78 , 109 , 85 , 100 , 10 , 10 , 0 }  // No.  157   // Typhlosion Fire
};
static const char P_158[][9] = {
    { 50 , 65 , 64 , 44 , 48 , 43 , 2 , 11 , 0 }  // No.  158   // Totodile Water
};
static const char P_159[][9] = {
    { 65 , 80 , 80 , 59 , 63 , 58 , 2 , 11 , 0 }  // No.  159   // Croconaw Water
};
static const char P_160[][9] = {
    { 85 , 105 , 100 , 79 , 83 , 78 , 2 , 11 , 0 }  // No.  160   // Feraligatr Water
};
static const char P_161[][9] = {
    { 35 , 46 , 34 , 35 , 45 , 20 , 3 , 1 , 0 }  // No.  161   // Sentret Normal
};
static const char P_162[][9] = {
    { 85 , 76 , 64 , 45 , 55 , 90 , 3 , 1 , 0 }  // No.  162   // Furret Normal
};
static const char P_163[][9] = {
    { 60 , 30 , 30 , 36 , 56 , 50 , 3 , 1 , 3 }  // No.  163   // Hoothoot Normal Flying
};
static const char P_164[][9] = {
    { 100 , 50 , 50 , 86 , 96 , 70 , 3 , 1 , 3 }  // No.  164   // Noctowl Normal Flying
};
static const char P_165[][9] = {
    { 40 , 20 , 30 , 40 , 80 , 55 , 8 , 7 , 3 }  // No.  165   // Ledyba Bug Flying
};
static const char P_166[][9] = {
    { 55 , 35 , 50 , 55 , 110 , 85 , 8 , 7 , 3 }  // No.  166   // Ledian Bug Flying
};
static const char P_167[][9] = {
    { 40 , 60 , 40 , 40 , 40 , 30 , 5 , 7 , 4 }  // No.  167   // Spinarak Bug Poison
};
static const char P_168[][9] = {
    { 70 , 90 , 70 , 60 , 70 , 40 , 8 , 7 , 4 }  // No.  168   // Ariados Bug Poison
};
static const char P_169[][9] = {
    { 85 , 90 , 80 , 70 , 80 , 130 , 7 , 4 , 3 }  // No.  169   // Crobat Poison Flying
};
static const char P_170[][9] = {
    { 75 , 38 , 38 , 56 , 56 , 67 , 2 , 11 , 13 }  // No.  170   // Chinchou Water Electric
};
static const char P_171[][9] = {
    { 125 , 58 , 58 , 76 , 76 , 67 , 2 , 11 , 13 }  // No.  171   // Lanturn Water Electric
};
static const char P_172[][9] = {
    { 20 , 40 , 15 , 35 , 35 , 60 , 10 , 13 , 0 }  // No.  172   // Pichu Electric
};
static const char P_173[][9] = {
    { 50 , 25 , 28 , 45 , 55 , 15 , 6 , 18 , 0 }  // No.  173   // Cleffa Fairy
};
static const char P_174[][9] = {
    { 90 , 30 , 15 , 40 , 20 , 15 , 6 , 1 , 18 }  // No.  174   // Igglybuff Normal Fairy
};
static const char P_175[][9] = {
    { 35 , 20 , 65 , 40 , 65 , 20 , 9 , 18 , 0 }  // No.  175   // Togepi Fairy
};
static const char P_176[][9] = {
    { 55 , 40 , 85 , 80 , 105 , 40 , 9 , 18 , 3 }  // No.  176   // Togetic Fairy Flying
};
static const char P_177[][9] = {
    { 40 , 50 , 45 , 70 , 45 , 70 , 5 , 14 , 3 }  // No.  177   // Natu Psychic Flying
};
static const char P_178[][9] = {
    { 65 , 75 , 70 , 95 , 70 , 95 , 5 , 14 , 3 }  // No.  178   // Xatu Psychic Flying
};
static const char P_179[][9] = {
    { 55 , 40 , 40 , 65 , 45 , 35 , 9 , 13 , 0 }  // No.  179   // Mareep Electric
};
static const char P_180[][9] = {
    { 70 , 55 , 55 , 80 , 60 , 45 , 6 , 13 , 0 }  // No.  180   // Flaaffy Electric
};
static const char P_181[][9] = {
    { 90 , 75 , 85 , 115 , 90 , 55 , 10 , 13 , 0 },  // No.  181   // Ampharos Electric
    { 90 , 95 , 105 , 165 , 110 , 45 , 10 , 13 , 0 }  // No.  181   // Ampharos Electric
};
static const char P_182[][9] = {
    { 75 , 80 , 95 , 90 , 100 , 50 , 5 , 12 , 0 }  // No.  182   // Bellossom Grass
};
static const char P_183[][9] = {
    { 70 , 20 , 50 , 20 , 50 , 40 , 2 , 11 , 18 }  // No.  183   // Marill Water Fairy
};
static const char P_184[][9] = {
    { 100 , 50 , 80 , 60 , 80 , 50 , 2 , 11 , 18 }  // No.  184   // Azumarill Water Fairy
};
static const char P_185[][9] = {
    { 70 , 100 , 115 , 30 , 65 , 30 , 3 , 6 , 0 }  // No.  185   // Sudowoodo Rock
};
static const char P_186[][9] = {
    { 90 , 75 , 75 , 90 , 100 , 70 , 5 , 11 , 0 }  // No.  186   // Politoed Water
};
static const char P_187[][9] = {
    { 35 , 35 , 40 , 35 , 55 , 50 , 6 , 12 , 3 }  // No.  187   // Hoppip Grass Flying
};
static const char P_188[][9] = {
    { 55 , 45 , 50 , 45 , 65 , 80 , 5 , 12 , 3 }  // No.  188   // Skiploom Grass Flying
};
static const char P_189[][9] = {
    { 75 , 55 , 70 , 55 , 95 , 110 , 2 , 12 , 3 }  // No.  189   // Jumpluff Grass Flying
};
static const char P_190[][9] = {
    { 55 , 70 , 55 , 40 , 55 , 85 , 7 , 1 , 0 }  // No.  190   // Aipom Normal
};
static const char P_191[][9] = {
    { 30 , 30 , 30 , 30 , 30 , 30 , 10 , 12 , 0 }  // No.  191   // Sunkern Grass
};
static const char P_192[][9] = {
    { 75 , 75 , 55 , 105 , 85 , 30 , 10 , 12 , 0 }  // No.  192   // Sunflora Grass
};
static const char P_193[][9] = {
    { 65 , 65 , 45 , 75 , 45 , 95 , 8 , 7 , 3 }  // No.  193   // Yanma Bug Flying
};
static const char P_194[][9] = {
    { 55 , 45 , 45 , 25 , 25 , 15 , 2 , 11 , 5 }  // No.  194   // Wooper Water Ground
};
static const char P_195[][9] = {
    { 95 , 85 , 85 , 65 , 65 , 35 , 2 , 11 , 5 }  // No.  195   // Quagsire Water Ground
};
static const char P_196[][9] = {
    { 65 , 65 , 60 , 130 , 95 , 110 , 7 , 14 , 0 }  // No.  196   // Espeon Psychic
};
static const char P_197[][9] = {
    { 95 , 65 , 110 , 60 , 130 , 65 , 1 , 17 , 0 }  // No.  197   // Umbreon Dark
};
static const char P_198[][9] = {
    { 60 , 85 , 42 , 85 , 42 , 91 , 1 , 17 , 3 }  // No.  198   // Murkrow Dark Flying
};
static const char P_199[][9] = {
    { 95 , 75 , 80 , 100 , 110 , 30 , 6 , 11 , 14 }  // No.  199   // Slowking Water Psychic
};
static const char P_200[][9] = {
    { 60 , 60 , 60 , 85 , 85 , 85 , 4 , 8 , 0 }  // No.  200   // Misdreavus Ghost
};
static const char P_201[][9] = {
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 1
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 2
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 3
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 4
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 5
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 6
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 7
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 8
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 9
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 10
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 11
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 12
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 13
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 14
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 15
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 16
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 17
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 18
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 19
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 20
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 21
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 22
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 23
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 24
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 25
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 26
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 },  // No.  201   // Unown Psychic 27
    { 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 }  // No.  201   // Unown Psychic 28
};
static const char P_202[][9] = {
    { 190 , 33 , 58 , 33 , 58 , 33 , 2 , 14 , 0 }  // No.  202   // Wobbuffet Psychic
};
static const char P_203[][9] = {
    { 70 , 80 , 65 , 90 , 65 , 85 , 10 , 1 , 14 }  // No.  203   // Girafarig Normal Psychic
};
static const char P_204[][9] = {
    { 50 , 65 , 90 , 35 , 35 , 15 , 4 , 7 , 0 }  // No.  204   // Pineco Bug
};
static const char P_205[][9] = {
    { 75 , 90 , 140 , 60 , 60 , 40 , 7 , 7 , 9 }  // No.  205   // Forretress Bug Steel
};
static const char P_206[][9] = {
    { 100 , 70 , 70 , 65 , 65 , 45 , 10 , 1 , 0 }  // No.  206   // Dunsparce Normal
};
static const char P_207[][9] = {
    { 65 , 75 , 105 , 35 , 65 , 85 , 7 , 5 , 3 }  // No.  207   // Gligar Ground Flying
};
static const char P_208[][9] = {
    { 75 , 85 , 200 , 55 , 65 , 30 , 4 , 9 , 5 },  // No.  208   // Steelix Steel Ground
    { 75 , 125 , 230 , 55 , 95 , 30 , 4 , 9 , 5 }  // No.  208   // Steelix Steel Ground
};
static const char P_209[][9] = {
    { 60 , 80 , 50 , 40 , 40 , 30 , 6 , 18 , 0 }  // No.  209   // Snubbull Fairy
};
static const char P_210[][9] = {
    { 90 , 120 , 75 , 60 , 60 , 45 , 7 , 18 , 0 }  // No.  210   // Granbull Fairy
};
static const char P_211[][9] = {
    { 65 , 95 , 85 , 55 , 55 , 85 , 4 , 11 , 4 }  // No.  211   // Qwilfish Water Poison
};
static const char P_212[][9] = {
    { 70 , 130 , 100 , 55 , 80 , 65 , 8 , 7 , 9 },  // No.  212   // Scizor Bug Steel
    { 70 , 150 , 140 , 65 , 100 , 75 , 8 , 7 , 9 }  // No.  212   // Scizor Bug Steel
};
static const char P_213[][9] = {
    { 20 , 10 , 230 , 10 , 230 , 5 , 10 , 7 , 6 }  // No.  213   // Shuckle Bug Rock
};
static const char P_214[][9] = {
    { 80 , 125 , 75 , 40 , 95 , 85 , 2 , 7 , 2 },  // No.  214   // Heracross Bug Fighting
    { 80 , 185 , 115 , 40 , 105 , 75 , 2 , 7 , 2 }  // No.  214   // Heracross Bug Fighting
};
static const char P_215[][9] = {
    { 55 , 95 , 55 , 35 , 75 , 115 , 1 , 17 , 15 }  // No.  215   // Sneasel Dark Ice
};
static const char P_216[][9] = {
    { 60 , 80 , 50 , 50 , 50 , 40 , 3 , 1 , 0 }  // No.  216   // Teddiursa Normal
};
static const char P_217[][9] = {
    { 90 , 130 , 75 , 75 , 75 , 55 , 3 , 1 , 0 }  // No.  217   // Ursaring Normal
};
static const char P_218[][9] = {
    { 40 , 40 , 40 , 70 , 40 , 20 , 8 , 10 , 0 }  // No.  218   // Slugma Fire
};
static const char P_219[][9] = {
    { 60 , 50 , 120 , 90 , 80 , 30 , 8 , 10 , 6 }  // No.  219   // Magcargo Fire Rock
};
static const char P_220[][9] = {
    { 50 , 50 , 40 , 30 , 30 , 50 , 3 , 15 , 5 }  // No.  220   // Swinub Ice Ground
};
static const char P_221[][9] = {
    { 100 , 100 , 80 , 60 , 60 , 50 , 3 , 15 , 5 }  // No.  221   // Piloswine Ice Ground
};
static const char P_222[][9] = {
    { 65 , 55 , 95 , 65 , 95 , 35 , 6 , 11 , 6 }  // No.  222   // Corsola Water Rock
};
static const char P_223[][9] = {
    { 35 , 65 , 35 , 65 , 35 , 65 , 4 , 11 , 0 }  // No.  223   // Remoraid Water
};
static const char P_224[][9] = {
    { 75 , 105 , 75 , 105 , 75 , 45 , 8 , 11 , 0 }  // No.  224   // Octillery Water
};
static const char P_225[][9] = {
    { 45 , 55 , 45 , 65 , 45 , 75 , 8 , 15 , 3 }  // No.  225   // Delibird Ice Flying
};
static const char P_226[][9] = {
    { 85 , 40 , 70 , 80 , 140 , 70 , 7 , 11 , 3 }  // No.  226   // Mantine Water Flying
};
static const char P_227[][9] = {
    { 65 , 80 , 140 , 40 , 70 , 70 , 4 , 9 , 3 }  // No.  227   // Skarmory Steel Flying
};
static const char P_228[][9] = {
    { 45 , 60 , 30 , 80 , 50 , 65 , 1 , 17 , 10 }  // No.  228   // Houndour Dark Fire
};
static const char P_229[][9] = {
    { 75 , 90 , 50 , 110 , 80 , 95 , 1 , 17 , 10 },  // No.  229   // Houndoom Dark Fire
    { 75 , 90 , 90 , 140 , 90 , 115 , 1 , 17 , 10 }  // No.  229   // Houndoom Dark Fire
};
static const char P_230[][9] = {
    { 75 , 95 , 95 , 95 , 95 , 85 , 2 , 11 , 16 }  // No.  230   // Kingdra Water Dragon
};
static const char P_231[][9] = {
    { 90 , 60 , 60 , 40 , 40 , 40 , 2 , 5 , 0 }  // No.  231   // Phanpy Ground
};
static const char P_232[][9] = {
    { 90 , 120 , 120 , 60 , 60 , 50 , 4 , 5 , 0 }  // No.  232   // Donphan Ground
};
static const char P_233[][9] = {
    { 85 , 80 , 90 , 105 , 95 , 60 , 8 , 1 , 0 }  // No.  233   // Porygon2 Normal
};
static const char P_234[][9] = {
    { 73 , 95 , 62 , 85 , 65 , 85 , 3 , 1 , 0 }  // No.  234   // Stantler Normal
};
static const char P_235[][9] = {
    { 55 , 20 , 35 , 20 , 45 , 75 , 9 , 1 , 0 }  // No.  235   // Smeargle Normal
};
static const char P_236[][9] = {
    { 35 , 35 , 35 , 35 , 35 , 35 , 7 , 2 , 0 }  // No.  236   // Tyrogue Fighting
};
static const char P_237[][9] = {
    { 50 , 95 , 95 , 35 , 110 , 70 , 3 , 2 , 0 }  // No.  237   // Hitmontop Fighting
};
static const char P_238[][9] = {
    { 45 , 30 , 15 , 85 , 65 , 65 , 6 , 15 , 14 }  // No.  238   // Smoochum Ice Psychic
};
static const char P_239[][9] = {
    { 45 , 63 , 37 , 65 , 55 , 95 , 10 , 13 , 0 }  // No.  239   // Elekid Electric
};
static const char P_240[][9] = {
    { 45 , 75 , 37 , 70 , 55 , 83 , 8 , 10 , 0 }  // No.  240   // Magby Fire
};
static const char P_241[][9] = {
    { 95 , 80 , 105 , 40 , 70 , 100 , 6 , 1 , 0 }  // No.  241   // Miltank Normal
};
static const char P_242[][9] = {
    { 255 , 10 , 10 , 75 , 135 , 55 , 6 , 1 , 0 }  // No.  242   // Blissey Normal
};
static const char P_243[][9] = {
    { 90 , 85 , 75 , 115 , 100 , 115 , 10 , 13 , 0 }  // No.  243   // Raikou Electric
};
static const char P_244[][9] = {
    { 115 , 115 , 85 , 90 , 75 , 100 , 3 , 10 , 0 }  // No.  244   // Entei Fire
};
static const char P_245[][9] = {
    { 100 , 75 , 115 , 90 , 115 , 85 , 2 , 11 , 0 }  // No.  245   // Suicune Water
};
static const char P_246[][9] = {
    { 50 , 64 , 50 , 45 , 50 , 41 , 5 , 6 , 5 }  // No.  246   // Larvitar Rock Ground
};
static const char P_247[][9] = {
    { 70 , 84 , 70 , 65 , 70 , 51 , 4 , 6 , 5 }  // No.  247   // Pupitar Rock Ground
};
static const char P_248[][9] = {
    { 100 , 134 , 110 , 95 , 100 , 61 , 5 , 6 , 17 },  // No.  248   // Tyranitar Rock Dark
    { 100 , 164 , 150 , 95 , 120 , 71 , 5 , 6 , 17 }  // No.  248   // Tyranitar Rock Dark
};
static const char P_249[][9] = {
    { 106 , 90 , 130 , 90 , 154 , 110 , 9 , 14 , 3 }  // No.  249   // Lugia Psychic Flying
};
static const char P_250[][9] = {
    { 106 , 130 , 90 , 110 , 154 , 90 , 8 , 10 , 3 }  // No.  250   // Ho-Oh Fire Flying
};
static const char P_251[][9] = {
    { 100 , 100 , 100 , 100 , 100 , 100 , 5 , 14 , 12 }  // No.  251   // Celebi Psychic Grass
};
static const char P_252[][9] = {
    { 40 , 45 , 35 , 65 , 55 , 70 , 5 , 12 , 0 }  // No.  252   // Treecko Grass
};
static const char P_253[][9] = {
    { 50 , 65 , 45 , 85 , 65 , 95 , 5 , 12 , 0 }  // No.  253   // Grovyle Grass
};
static const char P_254[][9] = {
    { 70 , 85 , 65 , 105 , 85 , 120 , 5 , 12 , 0 },  // No.  254   // Sceptile Grass
    { 70 , 110 , 75 , 145 , 85 , 145 , 5 , 12 , 0 }  // No.  254   // Sceptile Grass
};
static const char P_255[][9] = {
    { 45 , 60 , 40 , 70 , 50 , 45 , 8 , 10 , 0 }  // No.  255   // Torchic Fire
};
static const char P_256[][9] = {
    { 60 , 85 , 60 , 85 , 60 , 55 , 8 , 10 , 2 }  // No.  256   // Combusken Fire Fighting
};
static const char P_257[][9] = {
    { 80 , 120 , 70 , 110 , 70 , 80 , 8 , 10 , 2 },  // No.  257   // Blaziken Fire Fighting
    { 80 , 160 , 80 , 130 , 80 , 100 , 8 , 10 , 2 }  // No.  257   // Blaziken Fire Fighting
};
static const char P_258[][9] = {
    { 50 , 70 , 50 , 50 , 50 , 40 , 2 , 11 , 0 }  // No.  258   // Mudkip Water
};
static const char P_259[][9] = {
    { 70 , 85 , 70 , 60 , 70 , 50 , 2 , 11 , 5 }  // No.  259   // Marshtomp Water Ground
};
static const char P_260[][9] = {
    { 100 , 110 , 90 , 85 , 90 , 60 , 2 , 11 , 5 },  // No.  260   // Swampert Water Ground
    { 100 , 150 , 110 , 95 , 110 , 70 , 2 , 11 , 5 }  // No.  260   // Swampert Water Ground
};
static const char P_261[][9] = {
    { 35 , 55 , 35 , 30 , 30 , 35 , 4 , 17 , 0 }  // No.  261   // Poochyena Dark
};
static const char P_262[][9] = {
    { 70 , 90 , 70 , 60 , 60 , 70 , 4 , 17 , 0 }  // No.  262   // Mightyena Dark
};
static const char P_263[][9] = {
    { 38 , 30 , 41 , 30 , 41 , 60 , 3 , 1 , 0 }  // No.  263   // Zigzagoon Normal
};
static const char P_264[][9] = {
    { 78 , 70 , 61 , 50 , 61 , 100 , 9 , 1 , 0 }  // No.  264   // Linoone Normal
};
static const char P_265[][9] = {
    { 45 , 45 , 35 , 20 , 30 , 20 , 8 , 7 , 0 }  // No.  265   // Wurmple Bug
};
static const char P_266[][9] = {
    { 50 , 35 , 55 , 25 , 25 , 15 , 9 , 7 , 0 }  // No.  266   // Silcoon Bug
};
static const char P_267[][9] = {
    { 60 , 70 , 50 , 100 , 50 , 65 , 10 , 7 , 3 }  // No.  267   // Beautifly Bug Flying
};
static const char P_268[][9] = {
    { 50 , 35 , 55 , 25 , 25 , 15 , 7 , 7 , 0 }  // No.  268   // Cascoon Bug
};
static const char P_269[][9] = {
    { 60 , 50 , 70 , 50 , 90 , 65 , 5 , 7 , 4 }  // No.  269   // Dustox Bug Poison
};
static const char P_270[][9] = {
    { 40 , 30 , 30 , 40 , 50 , 30 , 5 , 11 , 12 }  // No.  270   // Lotad Water Grass
};
static const char P_271[][9] = {
    { 60 , 50 , 50 , 60 , 70 , 50 , 5 , 11 , 12 }  // No.  271   // Lombre Water Grass
};
static const char P_272[][9] = {
    { 80 , 70 , 70 , 90 , 100 , 70 , 5 , 11 , 12 }  // No.  272   // Ludicolo Water Grass
};
static const char P_273[][9] = {
    { 40 , 40 , 50 , 30 , 30 , 30 , 3 , 12 , 0 }  // No.  273   // Seedot Grass
};
static const char P_274[][9] = {
    { 70 , 70 , 40 , 60 , 40 , 60 , 3 , 12 , 17 }  // No.  274   // Nuzleaf Grass Dark
};
static const char P_275[][9] = {
    { 90 , 100 , 60 , 90 , 60 , 80 , 3 , 12 , 17 }  // No.  275   // Shiftry Grass Dark
};
static const char P_276[][9] = {
    { 40 , 55 , 30 , 30 , 30 , 85 , 2 , 1 , 3 }  // No.  276   // Taillow Normal Flying
};
static const char P_277[][9] = {
    { 60 , 85 , 60 , 75 , 50 , 125 , 2 , 1 , 3 }  // No.  277   // Swellow Normal Flying
};
static const char P_278[][9] = {
    { 40 , 30 , 30 , 55 , 30 , 85 , 9 , 11 , 3 }  // No.  278   // Wingull Water Flying
};
static const char P_279[][9] = {
    { 60 , 50 , 100 , 95 , 70 , 65 , 10 , 11 , 3 }  // No.  279   // Pelipper Water Flying
};
static const char P_280[][9] = {
    { 28 , 25 , 25 , 45 , 35 , 40 , 9 , 14 , 18 }  // No.  280   // Ralts Psychic Fairy
};
static const char P_281[][9] = {
    { 38 , 35 , 35 , 65 , 55 , 50 , 9 , 14 , 18 }  // No.  281   // Kirlia Psychic Fairy
};
static const char P_282[][9] = {
    { 68 , 65 , 65 , 125 , 115 , 80 , 9 , 14 , 18 },  // No.  282   // Gardevoir Psychic Fairy
    { 68 , 85 , 65 , 165 , 135 , 100 , 9 , 14 , 18 }  // No.  282   // Gardevoir Psychic Fairy
};
static const char P_283[][9] = {
    { 40 , 30 , 32 , 50 , 52 , 65 , 2 , 7 , 11 }  // No.  283   // Surskit Bug Water
};
static const char P_284[][9] = {
    { 70 , 60 , 62 , 100 , 82 , 80 , 2 , 7 , 3 }  // No.  284   // Masquerain Bug Flying
};
static const char P_285[][9] = {
    { 60 , 40 , 60 , 40 , 60 , 35 , 3 , 12 , 0 }  // No.  285   // Shroomish Grass
};
static const char P_286[][9] = {
    { 60 , 130 , 80 , 60 , 60 , 70 , 5 , 12 , 2 }  // No.  286   // Breloom Grass Fighting
};
static const char P_287[][9] = {
    { 60 , 60 , 60 , 35 , 35 , 30 , 3 , 1 , 0 }  // No.  287   // Slakoth Normal
};
static const char P_288[][9] = {
    { 80 , 80 , 80 , 55 , 55 , 90 , 9 , 1 , 0 }  // No.  288   // Vigoroth Normal
};
static const char P_289[][9] = {
    { 150 , 160 , 100 , 95 , 65 , 100 , 3 , 1 , 0 }  // No.  289   // Slaking Normal
};
static const char P_290[][9] = {
    { 31 , 45 , 90 , 30 , 30 , 40 , 4 , 7 , 5 }  // No.  290   // Nincada Bug Ground
};
static const char P_291[][9] = {
    { 61 , 90 , 45 , 50 , 50 , 160 , 10 , 7 , 3 }  // No.  291   // Ninjask Bug Flying
};
static const char P_292[][9] = {
    { 1 , 90 , 45 , 30 , 30 , 40 , 3 , 7 , 8 }  // No.  292   // Shedinja Bug Ghost
};
static const char P_293[][9] = {
    { 64 , 51 , 23 , 51 , 23 , 28 , 6 , 1 , 0 }  // No.  293   // Whismur Normal
};
static const char P_294[][9] = {
    { 84 , 71 , 43 , 71 , 43 , 48 , 2 , 1 , 0 }  // No.  294   // Loudred Normal
};
static const char P_295[][9] = {
    { 104 , 91 , 63 , 91 , 73 , 68 , 2 , 1 , 0 }  // No.  295   // Exploud Normal
};
static const char P_296[][9] = {
    { 72 , 60 , 30 , 20 , 30 , 25 , 10 , 2 , 0 }  // No.  296   // Makuhita Fighting
};
static const char P_297[][9] = {
    { 144 , 120 , 60 , 40 , 60 , 50 , 3 , 2 , 0 }  // No.  297   // Hariyama Fighting
};
static const char P_298[][9] = {
    { 50 , 20 , 40 , 20 , 40 , 20 , 2 , 1 , 18 }  // No.  298   // Azurill Normal Fairy
};
static const char P_299[][9] = {
    { 30 , 45 , 135 , 45 , 90 , 30 , 4 , 6 , 0 }  // No.  299   // Nosepass Rock
};
static const char P_300[][9] = {
    { 50 , 45 , 45 , 35 , 35 , 50 , 6 , 1 , 0 }  // No.  300   // Skitty Normal
};
static const char P_301[][9] = {
    { 70 , 65 , 65 , 55 , 55 , 90 , 7 , 1 , 0 }  // No.  301   // Delcatty Normal
};
static const char P_302[][9] = {
    { 50 , 75 , 75 , 65 , 65 , 50 , 7 , 17 , 8 },  // No.  302   // Sableye Dark Ghost
    { 50 , 85 , 125 , 85 , 115 , 20 , 7 , 17 , 8 }  // No.  302   // Sableye Dark Ghost
};
static const char P_303[][9] = {
    { 50 , 85 , 85 , 55 , 55 , 50 , 1 , 9 , 18 },  // No.  303   // Mawile Steel Fairy
    { 50 , 105 , 125 , 55 , 95 , 50 , 1 , 9 , 18 }  // No.  303   // Mawile Steel Fairy
};
static const char P_304[][9] = {
    { 50 , 70 , 100 , 40 , 40 , 30 , 4 , 9 , 6 }  // No.  304   // Aron Steel Rock
};
static const char P_305[][9] = {
    { 60 , 90 , 140 , 50 , 50 , 40 , 4 , 9 , 6 }  // No.  305   // Lairon Steel Rock
};
static const char P_306[][9] = {
    { 70 , 110 , 180 , 60 , 60 , 50 , 4 , 9 , 6 },  // No.  306   // Aggron Steel Rock
    { 70 , 140 , 230 , 60 , 80 , 50 , 4 , 9 , 6 }  // No.  306   // Aggron Steel Rock
};
static const char P_307[][9] = {
    { 30 , 40 , 55 , 40 , 55 , 60 , 2 , 2 , 14 }  // No.  307   // Meditite Fighting Psychic
};
static const char P_308[][9] = {
    { 60 , 60 , 75 , 60 , 75 , 80 , 8 , 2 , 14 },  // No.  308   // Medicham Fighting Psychic
    { 60 , 100 , 85 , 80 , 85 , 100 , 8 , 2 , 14 }  // No.  308   // Medicham Fighting Psychic
};
static const char P_309[][9] = {
    { 40 , 45 , 40 , 65 , 40 , 65 , 5 , 13 , 0 }  // No.  309   // Electrike Electric
};
static const char P_310[][9] = {
    { 70 , 75 , 60 , 105 , 60 , 105 , 10 , 13 , 0 },  // No.  310   // Manectric Electric
    { 70 , 75 , 80 , 135 , 80 , 135 , 10 , 13 , 0 }  // No.  310   // Manectric Electric
};
static const char P_311[][9] = {
    { 60 , 50 , 40 , 85 , 75 , 95 , 10 , 13 , 0 }  // No.  311   // Plusle Electric
};
static const char P_312[][9] = {
    { 60 , 40 , 50 , 75 , 85 , 95 , 10 , 13 , 0 }  // No.  312   // Minun Electric
};
static const char P_313[][9] = {
    { 65 , 73 , 75 , 47 , 85 , 85 , 4 , 7 , 0 }  // No.  313   // Volbeat Bug
};
static const char P_314[][9] = {
    { 65 , 47 , 75 , 73 , 85 , 85 , 7 , 7 , 0 }  // No.  314   // Illumise Bug
};
static const char P_315[][9] = {
    { 50 , 60 , 45 , 100 , 80 , 65 , 5 , 12 , 4 }  // No.  315   // Roselia Grass Poison
};
static const char P_316[][9] = {
    { 70 , 43 , 53 , 43 , 53 , 40 , 5 , 4 , 0 }  // No.  316   // Gulpin Poison
};
static const char P_317[][9] = {
    { 100 , 73 , 83 , 73 , 83 , 55 , 7 , 4 , 0 }  // No.  317   // Swalot Poison
};
static const char P_318[][9] = {
    { 45 , 90 , 20 , 65 , 20 , 65 , 8 , 11 , 17 }  // No.  318   // Carvanha Water Dark
};
static const char P_319[][9] = {
    { 70 , 120 , 40 , 95 , 40 , 95 , 2 , 11 , 17 },  // No.  319   // Sharpedo Water Dark
    { 70 , 140 , 70 , 110 , 65 , 105 , 2 , 11 , 17 }  // No.  319   // Sharpedo Water Dark
};
static const char P_320[][9] = {
    { 130 , 70 , 35 , 70 , 35 , 60 , 2 , 11 , 0 }  // No.  320   // Wailmer Water
};
static const char P_321[][9] = {
    { 170 , 90 , 45 , 90 , 45 , 60 , 2 , 11 , 0 }  // No.  321   // Wailord Water
};
static const char P_322[][9] = {
    { 60 , 60 , 40 , 65 , 45 , 35 , 10 , 10 , 5 }  // No.  322   // Numel Fire Ground
};
static const char P_323[][9] = {
    { 70 , 100 , 70 , 105 , 75 , 40 , 8 , 10 , 5 },  // No.  323   // Camerupt Fire Ground
    { 70 , 120 , 100 , 145 , 105 , 20 , 8 , 10 , 5 }  // No.  323   // Camerupt Fire Ground
};
static const char P_324[][9] = {
    { 70 , 85 , 140 , 85 , 70 , 20 , 3 , 10 , 0 }  // No.  324   // Torkoal Fire
};
static const char P_325[][9] = {
    { 60 , 25 , 35 , 70 , 80 , 60 , 1 , 14 , 0 }  // No.  325   // Spoink Psychic
};
static const char P_326[][9] = {
    { 80 , 45 , 65 , 90 , 110 , 80 , 7 , 14 , 0 }  // No.  326   // Grumpig Psychic
};
static const char P_327[][9] = {
    { 60 , 60 , 60 , 60 , 60 , 60 , 3 , 1 , 0 }  // No.  327   // Spinda Normal
};
static const char P_328[][9] = {
    { 45 , 100 , 45 , 45 , 45 , 10 , 3 , 5 , 0 }  // No.  328   // Trapinch Ground
};
static const char P_329[][9] = {
    { 50 , 70 , 50 , 50 , 50 , 70 , 5 , 5 , 16 }  // No.  329   // Vibrava Ground Dragon
};
static const char P_330[][9] = {
    { 80 , 100 , 80 , 80 , 80 , 100 , 5 , 5 , 16 }  // No.  330   // Flygon Ground Dragon
};
static const char P_331[][9] = {
    { 50 , 85 , 40 , 85 , 40 , 35 , 5 , 12 , 0 }  // No.  331   // Cacnea Grass
};
static const char P_332[][9] = {
    { 70 , 115 , 60 , 115 , 60 , 55 , 5 , 12 , 17 }  // No.  332   // Cacturne Grass Dark
};
static const char P_333[][9] = {
    { 45 , 40 , 60 , 40 , 75 , 50 , 2 , 1 , 3 }  // No.  333   // Swablu Normal Flying
};
static const char P_334[][9] = {
    { 75 , 70 , 90 , 70 , 105 , 80 , 2 , 16 , 3 },  // No.  334   // Altaria Dragon Flying
    { 75 , 110 , 110 , 110 , 105 , 80 , 2 , 16 , 3 }  // No.  334   // Altaria Dragon Flying
};
static const char P_335[][9] = {
    { 73 , 115 , 60 , 60 , 60 , 90 , 9 , 1 , 0 }  // No.  335   // Zangoose Normal
};
static const char P_336[][9] = {
    { 73 , 100 , 60 , 100 , 60 , 65 , 1 , 4 , 0 }  // No.  336   // Seviper Poison
};
static const char P_337[][9] = {
    { 90 , 55 , 65 , 95 , 85 , 70 , 10 , 6 , 14 }  // No.  337   // Lunatone Rock Psychic
};
static const char P_338[][9] = {
    { 90 , 95 , 85 , 55 , 65 , 70 , 8 , 6 , 14 }  // No.  338   // Solrock Rock Psychic
};
static const char P_339[][9] = {
    { 50 , 48 , 43 , 46 , 41 , 60 , 4 , 11 , 5 }  // No.  339   // Barboach Water Ground
};
static const char P_340[][9] = {
    { 110 , 78 , 73 , 76 , 71 , 60 , 2 , 11 , 5 }  // No.  340   // Whiscash Water Ground
};
static const char P_341[][9] = {
    { 43 , 80 , 65 , 50 , 35 , 35 , 8 , 11 , 0 }  // No.  341   // Corphish Water
};
static const char P_342[][9] = {
    { 63 , 120 , 85 , 90 , 55 , 55 , 8 , 11 , 17 }  // No.  342   // Crawdaunt Water Dark
};
static const char P_343[][9] = {
    { 40 , 40 , 55 , 40 , 70 , 55 , 3 , 5 , 14 }  // No.  343   // Baltoy Ground Psychic
};
static const char P_344[][9] = {
    { 60 , 70 , 105 , 70 , 120 , 75 , 1 , 5 , 14 }  // No.  344   // Claydol Ground Psychic
};
static const char P_345[][9] = {
    { 66 , 41 , 77 , 61 , 87 , 23 , 7 , 6 , 12 }  // No.  345   // Lileep Rock Grass
};
static const char P_346[][9] = {
    { 86 , 81 , 97 , 81 , 107 , 43 , 5 , 6 , 12 }  // No.  346   // Cradily Rock Grass
};
static const char P_347[][9] = {
    { 45 , 95 , 50 , 40 , 50 , 75 , 4 , 6 , 7 }  // No.  347   // Anorith Rock Bug
};
static const char P_348[][9] = {
    { 75 , 125 , 100 , 70 , 80 , 45 , 4 , 6 , 7 }  // No.  348   // Armaldo Rock Bug
};
static const char P_349[][9] = {
    { 20 , 15 , 20 , 10 , 55 , 80 , 3 , 11 , 0 }  // No.  349   // Feebas Water
};
static const char P_350[][9] = {
    { 95 , 60 , 79 , 100 , 125 , 81 , 6 , 11 , 0 }  // No.  350   // Milotic Water
};
static const char P_351[][9] = {
    { 70 , 70 , 70 , 70 , 70 , 70 , 4 , 1 , 0 }, // No.  351 // Castform Normal
    { 70 , 70 , 70 , 70 , 70 , 70 , 4 , 10 , 0 },  // No.  351   // Castform Sunny Fire
    { 70 , 70 , 70 , 70 , 70 , 70 , 4 , 11 , 0 },  // No.  351   // Castform Rainy Water
    { 70 , 70 , 70 , 70 , 70 , 70 , 4 , 15 , 0 }  // No.  351   // Castform Snowy Ice
};
static const char P_352[][9] = {
    { 60 , 90 , 70 , 60 , 120 , 40 , 5 , 1 , 0 }  // No.  352   // Kecleon Normal
};
static const char P_353[][9] = {
    { 44 , 75 , 35 , 63 , 33 , 45 , 1 , 8 , 0 }  // No.  353   // Shuppet Ghost
};
static const char P_354[][9] = {
    { 64 , 115 , 65 , 83 , 63 , 65 , 1 , 8 , 0 },  // No.  354   // Banette Ghost
    { 64 , 165 , 75 , 93 , 83 , 75 , 1 , 8 , 0 }  // No.  354   // Banette Ghost
};
static const char P_355[][9] = {
    { 20 , 40 , 90 , 30 , 90 , 25 , 1 , 8 , 0 }  // No.  355   // Duskull Ghost
};
static const char P_356[][9] = {
    { 40 , 70 , 130 , 60 , 130 , 25 , 1 , 8 , 0 }  // No.  356   // Dusclops Ghost
};
static const char P_357[][9] = {
    { 99 , 68 , 83 , 72 , 87 , 51 , 5 , 12 , 3 }  // No.  357   // Tropius Grass Flying
};
static const char P_358[][9] = {
    { 75 , 50 , 80 , 95 , 90 , 65 , 2 , 14 , 0 }  // No.  358   // Chimecho Psychic
};
static const char P_359[][9] = {
    { 65 , 130 , 60 , 75 , 60 , 75 , 9 , 17 , 0 },  // No.  359   // Absol Dark
    { 65 , 150 , 60 , 115 , 60 , 115 , 9 , 17 , 0 }  // No.  359   // Absol Dark
};
static const char P_360[][9] = {
    { 95 , 23 , 48 , 23 , 48 , 23 , 2 , 14 , 0 }  // No.  360   // Wynaut Psychic
};
static const char P_361[][9] = {
    { 50 , 50 , 50 , 50 , 50 , 50 , 4 , 15 , 0 }  // No.  361   // Snorunt Ice
};
static const char P_362[][9] = {
    { 80 , 80 , 80 , 80 , 80 , 80 , 4 , 15 , 0 },  // No.  362   // Glalie Ice
    { 80 , 120 , 80 , 120 , 80 , 100 , 4 , 15 , 0 }  // No.  362   // Glalie Ice
};
static const char P_363[][9] = {
    { 70 , 40 , 50 , 55 , 50 , 25 , 2 , 15 , 11 }  // No.  363   // Spheal Ice Water
};
static const char P_364[][9] = {
    { 90 , 60 , 70 , 75 , 70 , 45 , 2 , 15 , 11 }  // No.  364   // Sealeo Ice Water
};
static const char P_365[][9] = {
    { 110 , 80 , 90 , 95 , 90 , 65 , 2 , 15 , 11 }  // No.  365   // Walrein Ice Water
};
static const char P_366[][9] = {
    { 35 , 64 , 85 , 74 , 55 , 32 , 2 , 11 , 0 }  // No.  366   // Clamperl Water
};
static const char P_367[][9] = {
    { 55 , 104 , 105 , 94 , 75 , 52 , 2 , 11 , 0 }  // No.  367   // Huntail Water
};
static const char P_368[][9] = {
    { 55 , 84 , 105 , 114 , 75 , 52 , 6 , 11 , 0 }  // No.  368   // Gorebyss Water
};
static const char P_369[][9] = {
    { 100 , 90 , 130 , 45 , 65 , 55 , 4 , 11 , 6 }  // No.  369   // Relicanth Water Rock
};
static const char P_370[][9] = {
    { 43 , 30 , 55 , 40 , 65 , 97 , 6 , 11 , 0 }  // No.  370   // Luvdisc Water
};
static const char P_371[][9] = {
    { 45 , 75 , 60 , 40 , 30 , 50 , 2 , 16 , 0 }  // No.  371   // Bagon Dragon
};
static const char P_372[][9] = {
    { 65 , 95 , 100 , 60 , 50 , 50 , 9 , 16 , 0 }  // No.  372   // Shelgon Dragon
};
static const char P_373[][9] = {
    { 95 , 135 , 80 , 110 , 80 , 100 , 2 , 16 , 3 },  // No.  373   // Salamence Dragon Flying
    { 95 , 145 , 130 , 120 , 90 , 120 , 2 , 16 , 3 }  // No.  373   // Salamence Dragon Flying
};
static const char P_374[][9] = {
    { 40 , 55 , 80 , 35 , 60 , 30 , 2 , 9 , 14 }  // No.  374   // Beldum Steel Psychic
};
static const char P_375[][9] = {
    { 60 , 75 , 100 , 55 , 80 , 50 , 2 , 9 , 14 }  // No.  375   // Metang Steel Psychic
};
static const char P_376[][9] = {
    { 80 , 135 , 130 , 95 , 90 , 70 , 2 , 9 , 14 },  // No.  376   // Metagross Steel Psychic
    { 80 , 145 , 150 , 105 , 110 , 110 , 2 , 9 , 14 }  // No.  376   // Metagross Steel Psychic
};
static const char P_377[][9] = {
    { 80 , 100 , 200 , 50 , 100 , 50 , 3 , 6 , 0 }  // No.  377   // Regirock Rock
};
static const char P_378[][9] = {
    { 80 , 50 , 100 , 100 , 200 , 50 , 2 , 15 , 0 }  // No.  378   // Regice Ice
};
static const char P_379[][9] = {
    { 80 , 75 , 150 , 75 , 150 , 50 , 4 , 9 , 0 }  // No.  379   // Registeel Steel
};
static const char P_380[][9] = {
    { 80 , 80 , 90 , 110 , 130 , 110 , 8 , 16 , 14 },  // No.  380   // Latias Dragon Psychic
    { 80 , 100 , 120 , 140 , 150 , 110 , 7 , 16 , 14 }  // No.  380   // Latias Dragon Psychic
};
static const char P_381[][9] = {
    { 80 , 90 , 80 , 130 , 110 , 110 , 2 , 16 , 14 },  // No.  381   // Latios Dragon Psychic
    { 80 , 130 , 100 , 160 , 120 , 110 , 7 , 16 , 14 }  // No.  381   // Latios Dragon Psychic
};
static const char P_382[][9] = {
    { 100 , 100 , 90 , 150 , 140 , 90 , 2 , 11 , 0 },  // No.  382   // Kyogre Water
    { 100 , 150 , 90 , 180 , 160 , 90 , 2 , 11 , 0 }  // No.  382   // Kyogre Mega Water
};
static const char P_383[][9] = {
    { 100 , 150 , 140 , 100 , 90 , 90 , 8 , 5 , 0 },  // No.  383   // Groudon Ground
    { 100 , 180 , 160 , 150 , 90 , 90 , 8 , 5 , 0 }  // No.  383   // Groudon Mega Ground
};
static const char P_384[][9] = {
    { 105 , 150 , 90 , 150 , 90 , 95 , 5 , 16 , 3 },  // No.  384   // Rayquaza Dragon Flying
    { 105 , 180 , 100 , 180 , 100 , 115 , 5 , 16 , 3 }  // No.  384   // Rayquaza Dragon Flying
};
static const char P_385[][9] = {
    { 100 , 100 , 100 , 100 , 100 , 100 , 10 , 9 , 14 }  // No.  385   // Jirachi Steel Psychic
};
static const char P_386[][9] = {
    { 50 , 150 , 50 , 150 , 50 , 150 , 8 , 14 , 0 },  // No.  386   // Deoxys Psychic Normal
    { 50 , 180 , 20 , 180 , 20 , 150 , 8 , 14 , 0 },  // No.  386   // Deoxys Psychic Attack
    { 50 , 70 , 160 , 70 , 160 , 90 , 8 , 14 , 0 },  // No.  386   // Deoxys Psychic Defense
    { 50 , 95 , 90 , 95 , 90 , 180 , 8 , 14 , 0 }  // No.  386   // Deoxys Psychic Speed
};
static const char P_387[][9] = {
    { 55 , 68 , 64 , 45 , 55 , 31 , 5 , 12 , 0 }  // No.  387   // Turtwig Grass
};
static const char P_388[][9] = {
    { 75 , 89 , 85 , 55 , 65 , 36 , 5 , 12 , 0 }  // No.  388   // Grotle Grass
};
static const char P_389[][9] = {
    { 95 , 109 , 105 , 75 , 85 , 56 , 5 , 12 , 5 }  // No.  389   // Torterra Grass Ground
};
static const char P_390[][9] = {
    { 44 , 58 , 44 , 58 , 44 , 61 , 3 , 10 , 0 }  // No.  390   // Chimchar Fire
};
static const char P_391[][9] = {
    { 64 , 78 , 52 , 78 , 52 , 81 , 3 , 10 , 2 }  // No.  391   // Monferno Fire Fighting
};
static const char P_392[][9] = {
    { 76 , 104 , 71 , 104 , 71 , 108 , 3 , 10 , 2 }  // No.  392   // Infernape Fire Fighting
};
static const char P_393[][9] = {
    { 53 , 51 , 53 , 61 , 56 , 40 , 2 , 11 , 0 }  // No.  393   // Piplup Water
};
static const char P_394[][9] = {
    { 64 , 66 , 68 , 81 , 76 , 50 , 2 , 11 , 0 }  // No.  394   // Prinplup Water
};
static const char P_395[][9] = {
    { 84 , 86 , 88 , 111 , 101 , 60 , 2 , 11 , 9 }  // No.  395   // Empoleon Water Steel
};
static const char P_396[][9] = {
    { 40 , 55 , 30 , 30 , 30 , 60 , 3 , 1 , 3 }  // No.  396   // Starly Normal Flying
};
static const char P_397[][9] = {
    { 55 , 75 , 50 , 40 , 40 , 80 , 3 , 1 , 3 }  // No.  397   // Staravia Normal Flying
};
static const char P_398[][9] = {
    { 85 , 120 , 70 , 50 , 60 , 100 , 3 , 1 , 3 }  // No.  398   // Staraptor Normal Flying
};
static const char P_399[][9] = {
    { 59 , 45 , 40 , 35 , 40 , 31 , 3 , 1 , 0 }  // No.  399   // Bidoof Normal
};
static const char P_400[][9] = {
    { 79 , 85 , 60 , 55 , 60 , 71 , 3 , 1 , 11 }  // No.  400   // Bibarel Normal Water
};
static const char P_401[][9] = {
    { 37 , 25 , 41 , 25 , 41 , 25 , 8 , 7 , 0 }  // No.  401   // Kricketot Bug
};
static const char P_402[][9] = {
    { 77 , 85 , 51 , 55 , 51 , 65 , 8 , 7 , 0 }  // No.  402   // Kricketune Bug
};
static const char P_403[][9] = {
    { 45 , 65 , 34 , 40 , 34 , 45 , 2 , 13 , 0 }  // No.  403   // Shinx Electric
};
static const char P_404[][9] = {
    { 60 , 85 , 49 , 60 , 49 , 60 , 2 , 13 , 0 }  // No.  404   // Luxio Electric
};
static const char P_405[][9] = {
    { 80 , 120 , 79 , 95 , 79 , 70 , 2 , 13 , 0 }  // No.  405   // Luxray Electric
};
static const char P_406[][9] = {
    { 40 , 30 , 35 , 50 , 70 , 55 , 5 , 12 , 4 }  // No.  406   // Budew Grass Poison
};
static const char P_407[][9] = {
    { 60 , 70 , 65 , 125 , 105 , 90 , 5 , 12 , 4 }  // No.  407   // Roserade Grass Poison
};
static const char P_408[][9] = {
    { 67 , 125 , 40 , 30 , 30 , 58 , 2 , 6 , 0 }  // No.  408   // Cranidos Rock
};
static const char P_409[][9] = {
    { 97 , 165 , 60 , 65 , 50 , 58 , 2 , 6 , 0 }  // No.  409   // Rampardos Rock
};
static const char P_410[][9] = {
    { 30 , 42 , 118 , 42 , 88 , 30 , 4 , 6 , 9 }  // No.  410   // Shieldon Rock Steel
};
static const char P_411[][9] = {
    { 60 , 52 , 168 , 47 , 138 , 30 , 4 , 6 , 9 }  // No.  411   // Bastiodon Rock Steel
};
static const char P_412[][9] = {
    { 40 , 29 , 45 , 29 , 45 , 36 , 5 , 7 , 0 },  // No.  412   // Burmy Plant Bug
    { 40 , 29 , 45 , 29 , 45 , 36 , 5 , 7 , 0 },  // No.  412   // Burmy Sandy Bug
    { 40 , 29 , 45 , 29 , 45 , 36 , 5 , 7 , 0 }  // No.  412   // Burmy Trash Bug
};
static const char P_413[][9] = {
    { 60 , 59 , 85 , 79 , 105 , 36 , 5 , 7 , 12 },  // No.  413   // Wormadam Bug Grass
    { 60 , 79 , 105 , 59 , 85 , 36 , 3 , 7 , 2 },  // No.  413   // Wormadam Bug Fighting
    { 60 , 69 , 95 , 69 , 95 , 36 , 8 , 7 , 9 }  // No.  413   // Wormadam Bug Steel
};
static const char P_414[][9] = {
    { 70 , 94 , 50 , 94 , 50 , 66 , 10 , 7 , 3 },  // No.  414   // Mothim Bug Flying
    { 70 , 94 , 50 , 94 , 50 , 66 , 10 , 7 , 3 },  // No.  414   // Mothim Bug Flying
    { 70 , 94 , 50 , 94 , 50 , 66 , 10 , 7 , 3 }  // No.  414   // Mothim Bug Flying
};
static const char P_415[][9] = {
    { 30 , 30 , 42 , 30 , 42 , 70 , 10 , 7 , 3 }  // No.  415   // Combee Bug Flying
};
static const char P_416[][9] = {
    { 70 , 80 , 102 , 80 , 102 , 40 , 10 , 7 , 3 }  // No.  416   // Vespiquen Bug Flying
};
static const char P_417[][9] = {
    { 60 , 45 , 70 , 45 , 90 , 95 , 9 , 13 , 0 }  // No.  417   // Pachirisu Electric
};
static const char P_418[][9] = {
    { 55 , 65 , 35 , 60 , 30 , 85 , 3 , 11 , 0 }  // No.  418   // Buizel Water
};
static const char P_419[][9] = {
    { 85 , 105 , 55 , 85 , 50 , 115 , 3 , 11 , 0 }  // No.  419   // Floatzel Water
};
static const char P_420[][9] = {
    { 45 , 35 , 45 , 62 , 53 , 35 , 6 , 12 , 0 }  // No.  420   // Cherubi Grass
};
static const char P_421[][9] = {
    { 70 , 60 , 70 , 87 , 78 , 85 , 7 , 12 , 0 }  // No.  421   // Cherrim Grass
};
static const char P_422[][9] = {
    { 76 , 48 , 48 , 57 , 62 , 34 , 7 , 11 , 0 },  // No.  422   // Shellos East Water
    { 76 , 48 , 48 , 57 , 62 , 34 , 7 , 11 , 0 }  // No.  422   // Shellos West Water
};
static const char P_423[][9] = {
    { 111 , 83 , 68 , 92 , 82 , 39 , 7 , 11 , 5 },  // No.  423   // Gastrodon East Water Ground
    { 111 , 83 , 68 , 92 , 82 , 39 , 7 , 11 , 5 }  // No.  423   // Gastrodon West Water Ground
};
static const char P_424[][9] = {
    { 75 , 100 , 66 , 60 , 66 , 115 , 7 , 1 , 0 }  // No.  424   // Ambipom Normal
};
static const char P_425[][9] = {
    { 90 , 50 , 34 , 60 , 44 , 70 , 7 , 8 , 3 }  // No.  425   // Drifloon Ghost Flying
};
static const char P_426[][9] = {
    { 150 , 80 , 44 , 90 , 54 , 80 , 7 , 8 , 3 }  // No.  426   // Drifblim Ghost Flying
};
static const char P_427[][9] = {
    { 55 , 66 , 44 , 44 , 56 , 85 , 3 , 1 , 0 }  // No.  427   // Buneary Normal
};
static const char P_428[][9] = {
    { 65 , 76 , 84 , 54 , 96 , 105 , 3 , 1 , 0 },  // No.  428   // Lopunny Normal
    { 65 , 136 , 94 , 54 , 96 , 135 , 3 , 1 , 0 }  // No.  428   // Lopunny Mega Normal
};
static const char P_429[][9] = {
    { 60 , 60 , 60 , 105 , 105 , 105 , 7 , 8 , 0 }  // No.  429   // Mismagius Ghost
};
static const char P_430[][9] = {
    { 100 , 125 , 52 , 105 , 52 , 71 , 1 , 17 , 3 }  // No.  430   // Honchkrow Dark Flying
};
static const char P_431[][9] = {
    { 49 , 55 , 42 , 42 , 37 , 85 , 4 , 1 , 0 }  // No.  431   // Glameow Normal
};
static const char P_432[][9] = {
    { 71 , 82 , 64 , 64 , 59 , 112 , 4 , 1 , 0 }  // No.  432   // Purugly Normal
};
static const char P_433[][9] = {
    { 45 , 30 , 50 , 65 , 50 , 45 , 10 , 14 , 0 }  // No.  433   // Chingling Psychic
};
static const char P_434[][9] = {
    { 63 , 63 , 47 , 41 , 41 , 74 , 7 , 4 , 17 }  // No.  434   // Stunky Poison Dark
};
static const char P_435[][9] = {
    { 103 , 93 , 67 , 71 , 61 , 84 , 7 , 4 , 17 }  // No.  435   // Skuntank Poison Dark
};
static const char P_436[][9] = {
    { 57 , 24 , 86 , 24 , 86 , 23 , 5 , 9 , 14 }  // No.  436   // Bronzor Steel Psychic
};
static const char P_437[][9] = {
    { 67 , 89 , 116 , 79 , 116 , 33 , 5 , 9 , 14 }  // No.  437   // Bronzong Steel Psychic
};
static const char P_438[][9] = {
    { 50 , 80 , 95 , 10 , 45 , 10 , 3 , 6 , 0 }  // No.  438   // Bonsly Rock
};
static const char P_439[][9] = {
    { 20 , 25 , 45 , 70 , 90 , 60 , 6 , 14 , 18 }  // No.  439   // Mime Jr. Psychic Fairy
};
static const char P_440[][9] = {
    { 100 , 5 , 5 , 15 , 65 , 30 , 6 , 1 , 0 }  // No.  440   // Happiny Normal
};
static const char P_441[][9] = {
    { 76 , 65 , 45 , 92 , 42 , 91 , 1 , 1 , 3 }  // No.  441   // Chatot Normal Flying
};
static const char P_442[][9] = {
    { 50 , 92 , 108 , 92 , 108 , 35 , 7 , 8 , 17 }  // No.  442   // Spiritomb Ghost Dark
};
static const char P_443[][9] = {
    { 58 , 70 , 45 , 40 , 45 , 42 , 2 , 16 , 5 }  // No.  443   // Gible Dragon Ground
};
static const char P_444[][9] = {
    { 68 , 90 , 65 , 50 , 55 , 82 , 2 , 16 , 5 }  // No.  444   // Gabite Dragon Ground
};
static const char P_445[][9] = {
    { 108 , 130 , 95 , 80 , 85 , 102 , 2 , 16 , 5 },  // No.  445   // Garchomp Dragon Ground
    { 108 , 170 , 115 , 120 , 95 , 92 , 2 , 16 , 5 }  // No.  445   // Garchomp Dragon Ground
};
static const char P_446[][9] = {
    { 135 , 85 , 40 , 40 , 85 , 5 , 1 , 1 , 0 }  // No.  446   // Munchlax Normal
};
static const char P_447[][9] = {
    { 40 , 70 , 40 , 35 , 40 , 60 , 2 , 2 , 0 }  // No.  447   // Riolu Fighting
};
static const char P_448[][9] = {
    { 70 , 110 , 70 , 115 , 70 , 90 , 2 , 2 , 9 },  // No.  448   // Lucario Fighting Steel
    { 70 , 145 , 88 , 140 , 70 , 112 , 2 , 2 , 9 }  // No.  448   // Lucario Fighting Steel
};
static const char P_449[][9] = {
    { 68 , 72 , 78 , 38 , 42 , 32 , 3 , 5 , 0 }  // No.  449   // Hippopotas Ground
};
static const char P_450[][9] = {
    { 108 , 112 , 118 , 68 , 72 , 47 , 3 , 5 , 0 }  // No.  450   // Hippowdon Ground
};
static const char P_451[][9] = {
    { 40 , 50 , 90 , 30 , 55 , 65 , 7 , 4 , 7 }  // No.  451   // Skorupi Poison Bug
};
static const char P_452[][9] = {
    { 70 , 90 , 110 , 60 , 75 , 95 , 7 , 4 , 17 }  // No.  452   // Drapion Poison Dark
};
static const char P_453[][9] = {
    { 48 , 61 , 40 , 61 , 40 , 50 , 2 , 4 , 2 }  // No.  453   // Croagunk Poison Fighting
};
static const char P_454[][9] = {
    { 83 , 106 , 65 , 86 , 65 , 85 , 2 , 4 , 2 }  // No.  454   // Toxicroak Poison Fighting
};
static const char P_455[][9] = {
    { 74 , 100 , 72 , 90 , 72 , 46 , 5 , 12 , 0 }  // No.  455   // Carnivine Grass
};
static const char P_456[][9] = {
    { 49 , 49 , 56 , 49 , 61 , 66 , 2 , 11 , 0 }  // No.  456   // Finneon Water
};
static const char P_457[][9] = {
    { 69 , 69 , 76 , 69 , 86 , 91 , 2 , 11 , 0 }  // No.  457   // Lumineon Water
};
static const char P_458[][9] = {
    { 45 , 20 , 50 , 60 , 120 , 50 , 2 , 11 , 3 }  // No.  458   // Mantyke Water Flying
};
static const char P_459[][9] = {
    { 60 , 62 , 50 , 62 , 60 , 40 , 9 , 12 , 15 }  // No.  459   // Snover Grass Ice
};
static const char P_460[][9] = {
    { 90 , 92 , 75 , 92 , 85 , 60 , 9 , 12 , 15 },  // No.  460   // Abomasnow Grass Ice
    { 90 , 132 , 105 , 132 , 105 , 30 , 9 , 12 , 15 }  // No.  460   // Abomasnow Grass Ice
};
static const char P_461[][9] = {
    { 70 , 120 , 65 , 45 , 85 , 125 , 1 , 17 , 15 }  // No.  461   // Weavile Dark Ice
};
static const char P_462[][9] = {
    { 70 , 70 , 115 , 130 , 90 , 60 , 4 , 13 , 9 }  // No.  462   // Magnezone Electric Steel
};
static const char P_463[][9] = {
    { 110 , 85 , 95 , 80 , 95 , 50 , 6 , 1 , 0 }  // No.  463   // Lickilicky Normal
};
static const char P_464[][9] = {
    { 115 , 140 , 130 , 55 , 55 , 40 , 4 , 5 , 6 }  // No.  464   // Rhyperior Ground Rock
};
static const char P_465[][9] = {
    { 100 , 100 , 125 , 110 , 50 , 50 , 2 , 12 , 0 }  // No.  465   // Tangrowth Grass
};
static const char P_466[][9] = {
    { 75 , 123 , 67 , 95 , 85 , 95 , 10 , 13 , 0 }  // No.  466   // Electivire Electric
};
static const char P_467[][9] = {
    { 75 , 95 , 67 , 125 , 95 , 83 , 8 , 10 , 0 }  // No.  467   // Magmortar Fire
};
static const char P_468[][9] = {
    { 85 , 50 , 95 , 120 , 115 , 80 , 9 , 18 , 3 }  // No.  468   // Togekiss Fairy Flying
};
static const char P_469[][9] = {
    { 86 , 76 , 86 , 116 , 56 , 95 , 5 , 7 , 3 }  // No.  469   // Yanmega Bug Flying
};
static const char P_470[][9] = {
    { 65 , 110 , 130 , 60 , 65 , 95 , 5 , 12 , 0 }  // No.  470   // Leafeon Grass
};
static const char P_471[][9] = {
    { 65 , 60 , 110 , 130 , 95 , 65 , 2 , 15 , 0 }  // No.  471   // Glaceon Ice
};
static const char P_472[][9] = {
    { 75 , 95 , 125 , 45 , 75 , 95 , 7 , 5 , 3 }  // No.  472   // Gliscor Ground Flying
};
static const char P_473[][9] = {
    { 110 , 130 , 80 , 70 , 60 , 80 , 3 , 15 , 5 }  // No.  473   // Mamoswine Ice Ground
};
static const char P_474[][9] = {
    { 85 , 80 , 70 , 135 , 75 , 90 , 8 , 1 , 0 }  // No.  474   // Porygon-Z Normal
};
static const char P_475[][9] = {
    { 68 , 125 , 65 , 65 , 115 , 80 , 9 , 14 , 2 },  // No.  475   // Gallade Psychic Fighting
    { 68 , 165 , 95 , 65 , 115 , 110 , 9 , 14 , 2 }  // No.  475   // Gallade Psychic Fighting
};
static const char P_476[][9] = {
    { 60 , 55 , 145 , 75 , 150 , 40 , 4 , 6 , 9 }  // No.  476   // Probopass Rock Steel
};
static const char P_477[][9] = {
    { 45 , 100 , 135 , 65 , 135 , 45 , 1 , 8 , 0 }  // No.  477   // Dusknoir Ghost
};
static const char P_478[][9] = {
    { 70 , 80 , 70 , 80 , 70 , 110 , 9 , 15 , 8 }  // No.  478   // Froslass Ice Ghost
};
static const char P_479[][9] = {
    { 50 , 50 , 77 , 95 , 77 , 91 , 8 , 13 , 8 },  // No.  479   // Rotom Electric Ghost
    { 50 , 65 , 107 , 105 , 107 , 86 , 8 , 13 , 10 },  // No.  479   // Rotom Electric Fire
    { 50 , 65 , 107 , 105 , 107 , 86 , 8 , 13 , 11 },  // No.  479   // Rotom Electric Water
    { 50 , 65 , 107 , 105 , 107 , 86 , 8 , 13 , 15 },  // No.  479   // Rotom Electric Ice
    { 50 , 65 , 107 , 105 , 107 , 86 , 8 , 13 , 3 },  // No.  479   // Rotom Electric Flying
    { 50 , 65 , 107 , 105 , 107 , 86 , 8 , 13 , 12 }  // No.  479   // Rotom Electric Grass
};
static const char P_480[][9] = {
    { 75 , 75 , 130 , 75 , 130 , 95 , 10 , 14 , 0 }  // No.  480   // Uxie Psychic
};
static const char P_481[][9] = {
    { 80 , 105 , 105 , 105 , 105 , 80 , 6 , 14 , 0 }  // No.  481   // Mesprit Psychic
};
static const char P_482[][9] = {
    { 75 , 125 , 70 , 125 , 70 , 115 , 2 , 14 , 0 }  // No.  482   // Azelf Psychic
};
static const char P_483[][9] = {
    { 100 , 120 , 120 , 150 , 100 , 90 , 9 , 9 , 16 }  // No.  483   // Dialga Steel Dragon
};
static const char P_484[][9] = {
    { 90 , 120 , 100 , 150 , 120 , 100 , 7 , 11 , 16 }  // No.  484   // Palkia Water Dragon
};
static const char P_485[][9] = {
    { 91 , 90 , 106 , 130 , 106 , 77 , 3 , 10 , 9 }  // No.  485   // Heatran Fire Steel
};
static const char P_486[][9] = {
    { 110 , 160 , 110 , 80 , 110 , 100 , 9 , 1 , 0 }  // No.  486   // Regigigas Normal
};
static const char P_487[][9] = {
    { 150 , 100 , 120 , 100 , 120 , 90 , 1 , 8 , 16 },  // No.  487   // Giratina Ghost Dragon
    { 150 , 120 , 100 , 120 , 100 , 90 , 1 , 8 , 16 }  // No.  487   // Giratina Origin Ghost Dragon
};
static const char P_488[][9] = {
    { 120 , 70 , 120 , 75 , 130 , 85 , 10 , 14 , 0 }  // No.  488   // Cresselia Psychic
};
static const char P_489[][9] = {
    { 80 , 80 , 80 , 80 , 80 , 80 , 2 , 11 , 0 }  // No.  489   // Phione Water
};
static const char P_490[][9] = {
    { 100 , 100 , 100 , 100 , 100 , 100 , 2 , 11 , 0 }  // No.  490   // Manaphy Water
};
static const char P_491[][9] = {
    { 70 , 90 , 90 , 135 , 90 , 125 , 1 , 17 , 0 }  // No.  491   // Darkrai Dark
};
static const char P_492[][9] = {
    { 100 , 100 , 100 , 100 , 100 , 100 , 5 , 12 , 0 },  // No.  492   // Shaymin Grass
    { 100 , 103 , 75 , 120 , 75 , 127 , 5 , 12 , 3 }  // No.  492   // Shaymin Grass Flying
};
static const char P_493[][9] = {
    { 120 , 120 , 120 , 120 , 120 , 120 , 9 , 1 , 0 },  // No.  493   // Arceus Normal    1
    { 120 , 120 , 120 , 120 , 120 , 120 , 9 , 1 , 0 },  // No.  493   // Arceus Fighting  2
    { 120 , 120 , 120 , 120 , 120 , 120 , 9 , 1 , 0 },  // No.  493   // Arceus Flying    3
    { 120 , 120 , 120 , 120 , 120 , 120 , 9 , 1 , 0 },  // No.  493   // Arceus Poison    4
    { 120 , 120 , 120 , 120 , 120 , 120 , 9 , 1 , 0 },  // No.  493   // Arceus Ground    5
    { 120 , 120 , 120 , 120 , 120 , 120 , 9 , 1 , 0 },  // No.  493   // Arceus Rock      6
    { 120 , 120 , 120 , 120 , 120 , 120 , 9 , 1 , 0 },  // No.  493   // Arceus Bug       7
    { 120 , 120 , 120 , 120 , 120 , 120 , 9 , 1 , 0 },  // No.  493   // Arceus Ghost     8
    { 120 , 120 , 120 , 120 , 120 , 120 , 9 , 1 , 0 },  // No.  493   // Arceus Steel     9
    { 120 , 120 , 120 , 120 , 120 , 120 , 9 , 1 , 0 },  // No.  493   // Arceus Fire      10
    { 120 , 120 , 120 , 120 , 120 , 120 , 9 , 1 , 0 },  // No.  493   // Arceus Water     11
    { 120 , 120 , 120 , 120 , 120 , 120 , 9 , 1 , 0 },  // No.  493   // Arceus Grass     12
    { 120 , 120 , 120 , 120 , 120 , 120 , 9 , 1 , 0 },  // No.  493   // Arceus Electric  13
    { 120 , 120 , 120 , 120 , 120 , 120 , 9 , 1 , 0 },  // No.  493   // Arceus Psychic   14
    { 120 , 120 , 120 , 120 , 120 , 120 , 9 , 1 , 0 },  // No.  493   // Arceus Ice       15
    { 120 , 120 , 120 , 120 , 120 , 120 , 9 , 1 , 0 },  // No.  493   // Arceus Dragon    16
    { 120 , 120 , 120 , 120 , 120 , 120 , 9 , 1 , 0 },  // No.  493   // Arceus Dark      17
    { 120 , 120 , 120 , 120 , 120 , 120 , 9 , 1 , 0 }  // No.  493   // Arceus Fairy     18
};
static const char P_494[][9] = {
    { 100 , 100 , 100 , 100 , 100 , 100 , 10 , 14 , 10 }  // No.  494   // Victini Psychic Fire
};
static const char P_495[][9] = {
    { 45 , 45 , 55 , 45 , 55 , 63 , 5 , 12 , 0 }  // No.  495   // Snivy Grass
};
static const char P_496[][9] = {
    { 60 , 60 , 75 , 60 , 75 , 83 , 5 , 12 , 0 }  // No.  496   // Servine Grass
};
static const char P_497[][9] = {
    { 75 , 75 , 95 , 75 , 95 , 113 , 5 , 12 , 0 }  // No.  497   // Serperior Grass
};
static const char P_498[][9] = {
    { 65 , 63 , 45 , 45 , 45 , 45 , 8 , 10 , 0 }  // No.  498   // Tepig Fire
};
static const char P_499[][9] = {
    { 90 , 93 , 55 , 70 , 55 , 55 , 8 , 10 , 2 }  // No.  499   // Pignite Fire Fighting
};
static const char P_500[][9] = {
    { 110 , 123 , 65 , 100 , 65 , 65 , 8 , 10 , 2 }  // No.  500   // Emboar Fire Fighting
};
static const char P_501[][9] = {
    { 55 , 55 , 45 , 63 , 45 , 45 , 2 , 11 , 0 }  // No.  501   // Oshawott Water
};
static const char P_502[][9] = {
    { 75 , 75 , 60 , 83 , 60 , 60 , 2 , 11 , 0 }  // No.  502   // Dewott Water
};
static const char P_503[][9] = {
    { 95 , 100 , 85 , 108 , 70 , 70 , 2 , 11 , 0 }  // No.  503   // Samurott Water
};
static const char P_504[][9] = {
    { 45 , 55 , 39 , 35 , 39 , 42 , 3 , 1 , 0 }  // No.  504   // Patrat Normal
};
static const char P_505[][9] = {
    { 60 , 85 , 69 , 60 , 69 , 77 , 3 , 1 , 0 }  // No.  505   // Watchog Normal
};
static const char P_506[][9] = {
    { 45 , 60 , 45 , 25 , 45 , 55 , 3 , 1 , 0 }  // No.  506   // Lillipup Normal
};
static const char P_507[][9] = {
    { 65 , 80 , 65 , 35 , 65 , 60 , 4 , 1 , 0 }  // No.  507   // Herdier Normal
};
static const char P_508[][9] = {
    { 85 , 110 , 90 , 45 , 90 , 80 , 4 , 1 , 0 }  // No.  508   // Stoutland Normal
};
static const char P_509[][9] = {
    { 41 , 50 , 37 , 50 , 37 , 66 , 7 , 17 , 0 }  // No.  509   // Purrloin Dark
};
static const char P_510[][9] = {
    { 64 , 88 , 50 , 88 , 50 , 106 , 7 , 17 , 0 }  // No.  510   // Liepard Dark
};
static const char P_511[][9] = {
    { 50 , 53 , 48 , 53 , 48 , 64 , 5 , 12 , 0 }  // No.  511   // Pansage Grass
};
static const char P_512[][9] = {
    { 75 , 98 , 63 , 98 , 63 , 101 , 5 , 12 , 0 }  // No.  512   // Simisage Grass
};
static const char P_513[][9] = {
    { 50 , 53 , 48 , 53 , 48 , 64 , 8 , 10 , 0 }  // No.  513   // Pansear Fire
};
static const char P_514[][9] = {
    { 75 , 98 , 63 , 98 , 63 , 101 , 8 , 10 , 0 }  // No.  514   // Simisear Fire
};
static const char P_515[][9] = {
    { 50 , 53 , 48 , 53 , 48 , 64 , 2 , 11 , 0 }  // No.  515   // Panpour Water
};
static const char P_516[][9] = {
    { 75 , 98 , 63 , 98 , 63 , 101 , 2 , 11 , 0 }  // No.  516   // Simipour Water
};
static const char P_517[][9] = {
    { 76 , 25 , 45 , 67 , 55 , 24 , 6 , 14 , 0 }  // No.  517   // Munna Psychic
};
static const char P_518[][9] = {
    { 116 , 55 , 85 , 107 , 95 , 29 , 6 , 14 , 0 }  // No.  518   // Musharna Psychic
};
static const char P_519[][9] = {
    { 50 , 55 , 50 , 36 , 30 , 43 , 4 , 1 , 3 }  // No.  519   // Pidove Normal Flying
};
static const char P_520[][9] = {
    { 62 , 77 , 62 , 50 , 42 , 65 , 4 , 1 , 3 }  // No.  520   // Tranquill Normal Flying
};
static const char P_521[][9] = {
    { 80 , 115 , 80 , 65 , 55 , 93 , 4 , 1 , 3 }  // No.  521   // Unfezant Normal Flying
};
static const char P_522[][9] = {
    { 45 , 60 , 32 , 50 , 32 , 76 , 1 , 13 , 0 }  // No.  522   // Blitzle Electric
};
static const char P_523[][9] = {
    { 75 , 100 , 63 , 80 , 63 , 116 , 1 , 13 , 0 }  // No.  523   // Zebstrika Electric
};
static const char P_524[][9] = {
    { 55 , 75 , 85 , 25 , 25 , 15 , 2 , 6 , 0 }  // No.  524   // Roggenrola Rock
};
static const char P_525[][9] = {
    { 70 , 105 , 105 , 50 , 40 , 20 , 2 , 6 , 0 }  // No.  525   // Boldore Rock
};
static const char P_526[][9] = {
    { 85 , 135 , 130 , 60 , 80 , 25 , 2 , 6 , 0 }  // No.  526   // Gigalith Rock
};
static const char P_527[][9] = {
    { 65 , 45 , 43 , 55 , 43 , 72 , 2 , 14 , 3 }  // No.  527   // Woobat Psychic Flying
};
static const char P_528[][9] = {
    { 67 , 57 , 55 , 77 , 55 , 114 , 2 , 14 , 3 }  // No.  528   // Swoobat Psychic Flying
};
static const char P_529[][9] = {
    { 60 , 85 , 40 , 30 , 45 , 68 , 4 , 5 , 0 }  // No.  529   // Drilbur Ground
};
static const char P_530[][9] = {
    { 110 , 135 , 60 , 50 , 65 , 88 , 4 , 5 , 9 }  // No.  530   // Excadrill Ground Steel
};
static const char P_531[][9] = {
    { 103 , 60 , 86 , 60 , 86 , 50 , 6 , 1 , 0 },  // No.  531   // Audino Normal
    { 103 , 60 , 126 , 80 , 126 , 50 , 9 , 1 , 0 }  // No.  531   // Audino Normal
};
static const char P_532[][9] = {
    { 75 , 80 , 55 , 25 , 35 , 35 , 4 , 2 , 0 }  // No.  532   // Timburr Fighting
};
static const char P_533[][9] = {
    { 85 , 105 , 85 , 40 , 50 , 40 , 4 , 2 , 0 }  // No.  533   // Gurdurr Fighting
};
static const char P_534[][9] = {
    { 105 , 140 , 95 , 55 , 65 , 45 , 3 , 2 , 0 }  // No.  534   // Conkeldurr Fighting
};
static const char P_535[][9] = {
    { 50 , 50 , 40 , 50 , 40 , 64 , 2 , 11 , 0 }  // No.  535   // Tympole Water
};
static const char P_536[][9] = {
    { 75 , 65 , 55 , 65 , 55 , 69 , 2 , 11 , 5 }  // No.  536   // Palpitoad Water Ground
};
static const char P_537[][9] = {
    { 105 , 95 , 75 , 85 , 75 , 74 , 2 , 11 , 5 }  // No.  537   // Seismitoad Water Ground
};
static const char P_538[][9] = {
    { 120 , 100 , 85 , 30 , 85 , 45 , 8 , 2 , 0 }  // No.  538   // Throh Fighting
};
static const char P_539[][9] = {
    { 75 , 125 , 75 , 30 , 75 , 85 , 2 , 2 , 0 }  // No.  539   // Sawk Fighting
};
static const char P_540[][9] = {
    { 45 , 53 , 70 , 40 , 60 , 42 , 10 , 7 , 12 }  // No.  540   // Sewaddle Bug Grass
};
static const char P_541[][9] = {
    { 55 , 63 , 90 , 50 , 80 , 42 , 5 , 7 , 12 }  // No.  541   // Swadloon Bug Grass
};
static const char P_542[][9] = {
    { 75 , 103 , 80 , 70 , 80 , 92 , 10 , 7 , 12 }  // No.  542   // Leavanny Bug Grass
};
static const char P_543[][9] = {
    { 30 , 45 , 59 , 30 , 39 , 57 , 8 , 7 , 4 }  // No.  543   // Venipede Bug Poison
};
static const char P_544[][9] = {
    { 40 , 55 , 99 , 40 , 79 , 47 , 4 , 7 , 4 }  // No.  544   // Whirlipede Bug Poison
};
static const char P_545[][9] = {
    { 60 , 100 , 89 , 55 , 69 , 112 , 8 , 7 , 4 }  // No.  545   // Scolipede Bug Poison
};
static const char P_546[][9] = {
    { 40 , 27 , 60 , 37 , 50 , 66 , 5 , 12 , 18 }  // No.  546   // Cottonee Grass Fairy
};
static const char P_547[][9] = {
    { 60 , 67 , 85 , 77 , 75 , 116 , 5 , 12 , 18 }  // No.  547   // Whimsicott Grass Fairy
};
static const char P_548[][9] = {
    { 45 , 35 , 50 , 70 , 50 , 30 , 5 , 12 , 0 }  // No.  548   // Petilil Grass
};
static const char P_549[][9] = {
    { 70 , 60 , 75 , 110 , 75 , 90 , 5 , 12 , 0 }  // No.  549   // Lilligant Grass
};
static const char P_550[][9] = {
    { 70 , 92 , 65 , 80 , 55 , 98 , 5 , 11 , 0 },  // No.  550   // Basculin Red Water
    { 70 , 92 , 65 , 80 , 55 , 98 , 5 , 11 , 0 }  // No.  550   // Basculin Blue Water
};
static const char P_551[][9] = {
    { 50 , 72 , 35 , 35 , 35 , 65 , 3 , 5 , 17 }  // No.  551   // Sandile Ground Dark
};
static const char P_552[][9] = {
    { 60 , 82 , 45 , 45 , 45 , 74 , 3 , 5 , 17 }  // No.  552   // Krokorok Ground Dark
};
static const char P_553[][9] = {
    { 95 , 117 , 80 , 65 , 70 , 92 , 8 , 5 , 17 }  // No.  553   // Krookodile Ground Dark
};
static const char P_554[][9] = {
    { 70 , 90 , 45 , 15 , 45 , 50 , 8 , 10 , 0 }  // No.  554   // Darumaka Fire
};
static const char P_555[][9] = {
    { 105 , 140 , 55 , 30 , 55 , 95 , 8 , 10 , 0 },  // No.  555   // Darmanitan Fire
    { 105 , 30 , 105 , 140 , 105 , 55 , 2 , 10 , 14 }  // No.  555   // Darmanitan Fire Psychic
};
static const char P_556[][9] = {
    { 75 , 86 , 67 , 106 , 67 , 60 , 5 , 12 , 0 }  // No.  556   // Maractus Grass
};
static const char P_557[][9] = {
    { 50 , 65 , 85 , 35 , 35 , 55 , 8 , 7 , 6 }  // No.  557   // Dwebble Bug Rock
};
static const char P_558[][9] = {
    { 70 , 105 , 125 , 65 , 75 , 45 , 8 , 7 , 6 }  // No.  558   // Crustle Bug Rock
};
static const char P_559[][9] = {
    { 50 , 75 , 70 , 35 , 70 , 48 , 10 , 17 , 2 }  // No.  559   // Scraggy Dark Fighting
};
static const char P_560[][9] = {
    { 65 , 90 , 115 , 45 , 115 , 58 , 8 , 17 , 2 }  // No.  560   // Scrafty Dark Fighting
};
static const char P_561[][9] = {
    { 72 , 58 , 80 , 103 , 80 , 97 , 1 , 14 , 3 }  // No.  561   // Sigilyph Psychic Flying
};
static const char P_562[][9] = {
    { 38 , 30 , 85 , 55 , 65 , 30 , 1 , 8 , 0 }  // No.  562   // Yamask Ghost
};
static const char P_563[][9] = {
    { 58 , 50 , 145 , 95 , 105 , 30 , 10 , 8 , 0 }  // No.  563   // Cofagrigus Ghost
};
static const char P_564[][9] = {
    { 54 , 78 , 103 , 53 , 45 , 22 , 2 , 11 , 6 }  // No.  564   // Tirtouga Water Rock
};
static const char P_565[][9] = {
    { 74 , 108 , 133 , 83 , 65 , 32 , 2 , 11 , 6 }  // No.  565   // Carracosta Water Rock
};
static const char P_566[][9] = {
    { 55 , 112 , 45 , 74 , 45 , 70 , 10 , 6 , 3 }  // No.  566   // Archen Rock Flying
};
static const char P_567[][9] = {
    { 75 , 140 , 65 , 112 , 65 , 110 , 10 , 6 , 3 }  // No.  567   // Archeops Rock Flying
};
static const char P_568[][9] = {
    { 50 , 50 , 62 , 40 , 62 , 65 , 5 , 4 , 0 }  // No.  568   // Trubbish Poison
};
static const char P_569[][9] = {
    { 80 , 95 , 82 , 60 , 82 , 75 , 5 , 4 , 0 }  // No.  569   // Garbodor Poison
};
static const char P_570[][9] = {
    { 40 , 65 , 40 , 80 , 40 , 65 , 4 , 17 , 0 }  // No.  570   // Zorua Dark
};
static const char P_571[][9] = {
    { 60 , 105 , 60 , 120 , 60 , 105 , 4 , 17 , 0 }  // No.  571   // Zoroark Dark
};
static const char P_572[][9] = {
    { 55 , 50 , 40 , 40 , 40 , 75 , 4 , 1 , 0 }  // No.  572   // Minccino Normal
};
static const char P_573[][9] = {
    { 75 , 95 , 60 , 65 , 60 , 115 , 4 , 1 , 0 }  // No.  573   // Cinccino Normal
};
static const char P_574[][9] = {
    { 45 , 30 , 50 , 55 , 65 , 45 , 7 , 14 , 0 }  // No.  574   // Gothita Psychic
};
static const char P_575[][9] = {
    { 60 , 45 , 70 , 75 , 85 , 55 , 7 , 14 , 0 }  // No.  575   // Gothorita Psychic
};
static const char P_576[][9] = {
    { 70 , 55 , 95 , 95 , 110 , 65 , 7 , 14 , 0 }  // No.  576   // Gothitelle Psychic
};
static const char P_577[][9] = {
    { 45 , 30 , 40 , 105 , 50 , 20 , 5 , 14 , 0 }  // No.  577   // Solosis Psychic
};
static const char P_578[][9] = {
    { 65 , 40 , 50 , 125 , 60 , 30 , 5 , 14 , 0 }  // No.  578   // Duosion Psychic
};
static const char P_579[][9] = {
    { 110 , 65 , 75 , 125 , 85 , 30 , 5 , 14 , 0 }  // No.  579   // Reuniclus Psychic
};
static const char P_580[][9] = {
    { 62 , 44 , 50 , 44 , 50 , 55 , 2 , 11 , 3 }  // No.  580   // Ducklett Water Flying
};
static const char P_581[][9] = {
    { 75 , 87 , 63 , 87 , 63 , 98 , 9 , 11 , 3 }  // No.  581   // Swanna Water Flying
};
static const char P_582[][9] = {
    { 36 , 50 , 50 , 65 , 60 , 44 , 9 , 15 , 0 }  // No.  582   // Vanillite Ice
};
static const char P_583[][9] = {
    { 51 , 65 , 65 , 80 , 75 , 59 , 9 , 15 , 0 }  // No.  583   // Vanillish Ice
};
static const char P_584[][9] = {
    { 71 , 95 , 85 , 110 , 95 , 79 , 9 , 15 , 0 }  // No.  584   // Vanilluxe Ice
};
static const char P_585[][9] = {
    { 60 , 60 , 50 , 40 , 50 , 75 , 6 , 1 , 12 },  // No.  585   // Deerling Normal Grass
    { 60 , 60 , 50 , 40 , 50 , 75 , 6 , 1 , 12 },  // No.  585   // Deerling Normal Grass
    { 60 , 60 , 50 , 40 , 50 , 75 , 6 , 1 , 12 },  // No.  585   // Deerling Normal Grass
    { 60 , 60 , 50 , 40 , 50 , 75 , 6 , 1 , 12 }  // No.  585   // Deerling Normal Grass
};
static const char P_586[][9] = {
    { 80 , 100 , 70 , 60 , 70 , 95 , 3 , 1 , 12 },  // No.  586   // Sawsbuck Normal Grass
    { 80 , 100 , 70 , 60 , 70 , 95 , 3 , 1 , 12 },  // No.  586   // Sawsbuck Normal Grass
    { 80 , 100 , 70 , 60 , 70 , 95 , 3 , 1 , 12 },  // No.  586   // Sawsbuck Normal Grass
    { 80 , 100 , 70 , 60 , 70 , 95 , 3 , 1 , 12 }  // No.  586   // Sawsbuck Normal Grass
};
static const char P_587[][9] = {
    { 55 , 75 , 60 , 75 , 60 , 103 , 9 , 13 , 3 }  // No.  587   // Emolga Electric Flying
};
static const char P_588[][9] = {
    { 50 , 75 , 45 , 40 , 45 , 60 , 2 , 7 , 0 }  // No.  588   // Karrablast Bug
};
static const char P_589[][9] = {
    { 70 , 135 , 105 , 60 , 105 , 20 , 4 , 7 , 9 }  // No.  589   // Escavalier Bug Steel
};
static const char P_590[][9] = {
    { 69 , 55 , 45 , 55 , 55 , 15 , 9 , 12 , 4 }  // No.  590   // Foongus Grass Poison
};
static const char P_591[][9] = {
    { 114 , 85 , 70 , 85 , 80 , 30 , 9 , 12 , 4 }  // No.  591   // Amoonguss Grass Poison
};
static const char P_592[][9] = {
    { 55 , 40 , 50 , 65 , 85 , 40 , 9 , 11 , 8 }  // No.  592   // Frillish Water Ghost
};
static const char P_593[][9] = {
    { 100 , 60 , 70 , 85 , 105 , 60 , 9 , 11 , 8 }  // No.  593   // Jellicent Water Ghost
};
static const char P_594[][9] = {
    { 165 , 75 , 80 , 40 , 45 , 65 , 6 , 11 , 0 }  // No.  594   // Alomomola Water
};
static const char P_595[][9] = {
    { 50 , 47 , 50 , 57 , 50 , 65 , 10 , 7 , 13 }  // No.  595   // Joltik Bug Electric
};
static const char P_596[][9] = {
    { 70 , 77 , 60 , 97 , 60 , 108 , 10 , 7 , 13 }  // No.  596   // Galvantula Bug Electric
};
static const char P_597[][9] = {
    { 44 , 50 , 91 , 24 , 86 , 10 , 4 , 12 , 9 }  // No.  597   // Ferroseed Grass Steel
};
static const char P_598[][9] = {
    { 74 , 94 , 131 , 54 , 116 , 20 , 4 , 12 , 9 }  // No.  598   // Ferrothorn Grass Steel
};
static const char P_599[][9] = {
    { 40 , 55 , 70 , 45 , 60 , 30 , 4 , 9 , 0 }  // No.  599   // Klink Steel
};
static const char P_600[][9] = {
    { 60 , 80 , 95 , 70 , 85 , 50 , 4 , 9 , 0 }  // No.  600   // Klang Steel
};
static const char P_601[][9] = {
    { 60 , 100 , 115 , 70 , 85 , 90 , 4 , 9 , 0 }  // No.  601   // Klinklang Steel
};
static const char P_602[][9] = {
    { 35 , 55 , 40 , 45 , 40 , 60 , 9 , 13 , 0 }  // No.  602   // Tynamo Electric
};
static const char P_603[][9] = {
    { 65 , 85 , 70 , 75 , 70 , 40 , 2 , 13 , 0 }  // No.  603   // Eelektrik Electric
};
static const char P_604[][9] = {
    { 85 , 115 , 80 , 105 , 80 , 50 , 2 , 13 , 0 }  // No.  604   // Eelektross Electric
};
static const char P_605[][9] = {
    { 55 , 55 , 55 , 85 , 55 , 30 , 2 , 14 , 0 }  // No.  605   // Elgyem Psychic
};
static const char P_606[][9] = {
    { 75 , 75 , 75 , 125 , 95 , 40 , 3 , 14 , 0 }  // No.  606   // Beheeyem Psychic
};
static const char P_607[][9] = {
    { 50 , 30 , 55 , 65 , 55 , 20 , 9 , 8 , 10 }  // No.  607   // Litwick Ghost Fire
};
static const char P_608[][9] = {
    { 60 , 40 , 60 , 95 , 60 , 55 , 1 , 8 , 10 }  // No.  608   // Lampent Ghost Fire
};
static const char P_609[][9] = {
    { 60 , 55 , 90 , 145 , 90 , 80 , 1 , 8 , 10 }  // No.  609   // Chandelure Ghost Fire
};
static const char P_610[][9] = {
    { 46 , 87 , 60 , 30 , 40 , 57 , 5 , 16 , 0 }  // No.  610   // Axew Dragon
};
static const char P_611[][9] = {
    { 66 , 117 , 70 , 40 , 50 , 67 , 5 , 16 , 0 }  // No.  611   // Fraxure Dragon
};
static const char P_612[][9] = {
    { 76 , 147 , 90 , 60 , 70 , 97 , 10 , 16 , 0 }  // No.  612   // Haxorus Dragon
};
static const char P_613[][9] = {
    { 55 , 70 , 40 , 60 , 40 , 40 , 9 , 15 , 0 }  // No.  613   // Cubchoo Ice
};
static const char P_614[][9] = {
    { 95 , 130 , 80 , 70 , 80 , 50 , 9 , 15 , 0 }  // No.  614   // Beartic Ice
};
static const char P_615[][9] = {
    { 80 , 50 , 50 , 95 , 135 , 105 , 2 , 15 , 0 }  // No.  615   // Cryogonal Ice
};
static const char P_616[][9] = {
    { 50 , 40 , 85 , 40 , 65 , 25 , 8 , 7 , 0 }  // No.  616   // Shelmet Bug
};
static const char P_617[][9] = {
    { 80 , 70 , 40 , 100 , 60 , 145 , 8 , 7 , 0 }  // No.  617   // Accelgor Bug
};
static const char P_618[][9] = {
    { 109 , 66 , 84 , 81 , 99 , 32 , 3 , 5 , 13 }  // No.  618   // Stunfisk Ground Electric
};
static const char P_619[][9] = {
    { 45 , 85 , 50 , 55 , 50 , 65 , 10 , 2 , 0 }  // No.  619   // Mienfoo Fighting
};
static const char P_620[][9] = {
    { 65 , 125 , 60 , 95 , 60 , 105 , 7 , 2 , 0 }  // No.  620   // Mienshao Fighting
};
static const char P_621[][9] = {
    { 77 , 120 , 90 , 60 , 90 , 48 , 8 , 16 , 0 }  // No.  621   // Druddigon Dragon
};
static const char P_622[][9] = {
    { 59 , 74 , 50 , 35 , 50 , 35 , 5 , 5 , 8 }  // No.  622   // Golett Ground Ghost
};
static const char P_623[][9] = {
    { 89 , 124 , 80 , 55 , 80 , 55 , 5 , 5 , 8 }  // No.  623   // Golurk Ground Ghost
};
static const char P_624[][9] = {
    { 45 , 85 , 70 , 40 , 40 , 60 , 8 , 17 , 9 }  // No.  624   // Pawniard Dark Steel
};
static const char P_625[][9] = {
    { 65 , 125 , 100 , 60 , 70 , 70 , 8 , 17 , 9 }  // No.  625   // Bisharp Dark Steel
};
static const char P_626[][9] = {
    { 95 , 110 , 95 , 40 , 95 , 55 , 3 , 1 , 0 }  // No.  626   // Bouffalant Normal
};
static const char P_627[][9] = {
    { 70 , 83 , 50 , 37 , 50 , 60 , 9 , 1 , 3 }  // No.  627   // Rufflet Normal Flying
};
static const char P_628[][9] = {
    { 100 , 123 , 75 , 57 , 75 , 80 , 8 , 1 , 3 }  // No.  628   // Braviary Normal Flying
};
static const char P_629[][9] = {
    { 70 , 55 , 75 , 45 , 65 , 60 , 3 , 17 , 3 }  // No.  629   // Vullaby Dark Flying
};
static const char P_630[][9] = {
    { 110 , 65 , 105 , 55 , 95 , 80 , 3 , 17 , 3 }  // No.  630   // Mandibuzz Dark Flying
};
static const char P_631[][9] = {
    { 85 , 97 , 66 , 105 , 66 , 65 , 8 , 10 , 0 }  // No.  631   // Heatmor Fire
};
static const char P_632[][9] = {
    { 58 , 109 , 112 , 48 , 48 , 109 , 4 , 7 , 9 }  // No.  632   // Durant Bug Steel
};
static const char P_633[][9] = {
    { 52 , 65 , 50 , 45 , 50 , 38 , 2 , 17 , 16 }  // No.  633   // Deino Dark Dragon
};
static const char P_634[][9] = {
    { 72 , 85 , 70 , 65 , 70 , 58 , 2 , 17 , 16 }  // No.  634   // Zweilous Dark Dragon
};
static const char P_635[][9] = {
    { 92 , 105 , 90 , 125 , 90 , 98 , 2 , 17 , 16 }  // No.  635   // Hydreigon Dark Dragon
};
static const char P_636[][9] = {
    { 55 , 85 , 55 , 50 , 55 , 60 , 9 , 7 , 10 }  // No.  636   // Larvesta Bug Fire
};
static const char P_637[][9] = {
    { 85 , 60 , 65 , 135 , 105 , 100 , 9 , 7 , 10 }  // No.  637   // Volcarona Bug Fire
};
static const char P_638[][9] = {
    { 91 , 90 , 129 , 90 , 72 , 108 , 2 , 9 , 2 }  // No.  638   // Cobalion Steel Fighting
};
static const char P_639[][9] = {
    { 91 , 129 , 90 , 72 , 90 , 108 , 4 , 6 , 2 }  // No.  639   // Terrakion Rock Fighting
};
static const char P_640[][9] = {
    { 91 , 90 , 72 , 90 , 129 , 108 , 5 , 12 , 2 }  // No.  640   // Virizion Grass Fighting
};
static const char P_641[][9] = {
    { 79 , 115 , 70 , 125 , 80 , 111 , 5 , 3 , 0 },  // No.  641   // Tornadus Flying
    { 79 , 100 , 80 , 110 , 90 , 121 , 5 , 3 , 0 }  // No.  641   // Tornadus Flying
};
static const char P_642[][9] = {
    { 79 , 115 , 70 , 125 , 80 , 111 , 2 , 13 , 3 },  // No.  642   // Thundurus Electric Flying
    { 79 , 105 , 70 , 145 , 80 , 101 , 2 , 13 , 3 }  // No.  642   // Thundurus Electric Flying
};
static const char P_643[][9] = {
    { 100 , 120 , 100 , 150 , 120 , 90 , 9 , 16 , 10 }  // No.  643   // Reshiram Dragon Fire
};
static const char P_644[][9] = {
    { 100 , 150 , 120 , 120 , 100 , 90 , 1 , 16 , 13 }  // No.  644   // Zekrom Dragon Electric
};
static const char P_645[][9] = {
    { 89 , 125 , 90 , 115 , 80 , 101 , 3 , 5 , 3 },  // No.  645   // Landorus Ground Flying
    { 89 , 145 , 90 , 105 , 80 , 91 , 3 , 5 , 3 }  // No.  645   // Landorus Ground Flying
};
static const char P_646[][9] = {
    { 125 , 130 , 90 , 130 , 90 , 95 , 4 , 16 , 15 },  // No.  646   // Kyurem Dragon Ice
    { 125 , 170 , 100 , 120 , 90 , 95 , 4 , 16 , 15 },  // No.  646   // Kyurem Dragon Ice
    { 125 , 120 , 90 , 170 , 100 , 95 , 4 , 16 , 15 }  // No.  646   // Kyurem Dragon Ice
};
static const char P_647[][9] = {
    { 91 , 72 , 90 , 129 , 90 , 108 , 10 , 11 , 2 },  // No.  647   // Keldeo Water Fighting
    { 91 , 72 , 90 , 129 , 90 , 108 , 10 , 11 , 2 }  // No.  647   // Keldeo Resolute Water Fighting
};
static const char P_648[][9] = {
    { 100 , 77 , 77 , 128 , 128 , 90 , 9 , 1 , 14 },  // No.  648   // Meloetta Normal Psychic
    { 100 , 128 , 90 , 77 , 77 , 128 , 9 , 1 , 2 }  // No.  648   // Meloetta Normal Fighting
};
static const char P_649[][9] = {
    { 71 , 120 , 95 , 120 , 95 , 99 , 7 , 7 , 9 },  // No.  649   // Genesect Bug Steel
    { 71 , 120 , 95 , 120 , 95 , 99 , 7 , 7 , 9 },  // No.  649   // Genesect Bug Steel
    { 71 , 120 , 95 , 120 , 95 , 99 , 7 , 7 , 9 },  // No.  649   // Genesect Bug Steel
    { 71 , 120 , 95 , 120 , 95 , 99 , 7 , 7 , 9 },  // No.  649   // Genesect Bug Steel
    { 71 , 120 , 95 , 120 , 95 , 99 , 7 , 7 , 9 }  // No.  649   // Genesect Bug Steel
};
static const char P_650[][9] = {
    { 56 , 61 , 65 , 48 , 45 , 38 , 5 , 12 , 0 }  // No.  650   // Chespin Grass
};
static const char P_651[][9] = {
    { 61 , 78 , 95 , 56 , 58 , 57 , 5 , 12 , 0 }  // No.  651   // Quilladin Grass
};
static const char P_652[][9] = {
    { 88 , 107 , 122 , 74 , 75 , 64 , 5 , 12 , 2 }  // No.  652   // Chesnaught Grass Fighting
};
static const char P_653[][9] = {
    { 40 , 45 , 40 , 62 , 60 , 60 , 8 , 10 , 0 }  // No.  653   // Fennekin Fire
};
static const char P_654[][9] = {
    { 59 , 59 , 58 , 90 , 70 , 73 , 8 , 10 , 0 }  // No.  654   // Braixen Fire
};
static const char P_655[][9] = {
    { 75 , 69 , 72 , 114 , 100 , 104 , 8 , 10 , 14 }  // No.  655   // Delphox Fire Psychic
};
static const char P_656[][9] = {
    { 41 , 56 , 40 , 62 , 44 , 71 , 2 , 11 , 0 }  // No.  656   // Froakie Water
};
static const char P_657[][9] = {
    { 54 , 63 , 52 , 83 , 56 , 97 , 2 , 11 , 0 }  // No.  657   // Frogadier Water
};
static const char P_658[][9] = {
    { 72 , 95 , 67 , 103 , 71 , 122 , 2 , 11 , 17 },  // No.  658   // Greninja Water Dark
    { 72 , 95 , 67 , 103 , 71 , 122 , 2 , 11 , 17 },  // No.  658   // Greninja Water Dark
    { 72 , 145 , 67 , 153 , 71 , 132 , 2 , 11 , 17 }  // No.  658   // Greninja Active Water Dark
};
static const char P_659[][9] = {
    { 38 , 36 , 38 , 32 , 36 , 57 , 3 , 1 , 0 }  // No.  659   // Bunnelby Normal
};
static const char P_660[][9] = {
    { 85 , 56 , 77 , 50 , 77 , 78 , 3 , 1 , 5 }  // No.  660   // Diggersby Normal Ground
};
static const char P_661[][9] = {
    { 45 , 50 , 43 , 40 , 38 , 62 , 8 , 1 , 3 }  // No.  661   // Fletchling Normal Flying
};
static const char P_662[][9] = {
    { 62 , 73 , 55 , 56 , 52 , 84 , 8 , 10 , 3 }  // No.  662   // Fletchinder Fire Flying
};
static const char P_663[][9] = {
    { 78 , 81 , 71 , 74 , 69 , 126 , 8 , 10 , 3 }  // No.  663   // Talonflame Fire Flying
};
static const char P_664[][9] = {
    { 38 , 35 , 40 , 27 , 25 , 35 , 1 , 7 , 0 },  // No.  664   // Scatterbug Bug 1
    { 38 , 35 , 40 , 27 , 25 , 35 , 1 , 7 , 0 },  // No.  664   // Scatterbug Bug 2
    { 38 , 35 , 40 , 27 , 25 , 35 , 1 , 7 , 0 },  // No.  664   // Scatterbug Bug 3
    { 38 , 35 , 40 , 27 , 25 , 35 , 1 , 7 , 0 },  // No.  664   // Scatterbug Bug 4
    { 38 , 35 , 40 , 27 , 25 , 35 , 1 , 7 , 0 },  // No.  664   // Scatterbug Bug 5
    { 38 , 35 , 40 , 27 , 25 , 35 , 1 , 7 , 0 },  // No.  664   // Scatterbug Bug 6
    { 38 , 35 , 40 , 27 , 25 , 35 , 1 , 7 , 0 },  // No.  664   // Scatterbug Bug 7
    { 38 , 35 , 40 , 27 , 25 , 35 , 1 , 7 , 0 },  // No.  664   // Scatterbug Bug 8
    { 38 , 35 , 40 , 27 , 25 , 35 , 1 , 7 , 0 },  // No.  664   // Scatterbug Bug 9
    { 38 , 35 , 40 , 27 , 25 , 35 , 1 , 7 , 0 },  // No.  664   // Scatterbug Bug 10
    { 38 , 35 , 40 , 27 , 25 , 35 , 1 , 7 , 0 },  // No.  664   // Scatterbug Bug 11
    { 38 , 35 , 40 , 27 , 25 , 35 , 1 , 7 , 0 },  // No.  664   // Scatterbug Bug 12
    { 38 , 35 , 40 , 27 , 25 , 35 , 1 , 7 , 0 },  // No.  664   // Scatterbug Bug 13
    { 38 , 35 , 40 , 27 , 25 , 35 , 1 , 7 , 0 },  // No.  664   // Scatterbug Bug 14
    { 38 , 35 , 40 , 27 , 25 , 35 , 1 , 7 , 0 },  // No.  664   // Scatterbug Bug 15
    { 38 , 35 , 40 , 27 , 25 , 35 , 1 , 7 , 0 },  // No.  664   // Scatterbug Bug 16
    { 38 , 35 , 40 , 27 , 25 , 35 , 1 , 7 , 0 },  // No.  664   // Scatterbug Bug 17
    { 38 , 35 , 40 , 27 , 25 , 35 , 1 , 7 , 0 },  // No.  664   // Scatterbug Bug 18
    { 38 , 35 , 40 , 27 , 25 , 35 , 1 , 7 , 0 },  // No.  664   // Scatterbug Bug 19
    { 38 , 35 , 40 , 27 , 25 , 35 , 1 , 7 , 0 }  // No.  664   // Scatterbug Bug 20
};
static const char P_665[][9] = {
    { 45 , 22 , 60 , 27 , 30 , 29 , 1 , 7 , 0 },  // No.  665   // Spewpa Bug 1
    { 45 , 22 , 60 , 27 , 30 , 29 , 1 , 7 , 0 },  // No.  665   // Spewpa Bug 2
    { 45 , 22 , 60 , 27 , 30 , 29 , 1 , 7 , 0 },  // No.  665   // Spewpa Bug 3
    { 45 , 22 , 60 , 27 , 30 , 29 , 1 , 7 , 0 },  // No.  665   // Spewpa Bug 4
    { 45 , 22 , 60 , 27 , 30 , 29 , 1 , 7 , 0 },  // No.  665   // Spewpa Bug 5
    { 45 , 22 , 60 , 27 , 30 , 29 , 1 , 7 , 0 },  // No.  665   // Spewpa Bug 6
    { 45 , 22 , 60 , 27 , 30 , 29 , 1 , 7 , 0 },  // No.  665   // Spewpa Bug 7
    { 45 , 22 , 60 , 27 , 30 , 29 , 1 , 7 , 0 },  // No.  665   // Spewpa Bug 8
    { 45 , 22 , 60 , 27 , 30 , 29 , 1 , 7 , 0 },  // No.  665   // Spewpa Bug 9
    { 45 , 22 , 60 , 27 , 30 , 29 , 1 , 7 , 0 },  // No.  665   // Spewpa Bug 10
    { 45 , 22 , 60 , 27 , 30 , 29 , 1 , 7 , 0 },  // No.  665   // Spewpa Bug 11
    { 45 , 22 , 60 , 27 , 30 , 29 , 1 , 7 , 0 },  // No.  665   // Spewpa Bug 12
    { 45 , 22 , 60 , 27 , 30 , 29 , 1 , 7 , 0 },  // No.  665   // Spewpa Bug 13
    { 45 , 22 , 60 , 27 , 30 , 29 , 1 , 7 , 0 },  // No.  665   // Spewpa Bug 14
    { 45 , 22 , 60 , 27 , 30 , 29 , 1 , 7 , 0 },  // No.  665   // Spewpa Bug 15
    { 45 , 22 , 60 , 27 , 30 , 29 , 1 , 7 , 0 },  // No.  665   // Spewpa Bug 16
    { 45 , 22 , 60 , 27 , 30 , 29 , 1 , 7 , 0 },  // No.  665   // Spewpa Bug 17
    { 45 , 22 , 60 , 27 , 30 , 29 , 1 , 7 , 0 },  // No.  665   // Spewpa Bug 18
    { 45 , 22 , 60 , 27 , 30 , 29 , 1 , 7 , 0 },  // No.  665   // Spewpa Bug 19
    { 45 , 22 , 60 , 27 , 30 , 29 , 1 , 7 , 0 }  // No.  665   // Spewpa Bug 20
};
static const char P_666[][9] = {
    { 80 , 52 , 50 , 90 , 50 , 89 , 9 , 7 , 3 },  // No.  666   // Vivillon Bug Flying 1
    { 80 , 52 , 50 , 90 , 50 , 89 , 9 , 7 , 3 },  // No.  666   // Vivillon Bug Flying 2
    { 80 , 52 , 50 , 90 , 50 , 89 , 9 , 7 , 3 },  // No.  666   // Vivillon Bug Flying 3
    { 80 , 52 , 50 , 90 , 50 , 89 , 9 , 7 , 3 },  // No.  666   // Vivillon Bug Flying 4
    { 80 , 52 , 50 , 90 , 50 , 89 , 9 , 7 , 3 },  // No.  666   // Vivillon Bug Flying 5
    { 80 , 52 , 50 , 90 , 50 , 89 , 9 , 7 , 3 },  // No.  666   // Vivillon Bug Flying 6
    { 80 , 52 , 50 , 90 , 50 , 89 , 9 , 7 , 3 },  // No.  666   // Vivillon Bug Flying 7
    { 80 , 52 , 50 , 90 , 50 , 89 , 9 , 7 , 3 },  // No.  666   // Vivillon Bug Flying 8
    { 80 , 52 , 50 , 90 , 50 , 89 , 9 , 7 , 3 },  // No.  666   // Vivillon Bug Flying 9
    { 80 , 52 , 50 , 90 , 50 , 89 , 9 , 7 , 3 },  // No.  666   // Vivillon Bug Flying 10
    { 80 , 52 , 50 , 90 , 50 , 89 , 9 , 7 , 3 },  // No.  666   // Vivillon Bug Flying 11
    { 80 , 52 , 50 , 90 , 50 , 89 , 9 , 7 , 3 },  // No.  666   // Vivillon Bug Flying 12
    { 80 , 52 , 50 , 90 , 50 , 89 , 9 , 7 , 3 },  // No.  666   // Vivillon Bug Flying 13
    { 80 , 52 , 50 , 90 , 50 , 89 , 9 , 7 , 3 },  // No.  666   // Vivillon Bug Flying 14
    { 80 , 52 , 50 , 90 , 50 , 89 , 9 , 7 , 3 },  // No.  666   // Vivillon Bug Flying 15
    { 80 , 52 , 50 , 90 , 50 , 89 , 9 , 7 , 3 },  // No.  666   // Vivillon Bug Flying 16
    { 80 , 52 , 50 , 90 , 50 , 89 , 9 , 7 , 3 },  // No.  666   // Vivillon Bug Flying 17
    { 80 , 52 , 50 , 90 , 50 , 89 , 9 , 7 , 3 },  // No.  666   // Vivillon Bug Flying 18
    { 80 , 52 , 50 , 90 , 50 , 89 , 9 , 7 , 3 },  // No.  666   // Vivillon Bug Flying 19
    { 80 , 52 , 50 , 90 , 50 , 89 , 9 , 7 , 3 }  // No.  666   // Vivillon Bug Flying 20
};
static const char P_667[][9] = {
    { 62 , 50 , 58 , 73 , 54 , 72 , 3 , 10 , 1 }  // No.  667   // Litleo Fire Normal
};
static const char P_668[][9] = {
    { 86 , 68 , 72 , 109 , 66 , 106 , 3 , 10 , 1 }  // No.  668   // Pyroar Fire Normal
};
static const char P_669[][9] = {
    { 44 , 38 , 39 , 61 , 79 , 42 , 9 , 18 , 0 },  // No.  669   // Flabébé Fairy 1
    { 44 , 38 , 39 , 61 , 79 , 42 , 9 , 18 , 0 },  // No.  669   // Flabébé Fairy 2
    { 44 , 38 , 39 , 61 , 79 , 42 , 9 , 18 , 0 },  // No.  669   // Flabébé Fairy 3
    { 44 , 38 , 39 , 61 , 79 , 42 , 9 , 18 , 0 },  // No.  669   // Flabébé Fairy 4
    { 44 , 38 , 39 , 61 , 79 , 42 , 9 , 18 , 0 }  // No.  669   // Flabébé Fairy 5
};
static const char P_670[][9] = {
    { 54 , 45 , 47 , 75 , 98 , 52 , 9 , 18 , 0 },  // No.  670   // Floette Fairy 1
    { 54 , 45 , 47 , 75 , 98 , 52 , 9 , 18 , 0 },  // No.  670   // Floette Fairy 2
    { 54 , 45 , 47 , 75 , 98 , 52 , 9 , 18 , 0 },  // No.  670   // Floette Fairy 3
    { 54 , 45 , 47 , 75 , 98 , 52 , 9 , 18 , 0 },  // No.  670   // Floette Fairy 4
    { 54 , 45 , 47 , 75 , 98 , 52 , 9 , 18 , 0 },  // No.  670   // Floette Fairy 5
    { 54 , 45 , 47 , 75 , 98 , 52 , 9 , 18 , 0 }  // No.  670   // Floette Fairy 6
};
static const char P_671[][9] = {
    { 78 , 65 , 68 , 112 , 154 , 75 , 9 , 18 , 0 },  // No.  671   // Florges Fairy 1
    { 78 , 65 , 68 , 112 , 154 , 75 , 9 , 18 , 0 },  // No.  671   // Florges Fairy 2
    { 78 , 65 , 68 , 112 , 154 , 75 , 9 , 18 , 0 },  // No.  671   // Florges Fairy 3
    { 78 , 65 , 68 , 112 , 154 , 75 , 9 , 18 , 0 },  // No.  671   // Florges Fairy 4
    { 78 , 65 , 68 , 112 , 154 , 75 , 9 , 18 , 0 }  // No.  671   // Florges Fairy 5
};
static const char P_672[][9] = {
    { 66 , 65 , 48 , 62 , 57 , 52 , 3 , 12 , 0 }  // No.  672   // Skiddo Grass
};
static const char P_673[][9] = {
    { 123 , 100 , 62 , 97 , 81 , 68 , 3 , 12 , 0 }  // No.  673   // Gogoat Grass
};
static const char P_674[][9] = {
    { 67 , 82 , 62 , 46 , 48 , 43 , 9 , 2 , 0 }  // No.  674   // Pancham Fighting
};
static const char P_675[][9] = {
    { 95 , 124 , 78 , 69 , 71 , 58 , 9 , 2 , 17 }  // No.  675   // Pangoro Fighting Dark
};
static const char P_676[][9] = {
    { 75 , 80 , 60 , 65 , 90 , 102 , 9 , 1 , 0 },  // No.  676   // Furfrou Normal  1
    { 75 , 80 , 60 , 65 , 90 , 102 , 9 , 1 , 0 },  // No.  676   // Furfrou Normal  2
    { 75 , 80 , 60 , 65 , 90 , 102 , 9 , 1 , 0 },  // No.  676   // Furfrou Normal  3
    { 75 , 80 , 60 , 65 , 90 , 102 , 9 , 1 , 0 },  // No.  676   // Furfrou Normal  4
    { 75 , 80 , 60 , 65 , 90 , 102 , 9 , 1 , 0 },  // No.  676   // Furfrou Normal  5
    { 75 , 80 , 60 , 65 , 90 , 102 , 9 , 1 , 0 },  // No.  676   // Furfrou Normal  6
    { 75 , 80 , 60 , 65 , 90 , 102 , 9 , 1 , 0 },  // No.  676   // Furfrou Normal  7
    { 75 , 80 , 60 , 65 , 90 , 102 , 9 , 1 , 0 },  // No.  676   // Furfrou Normal  8
    { 75 , 80 , 60 , 65 , 90 , 102 , 9 , 1 , 0 },  // No.  676   // Furfrou Normal  9
    { 75 , 80 , 60 , 65 , 90 , 102 , 9 , 1 , 0 }  // No.  676   // Furfrou Normal  10    
};
static const char P_677[][9] = {
    { 62 , 48 , 54 , 63 , 60 , 68 , 4 , 14 , 0 }  // No.  677   // Espurr Psychic
};
static const char P_678[][9] = {
    { 74 , 48 , 76 , 83 , 81 , 104 , 2 , 14 , 0 }  // No.  678   // Meowstic Psychic
};
static const char P_679[][9] = {
    { 45 , 80 , 100 , 35 , 37 , 28 , 3 , 9 , 8 }  // No.  679   // Honedge Steel Ghost
};
static const char P_680[][9] = {
    { 59 , 110 , 150 , 45 , 49 , 35 , 3 , 9 , 8 }  // No.  680   // Doublade Steel Ghost
};
static const char P_681[][9] = {
    { 60 , 50 , 150 , 50 , 150 , 60 , 3 , 9 , 8 },  // No.  681   // Aegislash Steel Ghost
    { 60 , 150 , 50 , 150 , 50 , 60 , 3 , 9 , 8 }  // No.  681   // Aegislash Steel Ghost
};
static const char P_682[][9] = {
    { 78 , 52 , 60 , 63 , 65 , 23 , 6 , 18 , 0 }  // No.  682   // Spritzee Fairy
};
static const char P_683[][9] = {
    { 101 , 72 , 72 , 99 , 89 , 29 , 6 , 18 , 0 }  // No.  683   // Aromatisse Fairy
};
static const char P_684[][9] = {
    { 62 , 48 , 66 , 59 , 57 , 49 , 9 , 18 , 0 }  // No.  684   // Swirlix Fairy
};
static const char P_685[][9] = {
    { 82 , 80 , 86 , 85 , 75 , 72 , 9 , 18 , 0 }  // No.  685   // Slurpuff Fairy
};
static const char P_686[][9] = {
    { 53 , 54 , 53 , 37 , 46 , 45 , 2 , 17 , 14 }  // No.  686   // Inkay Dark Psychic
};
static const char P_687[][9] = {
    { 86 , 92 , 88 , 68 , 75 , 73 , 2 , 17 , 14 }  // No.  687   // Malamar Dark Psychic
};
static const char P_688[][9] = {
    { 42 , 52 , 67 , 39 , 56 , 50 , 3 , 6 , 11 }  // No.  688   // Binacle Rock Water
};
static const char P_689[][9] = {
    { 72 , 105 , 115 , 54 , 86 , 68 , 3 , 6 , 11 }  // No.  689   // Barbaracle Rock Water
};
static const char P_690[][9] = {
    { 50 , 60 , 60 , 60 , 60 , 30 , 3 , 4 , 11 }  // No.  690   // Skrelp Poison Water
};
static const char P_691[][9] = {
    { 65 , 75 , 90 , 97 , 123 , 44 , 3 , 4 , 16 }  // No.  691   // Dragalge Poison Dragon
};
static const char P_692[][9] = {
    { 50 , 53 , 62 , 58 , 63 , 44 , 2 , 11 , 0 }  // No.  692   // Clauncher Water
};
static const char P_693[][9] = {
    { 71 , 73 , 88 , 120 , 89 , 59 , 2 , 11 , 0 }  // No.  693   // Clawitzer Water
};
static const char P_694[][9] = {
    { 44 , 38 , 33 , 61 , 43 , 70 , 10 , 13 , 1 }  // No.  694   // Helioptile Electric Normal
};
static const char P_695[][9] = {
    { 62 , 55 , 52 , 109 , 94 , 109 , 10 , 13 , 1 }  // No.  695   // Heliolisk Electric Normal
};
static const char P_696[][9] = {
    { 58 , 89 , 77 , 45 , 45 , 48 , 3 , 6 , 16 }  // No.  696   // Tyrunt Rock Dragon
};
static const char P_697[][9] = {
    { 82 , 121 , 119 , 69 , 59 , 71 , 8 , 6 , 16 }  // No.  697   // Tyrantrum Rock Dragon
};
static const char P_698[][9] = {
    { 77 , 59 , 50 , 67 , 63 , 46 , 2 , 6 , 15 }  // No.  698   // Amaura Rock Ice
};
static const char P_699[][9] = {
    { 123 , 77 , 72 , 99 , 92 , 58 , 2 , 6 , 15 }  // No.  699   // Aurorus Rock Ice
};
static const char P_700[][9] = {
    { 95 , 65 , 65 , 110 , 130 , 60 , 6 , 18 , 0 }  // No.  700   // Sylveon Fairy
};
static const char P_701[][9] = {
    { 78 , 92 , 75 , 74 , 63 , 118 , 5 , 2 , 3 }  // No.  701   // Hawlucha Fighting Flying
};
static const char P_702[][9] = {
    { 67 , 58 , 57 , 81 , 67 , 101 , 10 , 13 , 18 }  // No.  702   // Dedenne Electric Fairy
};
static const char P_703[][9] = {
    { 50 , 50 , 150 , 50 , 150 , 50 , 4 , 6 , 18 }  // No.  703   // Carbink Rock Fairy
};
static const char P_704[][9] = {
    { 45 , 50 , 35 , 55 , 75 , 40 , 7 , 16 , 0 }  // No.  704   // Goomy Dragon
};
static const char P_705[][9] = {
    { 68 , 75 , 53 , 83 , 113 , 60 , 7 , 16 , 0 }  // No.  705   // Sliggoo Dragon
};
static const char P_706[][9] = {
    { 90 , 100 , 70 , 110 , 150 , 80 , 7 , 16 , 0 }  // No.  706   // Goodra Dragon
};
static const char P_707[][9] = {
    { 57 , 80 , 91 , 80 , 87 , 75 , 4 , 9 , 18 }  // No.  707   // Klefki Steel Fairy
};
static const char P_708[][9] = {
    { 43 , 70 , 48 , 50 , 60 , 38 , 3 , 8 , 12 }  // No.  708   // Phantump Ghost Grass
};
static const char P_709[][9] = {
    { 85 , 110 , 76 , 65 , 82 , 56 , 3 , 8 , 12 }  // No.  709   // Trevenant Ghost Grass
};
static const char P_710[][9] = {
    { 44 , 66 , 70 , 44 , 55 , 56 , 3 , 8 , 12 },  // No.  710   // Pumpkaboo Ghost Grass
    { 49 , 66 , 70 , 44 , 55 , 51 , 3 , 8 , 12 },  // No.  710   // Pumpkaboo Ghost Grass
    { 54 , 66 , 70 , 44 , 55 , 46 , 3 , 8 , 12 },  // No.  710   // Pumpkaboo Ghost Grass
    { 59 , 66 , 70 , 44 , 55 , 41 , 3 , 8 , 12 }  // No.  710   // Pumpkaboo Ghost Grass
};
static const char P_711[][9] = {
    { 55 , 85 , 122 , 58 , 75 , 99 , 3 , 8 , 12 },  // No.  711   // Gourgeist Ghost Grass
    { 65 , 90 , 122 , 58 , 75 , 84 , 3 , 8 , 12 },  // No.  711   // Gourgeist Ghost Grass
    { 75 , 95 , 122 , 58 , 75 , 69 , 3 , 8 , 12 },  // No.  711   // Gourgeist Ghost Grass
    { 85 , 100 , 122 , 58 , 75 , 54 , 3 , 8 , 12 }  // No.  711   // Gourgeist Ghost Grass
};
static const char P_712[][9] = {
    { 55 , 69 , 85 , 32 , 35 , 28 , 2 , 15 , 0 }  // No.  712   // Bergmite Ice
};
static const char P_713[][9] = {
    { 95 , 117 , 184 , 44 , 46 , 28 , 2 , 15 , 0 }  // No.  713   // Avalugg Ice
};
static const char P_714[][9] = {
    { 40 , 30 , 35 , 45 , 40 , 55 , 7 , 3 , 16 }  // No.  714   // Noibat Flying Dragon
};
static const char P_715[][9] = {
    { 85 , 70 , 80 , 97 , 80 , 123 , 7 , 3 , 16 }  // No.  715   // Noivern Flying Dragon
};
static const char P_716[][9] = {
    { 126 , 131 , 95 , 131 , 98 , 99 , 2 , 18 , 0 },  // No.  716   // Xerneas Fairy
    { 126 , 131 , 95 , 131 , 98 , 99 , 2 , 18 , 0 }  // No.  716   // Xerneas Fairy
};
static const char P_717[][9] = {
    { 126 , 131 , 95 , 131 , 98 , 99 , 8 , 17 , 3 }  // No.  717   // Yveltal Dark Flying
};
static const char P_718[][9] = {
    { 108 , 100 , 121 , 81 , 95 , 95 , 5 , 16 , 5 },  // No.  718   // Zygarde Dragon Ground 50%
    {  54 , 100 , 71 , 61 , 85 , 115 , 1 , 16 , 5 }, // No.  718   // Zygarde Dragon Ground  10%
    {  54 , 100 , 71 , 61 , 85 , 115 , 1 , 16 , 5 }, // No.  718   // Zygarde Dragon Ground  10% C
    { 108 , 100 , 121 , 81 , 95 , 95 , 5 , 16 , 5 },  // No.  718   // Zygarde Dragon Ground 50% C
    { 216 , 100 , 121 , 91 , 95 , 85 , 1 , 16 , 5 }  // No.  718   // Zygarde Dragon Ground 100% C
};
static const char P_719[][9] = {
    { 50 , 100 , 150 , 100 , 150 , 50 , 6 , 6 , 18 },  // No.  719   // Diancie Rock Fairy
    { 50 , 160 , 110 , 160 , 110 , 110 , 6 , 6 , 18 }  // No.  719   // Diancie Mega Rock Fairy
};
static const char P_720[][9] = {
    { 80 , 110 , 60 , 150 , 130 , 70 , 7 , 14 , 8 },  // No.  720   // Hoopa Psychic Ghost
    { 80 , 160 , 60 , 170 , 130 , 80 , 7 , 14 , 17 }  // No.  720   // Hoopa Unbound Psychic Dark
};
static const char P_721[][9] = {
    { 80 , 110 , 120 , 130 , 90 , 70 , 3 , 10 , 11 }  // No.  721   // Volcanion Fire Water
};
static const char P_722[][9] = {
    { 68 , 55 , 55 , 50 , 50 , 42 , 3 , 12 , 3 }  // No.  722   // Rowlet Grass Flying
};
static const char P_723[][9] = {
    { 78 , 75 , 75 , 70 , 70 , 52 , 3 , 12 , 3 }  // No.  723   // Dartrix Grass Flying
};
static const char P_724[][9] = {
    { 78 , 107 , 75 , 100 , 100 , 70 , 3 , 12 , 8 }  // No.  724   // Decidueye Grass Ghost
};
static const char P_725[][9] = {
    { 45 , 65 , 40 , 60 , 40 , 70 , 8 , 10 , 0 }  // No.  725   // Litten Fire
};
static const char P_726[][9] = {
    { 65 , 85 , 50 , 80 , 50 , 90 , 8 , 10 , 0 }  // No.  726   // Torracat Fire
};
static const char P_727[][9] = {
    { 95 , 115 , 90 , 80 , 90 , 60 , 8 , 10 , 17 }  // No.  727   // Incineroar Fire Dark
};
static const char P_728[][9] = {
    { 50 , 54 , 54 , 66 , 56 , 40 , 2 , 11 , 0 }  // No.  728   // Popplio Water
};
static const char P_729[][9] = {
    { 60 , 69 , 69 , 91 , 81 , 50 , 2 , 11 , 0 }  // No.  729   // Brionne Water
};
static const char P_730[][9] = {
    { 80 , 74 , 74 , 126 , 116 , 60 , 2 , 11 , 18 }  // No.  730   // Primarina Water Fairy
};
static const char P_731[][9] = {
    { 35 , 75 , 30 , 30 , 30 , 65 , 1 , 1 , 3 }  // No.  731   // Pikipek Normal Flying
};
static const char P_732[][9] = {
    { 55 , 85 , 50 , 40 , 50 , 75 , 1 , 1 , 3 }  // No.  732   // Trumbeak Normal Flying
};
static const char P_733[][9] = {
    { 80 , 120 , 75 , 75 , 75 , 60 , 1 , 1 , 3 }  // No.  733   // Toucannon Normal Flying
};
static const char P_734[][9] = {
    { 48 , 70 , 30 , 30 , 30 , 45 , 3 , 1 , 0 }  // No.  734   // Yungoos Normal
};
static const char P_735[][9] = {
    { 88 , 110 , 60 , 55 , 60 , 45 , 3 , 1 , 0 }  // No.  735   // Gumshoos Normal
};
static const char P_736[][9] = {
    { 47 , 62 , 45 , 55 , 45 , 46 , 4 , 7 , 0 }  // No.  736   // Grubbin Bug
};
static const char P_737[][9] = {
    { 57 , 82 , 95 , 55 , 75 , 36 , 5 , 7 , 13 }  // No.  737   // Charjabug Bug Electric
};
static const char P_738[][9] = {
    { 77 , 70 , 90 , 145 , 75 , 43 , 2 , 7 , 13 }  // No.  738   // Vikavolt Bug Electric
};
static const char P_739[][9] = {
    { 47 , 82 , 57 , 42 , 47 , 63 , 7 , 2 , 0 }  // No.  739   // Crabrawler Fighting
};
static const char P_740[][9] = {
    { 97 , 132 , 77 , 62 , 67 , 43 , 9 , 2 , 15 }  // No.  740   // Crabominable Fighting Ice
};
static const char P_741[][9] = {
    { 75 , 70 , 70 , 98 , 70 , 93 , 9 , 13 , 3 },  // No.  741   // Oricorio Electric Flying
    { 75 , 70 , 70 , 98 , 70 , 93 , 7 , 10 , 3 },  // No.  741   // Oricorio Fire Flying
    { 75 , 70 , 70 , 98 , 70 , 93 , 5 , 14 , 3 },  // No.  741   // Oricorio Psychic Flying
    { 75 , 70 , 70 , 98 , 70 , 93 , 6 , 8 , 3 }  // No.  741   // Oricorio Ghost Flying
};
static const char P_742[][9] = {
    { 40 , 45 , 40 , 55 , 40 , 84 , 10 , 7 , 18 }  // No.  742   // Cutiefly Bug Fairy
};
static const char P_743[][9] = {
    { 60 , 55 , 60 , 95 , 70 , 124 , 10 , 7 , 18 }  // No.  743   // Ribombee Bug Fairy
};
static const char P_744[][9] = {
    { 45 , 65 , 40 , 30 , 40 , 60 , 3 , 6 , 0 }  // No.  744   // Rockruff Rock
};
static const char P_745[][9] = {
    { 75 , 115 , 65 , 55 , 65 , 112 , 3 , 6 , 0 },  // No.  745   // Lycanroc Rock
    { 85 , 115 , 75 , 55 , 75 , 82 , 8 , 6 , 0 }  // No.  745   // Lycanroc Rock
};
static const char P_746[][9] = {
    { 45 , 20 , 20 , 25 , 25 , 40 , 2 , 11 , 0 },  // No.  746   // Wishiwashi Water
    { 45 , 140 , 130 , 140 , 135 , 30 , 2 , 11 , 0 }  // No.  746   // Wishiwashi Water
};
static const char P_747[][9] = {
    { 50 , 53 , 62 , 43 , 52 , 45 , 2 , 4 , 11 }  // No.  747   // Mareanie Poison Water
};
static const char P_748[][9] = {
    { 50 , 63 , 152 , 53 , 142 , 35 , 2 , 4 , 11 }  // No.  748   // Toxapex Poison Water
};
static const char P_749[][9] = {
    { 70 , 100 , 70 , 45 , 55 , 45 , 3 , 5 , 0 }  // No.  749   // Mudbray Ground
};
static const char P_750[][9] = {
    { 100 , 125 , 100 , 55 , 85 , 35 , 3 , 5 , 0 }  // No.  750   // Mudsdale Ground
};
static const char P_751[][9] = {
    { 38 , 40 , 52 , 40 , 72 , 27 , 5 , 11 , 7 }  // No.  751   // Dewpider Water Bug
};
static const char P_752[][9] = {
    { 68 , 70 , 92 , 50 , 132 , 42 , 5 , 11 , 7 }  // No.  752   // Araquanid Water Bug
};
static const char P_753[][9] = {
    { 40 , 55 , 35 , 50 , 35 , 35 , 6 , 12 , 0 }  // No.  753   // Fomantis Grass
};
static const char P_754[][9] = {
    { 70 , 105 , 90 , 80 , 90 , 45 , 6 , 12 , 0 }  // No.  754   // Lurantis Grass
};
static const char P_755[][9] = {
    { 40 , 35 , 55 , 65 , 75 , 15 , 7 , 12 , 18 }  // No.  755   // Morelull Grass Fairy
};
static const char P_756[][9] = {
    { 60 , 45 , 80 , 90 , 100 , 30 , 7 , 12 , 18 }  // No.  756   // Shiinotic Grass Fairy
};
static const char P_757[][9] = {
    { 48 , 44 , 40 , 71 , 40 , 77 , 1 , 4 , 10 }  // No.  757   // Salandit Poison Fire
};
static const char P_758[][9] = {
    { 68 , 64 , 60 , 111 , 60 , 117 , 1 , 4 , 10 }  // No.  758   // Salazzle Poison Fire
};
static const char P_759[][9] = {
    { 70 , 75 , 50 , 45 , 50 , 50 , 6 , 1 , 2 }  // No.  759   // Stufful Normal Fighting
};
static const char P_760[][9] = {
    { 120 , 125 , 80 , 55 , 60 , 60 , 6 , 1 , 2 }  // No.  760   // Bewear Normal Fighting
};
static const char P_761[][9] = {
    { 42 , 30 , 38 , 30 , 38 , 32 , 7 , 12 , 0 }  // No.  761   // Bounsweet Grass
};
static const char P_762[][9] = {
    { 52 , 40 , 48 , 40 , 48 , 62 , 7 , 12 , 0 }  // No.  762   // Steenee Grass
};
static const char P_763[][9] = {
    { 72 , 120 , 98 , 50 , 98 , 72 , 7 , 12 , 0 }  // No.  763   // Tsareena Grass
};
static const char P_764[][9] = {
    { 51 , 52 , 90 , 82 , 110 , 100 , 5 , 18 , 0 }  // No.  764   // Comfey Fairy
};
static const char P_765[][9] = {
    { 90 , 60 , 80 , 90 , 110 , 60 , 9 , 1 , 14 }  // No.  765   // Oranguru Normal Psychic
};
static const char P_766[][9] = {
    { 100 , 120 , 90 , 40 , 60 , 80 , 9 , 2 , 0 }  // No.  766   // Passimian Fighting
};
static const char P_767[][9] = {
    { 25 , 35 , 40 , 20 , 30 , 80 , 4 , 7 , 11 }  // No.  767   // Wimpod Bug Water
};
static const char P_768[][9] = {
    { 75 , 125 , 140 , 60 , 90 , 40 , 4 , 7 , 11 }  // No.  768   // Golisopod Bug Water
};
static const char P_769[][9] = {
    { 55 , 55 , 80 , 70 , 45 , 15 , 3 , 8 , 5 }  // No.  769   // Sandygast Ghost Ground
};
static const char P_770[][9] = {
    { 85 , 75 , 110 , 100 , 75 , 35 , 3 , 8 , 5 }  // No.  770   // Palossand Ghost Ground
};
static const char P_771[][9] = {
    { 55 , 60 , 130 , 30 , 130 , 5 , 1 , 11 , 0 }  // No.  771   // Pyukumuku Water
};
static const char P_772[][9] = {
    { 95 , 95 , 95 , 95 , 95 , 59 , 4 , 1 , 0 }  // No.  772   // Type: Null Normal
};
static const char P_773[][9] = {
    { 95 , 95 , 95 , 95 , 95 , 95 , 4 , 1 , 0 },  // No.  773   // Silvally Normal    1
    { 95 , 95 , 95 , 95 , 95 , 95 , 4 , 1 , 0 },  // No.  773   // Silvally Fighting    2
    { 95 , 95 , 95 , 95 , 95 , 95 , 4 , 1 , 0 },  // No.  773   // Silvally Flying    3
    { 95 , 95 , 95 , 95 , 95 , 95 , 4 , 1 , 0 },  // No.  773   // Silvally Poison    4
    { 95 , 95 , 95 , 95 , 95 , 95 , 4 , 1 , 0 },  // No.  773   // Silvally Ground    5
    { 95 , 95 , 95 , 95 , 95 , 95 , 4 , 1 , 0 },  // No.  773   // Silvally Rock    6
    { 95 , 95 , 95 , 95 , 95 , 95 , 4 , 1 , 0 },  // No.  773   // Silvally Bug    7
    { 95 , 95 , 95 , 95 , 95 , 95 , 4 , 1 , 0 },  // No.  773   // Silvally Ghost    8
    { 95 , 95 , 95 , 95 , 95 , 95 , 4 , 1 , 0 },  // No.  773   // Silvally Steel    9
    { 95 , 95 , 95 , 95 , 95 , 95 , 4 , 1 , 0 },  // No.  773   // Silvally Fire    10
    { 95 , 95 , 95 , 95 , 95 , 95 , 4 , 1 , 0 },  // No.  773   // Silvally Water    11
    { 95 , 95 , 95 , 95 , 95 , 95 , 4 , 1 , 0 },  // No.  773   // Silvally Grass    12
    { 95 , 95 , 95 , 95 , 95 , 95 , 4 , 1 , 0 },  // No.  773   // Silvally Electric    13
    { 95 , 95 , 95 , 95 , 95 , 95 , 4 , 1 , 0 },  // No.  773   // Silvally Psychic    14
    { 95 , 95 , 95 , 95 , 95 , 95 , 4 , 1 , 0 },  // No.  773   // Silvally Ice    15
    { 95 , 95 , 95 , 95 , 95 , 95 , 4 , 1 , 0 },  // No.  773   // Silvally Dragon    16
    { 95 , 95 , 95 , 95 , 95 , 95 , 4 , 1 , 0 },  // No.  773   // Silvally Dark    17
    { 95 , 95 , 95 , 95 , 95 , 95 , 4 , 1 , 0 }   // No.  773   // Silvally Fairy    18
};
static const char P_774[][9] = {
    { 60 , 60 , 100 , 60 , 100 , 60 , 3 , 6 , 3 },   // No.  774   // Minior Meteor Rock Flying 1
    { 60 , 60 , 100 , 60 , 100 , 60 , 3 , 6 , 3 },   // No.  774   // Minior Meteor Rock Flying 2
    { 60 , 60 , 100 , 60 , 100 , 60 , 3 , 6 , 3 },   // No.  774   // Minior Meteor Rock Flying 3
    { 60 , 60 , 100 , 60 , 100 , 60 , 3 , 6 , 3 },   // No.  774   // Minior Meteor Rock Flying 4
    { 60 , 60 , 100 , 60 , 100 , 60 , 3 , 6 , 3 },   // No.  774   // Minior Meteor Rock Flying 5
    { 60 , 60 , 100 , 60 , 100 , 60 , 3 , 6 , 3 },   // No.  774   // Minior Meteor Rock Flying 6
    { 60 , 60 , 100 , 60 , 100 , 60 , 3 , 6 , 3 },   // No.  774   // Minior Meteor Rock Flying 7
    { 60 , 100 , 60 , 100 , 60 , 120 , 3 , 6 , 3 },  // No.  774   // Minior Core Rock Flying 1
    { 60 , 100 , 60 , 100 , 60 , 120 , 3 , 6 , 3 },  // No.  774   // Minior Core Rock Flying 2
    { 60 , 100 , 60 , 100 , 60 , 120 , 3 , 6 , 3 },  // No.  774   // Minior Core Rock Flying 3
    { 60 , 100 , 60 , 100 , 60 , 120 , 3 , 6 , 3 },  // No.  774   // Minior Core Rock Flying 4
    { 60 , 100 , 60 , 100 , 60 , 120 , 3 , 6 , 3 },  // No.  774   // Minior Core Rock Flying 5
    { 60 , 100 , 60 , 100 , 60 , 120 , 3 , 6 , 3 },  // No.  774   // Minior Core Rock Flying 6
    { 60 , 100 , 60 , 100 , 60 , 120 , 3 , 6 , 3 }   // No.  774   // Minior Core Rock Flying 7
};
static const char P_775[][9] = {
    { 65 , 115 , 65 , 75 , 95 , 65 , 2 , 1 , 0 }  // No.  775   // Komala Normal
};
static const char P_776[][9] = {
    { 60 , 78 , 135 , 91 , 85 , 36 , 8 , 10 , 16 }  // No.  776   // Turtonator Fire Dragon
};
static const char P_777[][9] = {
    { 65 , 98 , 63 , 40 , 73 , 96 , 4 , 13 , 9 }  // No.  777   // Togedemaru Electric Steel
};
static const char P_778[][9] = {
    { 55 , 90 , 80 , 50 , 105 , 96 , 10 , 8 , 18 },  // No.  778   // Mimikyu Disguised Ghost Fairy
    { 55 , 90 , 80 , 50 , 105 , 96 , 10 , 8 , 18 }   // No.  778   // Mimikyu Busted Ghost Fairy
};
static const char P_779[][9] = {
    { 68 , 105 , 70 , 70 , 70 , 92 , 6 , 11 , 14 }  // No.  779   // Bruxish Water Psychic
};
static const char P_780[][9] = {
    { 78 , 60 , 85 , 135 , 91 , 36 , 9 , 1 , 16 }  // No.  780   // Drampa Normal Dragon
};
static const char P_781[][9] = {
    { 70 , 131 , 100 , 86 , 90 , 40 , 5 , 8 , 12 }  // No.  781   // Dhelmise Ghost Grass
};
static const char P_782[][9] = {
    { 45 , 55 , 65 , 45 , 45 , 45 , 4 , 16 , 0 }  // No.  782   // Jangmo-o Dragon
};
static const char P_783[][9] = {
    { 55 , 75 , 90 , 65 , 70 , 65 , 4 , 16 , 2 }  // No.  783   // Hakamo-o Dragon Fighting
};
static const char P_784[][9] = {
    { 75 , 110 , 125 , 100 , 105 , 85 , 4 , 16 , 2 }  // No.  784   // Kommo-o Dragon Fighting
};
static const char P_785[][9] = {
    { 70 , 115 , 85 , 95 , 75 , 130 , 10 , 13 , 18 }  // No.  785   // Tapu Koko Electric Fairy
};
static const char P_786[][9] = {
    { 70 , 85 , 75 , 130 , 115 , 95 , 6 , 14 , 18 }  // No.  786   // Tapu Lele Psychic Fairy
};
static const char P_787[][9] = {
    { 70 , 130 , 115 , 85 , 95 , 75 , 8 , 12 , 18 }  // No.  787   // Tapu Bulu Grass Fairy
};
static const char P_788[][9] = {
    { 70 , 75 , 115 , 95 , 130 , 85 , 7 , 11 , 18 }  // No.  788   // Tapu Fini Water Fairy
};
static const char P_789[][9] = {
    { 43 , 29 , 31 , 29 , 31 , 37 , 2 , 14 , 0 }  // No.  789   // Cosmog Psychic
};
static const char P_790[][9] = {
    { 43 , 29 , 131 , 29 , 131 , 37 , 2 , 14 , 0 }  // No.  790   // Cosmoem Psychic
};
static const char P_791[][9] = {
    { 137 , 137 , 107 , 113 , 89 , 97 , 9 , 14 , 9 }  // No.  791   // Solgaleo Psychic Steel
};
static const char P_792[][9] = {
    { 137 , 113 , 89 , 137 , 107 , 97 , 7 , 14 , 8 }  // No.  792   // Lunala Psychic Ghost
};
static const char P_793[][9] = {
    { 109 , 53 , 47 , 127 , 131 , 103 , 9 , 6 , 4 }  // No.  793   // Nihilego Rock Poison
};
static const char P_794[][9] = {
    { 107 , 139 , 139 , 53 , 53 , 79 , 8 , 7 , 2 }  // No.  794   // Buzzwole Bug Fighting
};
static const char P_795[][9] = {
    { 71 , 137 , 37 , 137 , 37 , 151 , 9 , 7 , 2 }  // No.  795   // Pheromosa Bug Fighting
};
static const char P_796[][9] = {
    { 83 , 89 , 71 , 173 , 71 , 83 , 1 , 13 , 0 }  // No.  796   // Xurkitree Electric
};
static const char P_797[][9] = {
    { 97 , 101 , 103 , 107 , 101 , 61 , 5 , 9 , 3 }  // No.  797   // Celesteela Steel Flying
};
static const char P_798[][9] = {
    { 59 , 181 , 131 , 59 , 31 , 109 , 9 , 12 , 9 }  // No.  798   // Kartana Grass Steel
};
static const char P_799[][9] = {
    { 223 , 101 , 53 , 97 , 53 , 43 , 1 , 17 , 16 }  // No.  799   // Guzzlord Dark Dragon
};
static const char P_800[][9] = {
    { 97 , 107 , 101 , 127 , 89 , 79 , 1 , 14 , 0 }  // No.  800   // Necrozma Psychic
};
static const char P_801[][9] = {
    { 80 , 95 , 115 , 130 , 115 , 65 , 4 , 9 , 18 },  // No.  801   // Magearna Steel Fairy
    { 80 , 95 , 115 , 130 , 115 , 65 , 4 , 9 , 18 }   // No.  801   // Magearna Original Steel Fairy
};
static const char P_802[][9] = {
    { 90 , 125 , 80 , 90 , 90 , 125 , 4 , 2 , 8 }  // No.  802   // Marshadow Fighting Ghost
};



// NATURE BENEFITS TABLES
static const char *NATURE_PLUS[] = {
    "", "ATK", "ATK", "ATK", "ATK", "DEF", "", "DEF", "DEF", "DEF", "SPE", "SPE",
    "", "SPE", "SPE", "SpA", "SpA", "SpA", "", "SpA", "SpD", "SpD", "SpD", "SpD", ""
};
static const char *NATURE_MINUS[] = {
    "", "DEF", "SPE", "SpA", "SpD", "ATK", "", "SPE", "SpA", "SpD", "ATK", "DEF",
    "", "SpA", "SpD", "ATK", "DEF", "SPE", "", "SpD", "ATK", "DEF", "SPE", "SpA", ""
};

static const u8 *PK_LOOKUP[802] = {
    (u8*)P_001,(u8*)P_002,(u8*)P_003,(u8*)P_004,(u8*)P_005,(u8*)P_006,(u8*)P_007,(u8*)P_008,(u8*)P_009,(u8*)P_010,(u8*)P_011,(u8*)P_012,(u8*)P_013,(u8*)P_014,(u8*)P_015,(u8*)P_016,(u8*)P_017,(u8*)P_018,(u8*)P_019,(u8*)P_020,
    (u8*)P_021,(u8*)P_022,(u8*)P_023,(u8*)P_024,(u8*)P_025,(u8*)P_026,(u8*)P_027,(u8*)P_028,(u8*)P_029,(u8*)P_030,(u8*)P_031,(u8*)P_032,(u8*)P_033,(u8*)P_034,(u8*)P_035,(u8*)P_036,(u8*)P_037,(u8*)P_038,(u8*)P_039,(u8*)P_040,
    (u8*)P_041,(u8*)P_042,(u8*)P_043,(u8*)P_044,(u8*)P_045,(u8*)P_046,(u8*)P_047,(u8*)P_048,(u8*)P_049,(u8*)P_050,(u8*)P_051,(u8*)P_052,(u8*)P_053,(u8*)P_054,(u8*)P_055,(u8*)P_056,(u8*)P_057,(u8*)P_058,(u8*)P_059,(u8*)P_060,
    (u8*)P_061,(u8*)P_062,(u8*)P_063,(u8*)P_064,(u8*)P_065,(u8*)P_066,(u8*)P_067,(u8*)P_068,(u8*)P_069,(u8*)P_070,(u8*)P_071,(u8*)P_072,(u8*)P_073,(u8*)P_074,(u8*)P_075,(u8*)P_076,(u8*)P_077,(u8*)P_078,(u8*)P_079,(u8*)P_080,
    (u8*)P_081,(u8*)P_082,(u8*)P_083,(u8*)P_084,(u8*)P_085,(u8*)P_086,(u8*)P_087,(u8*)P_088,(u8*)P_089,(u8*)P_090,(u8*)P_091,(u8*)P_092,(u8*)P_093,(u8*)P_094,(u8*)P_095,(u8*)P_096,(u8*)P_097,(u8*)P_098,(u8*)P_099,(u8*)P_100,
    (u8*)P_101,(u8*)P_102,(u8*)P_103,(u8*)P_104,(u8*)P_105,(u8*)P_106,(u8*)P_107,(u8*)P_108,(u8*)P_109,(u8*)P_110,(u8*)P_111,(u8*)P_112,(u8*)P_113,(u8*)P_114,(u8*)P_115,(u8*)P_116,(u8*)P_117,(u8*)P_118,(u8*)P_119,(u8*)P_120,
    (u8*)P_121,(u8*)P_122,(u8*)P_123,(u8*)P_124,(u8*)P_125,(u8*)P_126,(u8*)P_127,(u8*)P_128,(u8*)P_129,(u8*)P_130,(u8*)P_131,(u8*)P_132,(u8*)P_133,(u8*)P_134,(u8*)P_135,(u8*)P_136,(u8*)P_137,(u8*)P_138,(u8*)P_139,(u8*)P_140,
    (u8*)P_141,(u8*)P_142,(u8*)P_143,(u8*)P_144,(u8*)P_145,(u8*)P_146,(u8*)P_147,(u8*)P_148,(u8*)P_149,(u8*)P_150,(u8*)P_151,(u8*)P_152,(u8*)P_153,(u8*)P_154,(u8*)P_155,(u8*)P_156,(u8*)P_157,(u8*)P_158,(u8*)P_159,(u8*)P_160,
    (u8*)P_161,(u8*)P_162,(u8*)P_163,(u8*)P_164,(u8*)P_165,(u8*)P_166,(u8*)P_167,(u8*)P_168,(u8*)P_169,(u8*)P_170,(u8*)P_171,(u8*)P_172,(u8*)P_173,(u8*)P_174,(u8*)P_175,(u8*)P_176,(u8*)P_177,(u8*)P_178,(u8*)P_179,(u8*)P_180,
    (u8*)P_181,(u8*)P_182,(u8*)P_183,(u8*)P_184,(u8*)P_185,(u8*)P_186,(u8*)P_187,(u8*)P_188,(u8*)P_189,(u8*)P_190,(u8*)P_191,(u8*)P_192,(u8*)P_193,(u8*)P_194,(u8*)P_195,(u8*)P_196,(u8*)P_197,(u8*)P_198,(u8*)P_199,(u8*)P_200,
    (u8*)P_201,(u8*)P_202,(u8*)P_203,(u8*)P_204,(u8*)P_205,(u8*)P_206,(u8*)P_207,(u8*)P_208,(u8*)P_209,(u8*)P_210,(u8*)P_211,(u8*)P_212,(u8*)P_213,(u8*)P_214,(u8*)P_215,(u8*)P_216,(u8*)P_217,(u8*)P_218,(u8*)P_219,(u8*)P_220,
    (u8*)P_221,(u8*)P_222,(u8*)P_223,(u8*)P_224,(u8*)P_225,(u8*)P_226,(u8*)P_227,(u8*)P_228,(u8*)P_229,(u8*)P_230,(u8*)P_231,(u8*)P_232,(u8*)P_233,(u8*)P_234,(u8*)P_235,(u8*)P_236,(u8*)P_237,(u8*)P_238,(u8*)P_239,(u8*)P_240,
    (u8*)P_241,(u8*)P_242,(u8*)P_243,(u8*)P_244,(u8*)P_245,(u8*)P_246,(u8*)P_247,(u8*)P_248,(u8*)P_249,(u8*)P_250,(u8*)P_251,(u8*)P_252,(u8*)P_253,(u8*)P_254,(u8*)P_255,(u8*)P_256,(u8*)P_257,(u8*)P_258,(u8*)P_259,(u8*)P_260,
    (u8*)P_261,(u8*)P_262,(u8*)P_263,(u8*)P_264,(u8*)P_265,(u8*)P_266,(u8*)P_267,(u8*)P_268,(u8*)P_269,(u8*)P_270,(u8*)P_271,(u8*)P_272,(u8*)P_273,(u8*)P_274,(u8*)P_275,(u8*)P_276,(u8*)P_277,(u8*)P_278,(u8*)P_279,(u8*)P_280,
    (u8*)P_281,(u8*)P_282,(u8*)P_283,(u8*)P_284,(u8*)P_285,(u8*)P_286,(u8*)P_287,(u8*)P_288,(u8*)P_289,(u8*)P_290,(u8*)P_291,(u8*)P_292,(u8*)P_293,(u8*)P_294,(u8*)P_295,(u8*)P_296,(u8*)P_297,(u8*)P_298,(u8*)P_299,(u8*)P_300,
    (u8*)P_301,(u8*)P_302,(u8*)P_303,(u8*)P_304,(u8*)P_305,(u8*)P_306,(u8*)P_307,(u8*)P_308,(u8*)P_309,(u8*)P_310,(u8*)P_311,(u8*)P_312,(u8*)P_313,(u8*)P_314,(u8*)P_315,(u8*)P_316,(u8*)P_317,(u8*)P_318,(u8*)P_319,(u8*)P_320,
    (u8*)P_321,(u8*)P_322,(u8*)P_323,(u8*)P_324,(u8*)P_325,(u8*)P_326,(u8*)P_327,(u8*)P_328,(u8*)P_329,(u8*)P_330,(u8*)P_331,(u8*)P_332,(u8*)P_333,(u8*)P_334,(u8*)P_335,(u8*)P_336,(u8*)P_337,(u8*)P_338,(u8*)P_339,(u8*)P_340,
    (u8*)P_341,(u8*)P_342,(u8*)P_343,(u8*)P_344,(u8*)P_345,(u8*)P_346,(u8*)P_347,(u8*)P_348,(u8*)P_349,(u8*)P_350,(u8*)P_351,(u8*)P_352,(u8*)P_353,(u8*)P_354,(u8*)P_355,(u8*)P_356,(u8*)P_357,(u8*)P_358,(u8*)P_359,(u8*)P_360,
    (u8*)P_361,(u8*)P_362,(u8*)P_363,(u8*)P_364,(u8*)P_365,(u8*)P_366,(u8*)P_367,(u8*)P_368,(u8*)P_369,(u8*)P_370,(u8*)P_371,(u8*)P_372,(u8*)P_373,(u8*)P_374,(u8*)P_375,(u8*)P_376,(u8*)P_377,(u8*)P_378,(u8*)P_379,(u8*)P_380,
    (u8*)P_381,(u8*)P_382,(u8*)P_383,(u8*)P_384,(u8*)P_385,(u8*)P_386,(u8*)P_387,(u8*)P_388,(u8*)P_389,(u8*)P_390,(u8*)P_391,(u8*)P_392,(u8*)P_393,(u8*)P_394,(u8*)P_395,(u8*)P_396,(u8*)P_397,(u8*)P_398,(u8*)P_399,(u8*)P_400,
    (u8*)P_401,(u8*)P_402,(u8*)P_403,(u8*)P_404,(u8*)P_405,(u8*)P_406,(u8*)P_407,(u8*)P_408,(u8*)P_409,(u8*)P_410,(u8*)P_411,(u8*)P_412,(u8*)P_413,(u8*)P_414,(u8*)P_415,(u8*)P_416,(u8*)P_417,(u8*)P_418,(u8*)P_419,(u8*)P_420,
    (u8*)P_421,(u8*)P_422,(u8*)P_423,(u8*)P_424,(u8*)P_425,(u8*)P_426,(u8*)P_427,(u8*)P_428,(u8*)P_429,(u8*)P_430,(u8*)P_431,(u8*)P_432,(u8*)P_433,(u8*)P_434,(u8*)P_435,(u8*)P_436,(u8*)P_437,(u8*)P_438,(u8*)P_439,(u8*)P_440,
    (u8*)P_441,(u8*)P_442,(u8*)P_443,(u8*)P_444,(u8*)P_445,(u8*)P_446,(u8*)P_447,(u8*)P_448,(u8*)P_449,(u8*)P_450,(u8*)P_451,(u8*)P_452,(u8*)P_453,(u8*)P_454,(u8*)P_455,(u8*)P_456,(u8*)P_457,(u8*)P_458,(u8*)P_459,(u8*)P_460,
    (u8*)P_461,(u8*)P_462,(u8*)P_463,(u8*)P_464,(u8*)P_465,(u8*)P_466,(u8*)P_467,(u8*)P_468,(u8*)P_469,(u8*)P_470,(u8*)P_471,(u8*)P_472,(u8*)P_473,(u8*)P_474,(u8*)P_475,(u8*)P_476,(u8*)P_477,(u8*)P_478,(u8*)P_479,(u8*)P_480,
    (u8*)P_481,(u8*)P_482,(u8*)P_483,(u8*)P_484,(u8*)P_485,(u8*)P_486,(u8*)P_487,(u8*)P_488,(u8*)P_489,(u8*)P_490,(u8*)P_491,(u8*)P_492,(u8*)P_493,(u8*)P_494,(u8*)P_495,(u8*)P_496,(u8*)P_497,(u8*)P_498,(u8*)P_499,(u8*)P_500,
    (u8*)P_501,(u8*)P_502,(u8*)P_503,(u8*)P_504,(u8*)P_505,(u8*)P_506,(u8*)P_507,(u8*)P_508,(u8*)P_509,(u8*)P_510,(u8*)P_511,(u8*)P_512,(u8*)P_513,(u8*)P_514,(u8*)P_515,(u8*)P_516,(u8*)P_517,(u8*)P_518,(u8*)P_519,(u8*)P_520,
    (u8*)P_521,(u8*)P_522,(u8*)P_523,(u8*)P_524,(u8*)P_525,(u8*)P_526,(u8*)P_527,(u8*)P_528,(u8*)P_529,(u8*)P_530,(u8*)P_531,(u8*)P_532,(u8*)P_533,(u8*)P_534,(u8*)P_535,(u8*)P_536,(u8*)P_537,(u8*)P_538,(u8*)P_539,(u8*)P_540,
    (u8*)P_541,(u8*)P_542,(u8*)P_543,(u8*)P_544,(u8*)P_545,(u8*)P_546,(u8*)P_547,(u8*)P_548,(u8*)P_549,(u8*)P_550,(u8*)P_551,(u8*)P_552,(u8*)P_553,(u8*)P_554,(u8*)P_555,(u8*)P_556,(u8*)P_557,(u8*)P_558,(u8*)P_559,(u8*)P_560,
    (u8*)P_561,(u8*)P_562,(u8*)P_563,(u8*)P_564,(u8*)P_565,(u8*)P_566,(u8*)P_567,(u8*)P_568,(u8*)P_569,(u8*)P_570,(u8*)P_571,(u8*)P_572,(u8*)P_573,(u8*)P_574,(u8*)P_575,(u8*)P_576,(u8*)P_577,(u8*)P_578,(u8*)P_579,(u8*)P_580,
    (u8*)P_581,(u8*)P_582,(u8*)P_583,(u8*)P_584,(u8*)P_585,(u8*)P_586,(u8*)P_587,(u8*)P_588,(u8*)P_589,(u8*)P_590,(u8*)P_591,(u8*)P_592,(u8*)P_593,(u8*)P_594,(u8*)P_595,(u8*)P_596,(u8*)P_597,(u8*)P_598,(u8*)P_599,(u8*)P_600,
    (u8*)P_601,(u8*)P_602,(u8*)P_603,(u8*)P_604,(u8*)P_605,(u8*)P_606,(u8*)P_607,(u8*)P_608,(u8*)P_609,(u8*)P_610,(u8*)P_611,(u8*)P_612,(u8*)P_613,(u8*)P_614,(u8*)P_615,(u8*)P_616,(u8*)P_617,(u8*)P_618,(u8*)P_619,(u8*)P_620,
    (u8*)P_621,(u8*)P_622,(u8*)P_623,(u8*)P_624,(u8*)P_625,(u8*)P_626,(u8*)P_627,(u8*)P_628,(u8*)P_629,(u8*)P_630,(u8*)P_631,(u8*)P_632,(u8*)P_633,(u8*)P_634,(u8*)P_635,(u8*)P_636,(u8*)P_637,(u8*)P_638,(u8*)P_639,(u8*)P_640,
    (u8*)P_641,(u8*)P_642,(u8*)P_643,(u8*)P_644,(u8*)P_645,(u8*)P_646,(u8*)P_647,(u8*)P_648,(u8*)P_649,(u8*)P_650,(u8*)P_651,(u8*)P_652,(u8*)P_653,(u8*)P_654,(u8*)P_655,(u8*)P_656,(u8*)P_657,(u8*)P_658,(u8*)P_659,(u8*)P_660,
    (u8*)P_661,(u8*)P_662,(u8*)P_663,(u8*)P_664,(u8*)P_665,(u8*)P_666,(u8*)P_667,(u8*)P_668,(u8*)P_669,(u8*)P_670,(u8*)P_671,(u8*)P_672,(u8*)P_673,(u8*)P_674,(u8*)P_675,(u8*)P_676,(u8*)P_677,(u8*)P_678,(u8*)P_679,(u8*)P_680,
    (u8*)P_681,(u8*)P_682,(u8*)P_683,(u8*)P_684,(u8*)P_685,(u8*)P_686,(u8*)P_687,(u8*)P_688,(u8*)P_689,(u8*)P_690,(u8*)P_691,(u8*)P_692,(u8*)P_693,(u8*)P_694,(u8*)P_695,(u8*)P_696,(u8*)P_697,(u8*)P_698,(u8*)P_699,(u8*)P_700,
    (u8*)P_701,(u8*)P_702,(u8*)P_703,(u8*)P_704,(u8*)P_705,(u8*)P_706,(u8*)P_707,(u8*)P_708,(u8*)P_709,(u8*)P_710,(u8*)P_711,(u8*)P_712,(u8*)P_713,(u8*)P_714,(u8*)P_715,(u8*)P_716,(u8*)P_717,(u8*)P_718,(u8*)P_719,(u8*)P_720,
    (u8*)P_721,(u8*)P_722,(u8*)P_723,(u8*)P_724,(u8*)P_725,(u8*)P_726,(u8*)P_727,(u8*)P_728,(u8*)P_729,(u8*)P_730,(u8*)P_731,(u8*)P_732,(u8*)P_733,(u8*)P_734,(u8*)P_735,(u8*)P_736,(u8*)P_737,(u8*)P_738,(u8*)P_739,(u8*)P_740,
    (u8*)P_741,(u8*)P_742,(u8*)P_743,(u8*)P_744,(u8*)P_745,(u8*)P_746,(u8*)P_747,(u8*)P_748,(u8*)P_749,(u8*)P_750,(u8*)P_751,(u8*)P_752,(u8*)P_753,(u8*)P_754,(u8*)P_755,(u8*)P_756,(u8*)P_757,(u8*)P_758,(u8*)P_759,(u8*)P_760,
    (u8*)P_761,(u8*)P_762,(u8*)P_763,(u8*)P_764,(u8*)P_765,(u8*)P_766,(u8*)P_767,(u8*)P_768,(u8*)P_769,(u8*)P_770,(u8*)P_771,(u8*)P_772,(u8*)P_773,(u8*)P_774,(u8*)P_775,(u8*)P_776,(u8*)P_777,(u8*)P_778,(u8*)P_779,(u8*)P_780,
    (u8*)P_781,(u8*)P_782,(u8*)P_783,(u8*)P_784,(u8*)P_785,(u8*)P_786,(u8*)P_787,(u8*)P_788,(u8*)P_789,(u8*)P_790,(u8*)P_791,(u8*)P_792,(u8*)P_793,(u8*)P_794,(u8*)P_795,(u8*)P_796,(u8*)P_797,(u8*)P_798,(u8*)P_799,(u8*)P_800,
    (u8*)P_801,(u8*)P_802
};
static u8 PK_SIZE[802] = {
    (u8)(arrSz(P_001)),(u8)(arrSz(P_002)),(u8)(arrSz(P_003)),(u8)(arrSz(P_004)),(u8)(arrSz(P_005)),(u8)(arrSz(P_006)),(u8)(arrSz(P_007)),(u8)(arrSz(P_008)),(u8)(arrSz(P_009)),(u8)(arrSz(P_010)),(u8)(arrSz(P_011)),(u8)(arrSz(P_012)),(u8)(arrSz(P_013)),(u8)(arrSz(P_014)),(u8)(arrSz(P_015)),(u8)(arrSz(P_016)),(u8)(arrSz(P_017)),(u8)(arrSz(P_018)),(u8)(arrSz(P_019)),(u8)(arrSz(P_020)),
    (u8)(arrSz(P_021)),(u8)(arrSz(P_022)),(u8)(arrSz(P_023)),(u8)(arrSz(P_024)),(u8)(arrSz(P_025)),(u8)(arrSz(P_026)),(u8)(arrSz(P_027)),(u8)(arrSz(P_028)),(u8)(arrSz(P_029)),(u8)(arrSz(P_030)),(u8)(arrSz(P_031)),(u8)(arrSz(P_032)),(u8)(arrSz(P_033)),(u8)(arrSz(P_034)),(u8)(arrSz(P_035)),(u8)(arrSz(P_036)),(u8)(arrSz(P_037)),(u8)(arrSz(P_038)),(u8)(arrSz(P_039)),(u8)(arrSz(P_040)),
    (u8)(arrSz(P_041)),(u8)(arrSz(P_042)),(u8)(arrSz(P_043)),(u8)(arrSz(P_044)),(u8)(arrSz(P_045)),(u8)(arrSz(P_046)),(u8)(arrSz(P_047)),(u8)(arrSz(P_048)),(u8)(arrSz(P_049)),(u8)(arrSz(P_050)),(u8)(arrSz(P_051)),(u8)(arrSz(P_052)),(u8)(arrSz(P_053)),(u8)(arrSz(P_054)),(u8)(arrSz(P_055)),(u8)(arrSz(P_056)),(u8)(arrSz(P_057)),(u8)(arrSz(P_058)),(u8)(arrSz(P_059)),(u8)(arrSz(P_060)),
    (u8)(arrSz(P_061)),(u8)(arrSz(P_062)),(u8)(arrSz(P_063)),(u8)(arrSz(P_064)),(u8)(arrSz(P_065)),(u8)(arrSz(P_066)),(u8)(arrSz(P_067)),(u8)(arrSz(P_068)),(u8)(arrSz(P_069)),(u8)(arrSz(P_070)),(u8)(arrSz(P_071)),(u8)(arrSz(P_072)),(u8)(arrSz(P_073)),(u8)(arrSz(P_074)),(u8)(arrSz(P_075)),(u8)(arrSz(P_076)),(u8)(arrSz(P_077)),(u8)(arrSz(P_078)),(u8)(arrSz(P_079)),(u8)(arrSz(P_080)),
    (u8)(arrSz(P_081)),(u8)(arrSz(P_082)),(u8)(arrSz(P_083)),(u8)(arrSz(P_084)),(u8)(arrSz(P_085)),(u8)(arrSz(P_086)),(u8)(arrSz(P_087)),(u8)(arrSz(P_088)),(u8)(arrSz(P_089)),(u8)(arrSz(P_090)),(u8)(arrSz(P_091)),(u8)(arrSz(P_092)),(u8)(arrSz(P_093)),(u8)(arrSz(P_094)),(u8)(arrSz(P_095)),(u8)(arrSz(P_096)),(u8)(arrSz(P_097)),(u8)(arrSz(P_098)),(u8)(arrSz(P_099)),(u8)(arrSz(P_100)),
    (u8)(arrSz(P_101)),(u8)(arrSz(P_102)),(u8)(arrSz(P_103)),(u8)(arrSz(P_104)),(u8)(arrSz(P_105)),(u8)(arrSz(P_106)),(u8)(arrSz(P_107)),(u8)(arrSz(P_108)),(u8)(arrSz(P_109)),(u8)(arrSz(P_110)),(u8)(arrSz(P_111)),(u8)(arrSz(P_112)),(u8)(arrSz(P_113)),(u8)(arrSz(P_114)),(u8)(arrSz(P_115)),(u8)(arrSz(P_116)),(u8)(arrSz(P_117)),(u8)(arrSz(P_118)),(u8)(arrSz(P_119)),(u8)(arrSz(P_120)),
    (u8)(arrSz(P_121)),(u8)(arrSz(P_122)),(u8)(arrSz(P_123)),(u8)(arrSz(P_124)),(u8)(arrSz(P_125)),(u8)(arrSz(P_126)),(u8)(arrSz(P_127)),(u8)(arrSz(P_128)),(u8)(arrSz(P_129)),(u8)(arrSz(P_130)),(u8)(arrSz(P_131)),(u8)(arrSz(P_132)),(u8)(arrSz(P_133)),(u8)(arrSz(P_134)),(u8)(arrSz(P_135)),(u8)(arrSz(P_136)),(u8)(arrSz(P_137)),(u8)(arrSz(P_138)),(u8)(arrSz(P_139)),(u8)(arrSz(P_140)),
    (u8)(arrSz(P_141)),(u8)(arrSz(P_142)),(u8)(arrSz(P_143)),(u8)(arrSz(P_144)),(u8)(arrSz(P_145)),(u8)(arrSz(P_146)),(u8)(arrSz(P_147)),(u8)(arrSz(P_148)),(u8)(arrSz(P_149)),(u8)(arrSz(P_150)),(u8)(arrSz(P_151)),(u8)(arrSz(P_152)),(u8)(arrSz(P_153)),(u8)(arrSz(P_154)),(u8)(arrSz(P_155)),(u8)(arrSz(P_156)),(u8)(arrSz(P_157)),(u8)(arrSz(P_158)),(u8)(arrSz(P_159)),(u8)(arrSz(P_160)),
    (u8)(arrSz(P_161)),(u8)(arrSz(P_162)),(u8)(arrSz(P_163)),(u8)(arrSz(P_164)),(u8)(arrSz(P_165)),(u8)(arrSz(P_166)),(u8)(arrSz(P_167)),(u8)(arrSz(P_168)),(u8)(arrSz(P_169)),(u8)(arrSz(P_170)),(u8)(arrSz(P_171)),(u8)(arrSz(P_172)),(u8)(arrSz(P_173)),(u8)(arrSz(P_174)),(u8)(arrSz(P_175)),(u8)(arrSz(P_176)),(u8)(arrSz(P_177)),(u8)(arrSz(P_178)),(u8)(arrSz(P_179)),(u8)(arrSz(P_180)),
    (u8)(arrSz(P_181)),(u8)(arrSz(P_182)),(u8)(arrSz(P_183)),(u8)(arrSz(P_184)),(u8)(arrSz(P_185)),(u8)(arrSz(P_186)),(u8)(arrSz(P_187)),(u8)(arrSz(P_188)),(u8)(arrSz(P_189)),(u8)(arrSz(P_190)),(u8)(arrSz(P_191)),(u8)(arrSz(P_192)),(u8)(arrSz(P_193)),(u8)(arrSz(P_194)),(u8)(arrSz(P_195)),(u8)(arrSz(P_196)),(u8)(arrSz(P_197)),(u8)(arrSz(P_198)),(u8)(arrSz(P_199)),(u8)(arrSz(P_200)),
    (u8)(arrSz(P_201)),(u8)(arrSz(P_202)),(u8)(arrSz(P_203)),(u8)(arrSz(P_204)),(u8)(arrSz(P_205)),(u8)(arrSz(P_206)),(u8)(arrSz(P_207)),(u8)(arrSz(P_208)),(u8)(arrSz(P_209)),(u8)(arrSz(P_210)),(u8)(arrSz(P_211)),(u8)(arrSz(P_212)),(u8)(arrSz(P_213)),(u8)(arrSz(P_214)),(u8)(arrSz(P_215)),(u8)(arrSz(P_216)),(u8)(arrSz(P_217)),(u8)(arrSz(P_218)),(u8)(arrSz(P_219)),(u8)(arrSz(P_220)),
    (u8)(arrSz(P_221)),(u8)(arrSz(P_222)),(u8)(arrSz(P_223)),(u8)(arrSz(P_224)),(u8)(arrSz(P_225)),(u8)(arrSz(P_226)),(u8)(arrSz(P_227)),(u8)(arrSz(P_228)),(u8)(arrSz(P_229)),(u8)(arrSz(P_230)),(u8)(arrSz(P_231)),(u8)(arrSz(P_232)),(u8)(arrSz(P_233)),(u8)(arrSz(P_234)),(u8)(arrSz(P_235)),(u8)(arrSz(P_236)),(u8)(arrSz(P_237)),(u8)(arrSz(P_238)),(u8)(arrSz(P_239)),(u8)(arrSz(P_240)),
    (u8)(arrSz(P_241)),(u8)(arrSz(P_242)),(u8)(arrSz(P_243)),(u8)(arrSz(P_244)),(u8)(arrSz(P_245)),(u8)(arrSz(P_246)),(u8)(arrSz(P_247)),(u8)(arrSz(P_248)),(u8)(arrSz(P_249)),(u8)(arrSz(P_250)),(u8)(arrSz(P_251)),(u8)(arrSz(P_252)),(u8)(arrSz(P_253)),(u8)(arrSz(P_254)),(u8)(arrSz(P_255)),(u8)(arrSz(P_256)),(u8)(arrSz(P_257)),(u8)(arrSz(P_258)),(u8)(arrSz(P_259)),(u8)(arrSz(P_260)),
    (u8)(arrSz(P_261)),(u8)(arrSz(P_262)),(u8)(arrSz(P_263)),(u8)(arrSz(P_264)),(u8)(arrSz(P_265)),(u8)(arrSz(P_266)),(u8)(arrSz(P_267)),(u8)(arrSz(P_268)),(u8)(arrSz(P_269)),(u8)(arrSz(P_270)),(u8)(arrSz(P_271)),(u8)(arrSz(P_272)),(u8)(arrSz(P_273)),(u8)(arrSz(P_274)),(u8)(arrSz(P_275)),(u8)(arrSz(P_276)),(u8)(arrSz(P_277)),(u8)(arrSz(P_278)),(u8)(arrSz(P_279)),(u8)(arrSz(P_280)),
    (u8)(arrSz(P_281)),(u8)(arrSz(P_282)),(u8)(arrSz(P_283)),(u8)(arrSz(P_284)),(u8)(arrSz(P_285)),(u8)(arrSz(P_286)),(u8)(arrSz(P_287)),(u8)(arrSz(P_288)),(u8)(arrSz(P_289)),(u8)(arrSz(P_290)),(u8)(arrSz(P_291)),(u8)(arrSz(P_292)),(u8)(arrSz(P_293)),(u8)(arrSz(P_294)),(u8)(arrSz(P_295)),(u8)(arrSz(P_296)),(u8)(arrSz(P_297)),(u8)(arrSz(P_298)),(u8)(arrSz(P_299)),(u8)(arrSz(P_300)),
    (u8)(arrSz(P_301)),(u8)(arrSz(P_302)),(u8)(arrSz(P_303)),(u8)(arrSz(P_304)),(u8)(arrSz(P_305)),(u8)(arrSz(P_306)),(u8)(arrSz(P_307)),(u8)(arrSz(P_308)),(u8)(arrSz(P_309)),(u8)(arrSz(P_310)),(u8)(arrSz(P_311)),(u8)(arrSz(P_312)),(u8)(arrSz(P_313)),(u8)(arrSz(P_314)),(u8)(arrSz(P_315)),(u8)(arrSz(P_316)),(u8)(arrSz(P_317)),(u8)(arrSz(P_318)),(u8)(arrSz(P_319)),(u8)(arrSz(P_320)),
    (u8)(arrSz(P_321)),(u8)(arrSz(P_322)),(u8)(arrSz(P_323)),(u8)(arrSz(P_324)),(u8)(arrSz(P_325)),(u8)(arrSz(P_326)),(u8)(arrSz(P_327)),(u8)(arrSz(P_328)),(u8)(arrSz(P_329)),(u8)(arrSz(P_330)),(u8)(arrSz(P_331)),(u8)(arrSz(P_332)),(u8)(arrSz(P_333)),(u8)(arrSz(P_334)),(u8)(arrSz(P_335)),(u8)(arrSz(P_336)),(u8)(arrSz(P_337)),(u8)(arrSz(P_338)),(u8)(arrSz(P_339)),(u8)(arrSz(P_340)),
    (u8)(arrSz(P_341)),(u8)(arrSz(P_342)),(u8)(arrSz(P_343)),(u8)(arrSz(P_344)),(u8)(arrSz(P_345)),(u8)(arrSz(P_346)),(u8)(arrSz(P_347)),(u8)(arrSz(P_348)),(u8)(arrSz(P_349)),(u8)(arrSz(P_350)),(u8)(arrSz(P_351)),(u8)(arrSz(P_352)),(u8)(arrSz(P_353)),(u8)(arrSz(P_354)),(u8)(arrSz(P_355)),(u8)(arrSz(P_356)),(u8)(arrSz(P_357)),(u8)(arrSz(P_358)),(u8)(arrSz(P_359)),(u8)(arrSz(P_360)),
    (u8)(arrSz(P_361)),(u8)(arrSz(P_362)),(u8)(arrSz(P_363)),(u8)(arrSz(P_364)),(u8)(arrSz(P_365)),(u8)(arrSz(P_366)),(u8)(arrSz(P_367)),(u8)(arrSz(P_368)),(u8)(arrSz(P_369)),(u8)(arrSz(P_370)),(u8)(arrSz(P_371)),(u8)(arrSz(P_372)),(u8)(arrSz(P_373)),(u8)(arrSz(P_374)),(u8)(arrSz(P_375)),(u8)(arrSz(P_376)),(u8)(arrSz(P_377)),(u8)(arrSz(P_378)),(u8)(arrSz(P_379)),(u8)(arrSz(P_380)),
    (u8)(arrSz(P_381)),(u8)(arrSz(P_382)),(u8)(arrSz(P_383)),(u8)(arrSz(P_384)),(u8)(arrSz(P_385)),(u8)(arrSz(P_386)),(u8)(arrSz(P_387)),(u8)(arrSz(P_388)),(u8)(arrSz(P_389)),(u8)(arrSz(P_390)),(u8)(arrSz(P_391)),(u8)(arrSz(P_392)),(u8)(arrSz(P_393)),(u8)(arrSz(P_394)),(u8)(arrSz(P_395)),(u8)(arrSz(P_396)),(u8)(arrSz(P_397)),(u8)(arrSz(P_398)),(u8)(arrSz(P_399)),(u8)(arrSz(P_400)),
    (u8)(arrSz(P_401)),(u8)(arrSz(P_402)),(u8)(arrSz(P_403)),(u8)(arrSz(P_404)),(u8)(arrSz(P_405)),(u8)(arrSz(P_406)),(u8)(arrSz(P_407)),(u8)(arrSz(P_408)),(u8)(arrSz(P_409)),(u8)(arrSz(P_410)),(u8)(arrSz(P_411)),(u8)(arrSz(P_412)),(u8)(arrSz(P_413)),(u8)(arrSz(P_414)),(u8)(arrSz(P_415)),(u8)(arrSz(P_416)),(u8)(arrSz(P_417)),(u8)(arrSz(P_418)),(u8)(arrSz(P_419)),(u8)(arrSz(P_420)),
    (u8)(arrSz(P_421)),(u8)(arrSz(P_422)),(u8)(arrSz(P_423)),(u8)(arrSz(P_424)),(u8)(arrSz(P_425)),(u8)(arrSz(P_426)),(u8)(arrSz(P_427)),(u8)(arrSz(P_428)),(u8)(arrSz(P_429)),(u8)(arrSz(P_430)),(u8)(arrSz(P_431)),(u8)(arrSz(P_432)),(u8)(arrSz(P_433)),(u8)(arrSz(P_434)),(u8)(arrSz(P_435)),(u8)(arrSz(P_436)),(u8)(arrSz(P_437)),(u8)(arrSz(P_438)),(u8)(arrSz(P_439)),(u8)(arrSz(P_440)),
    (u8)(arrSz(P_441)),(u8)(arrSz(P_442)),(u8)(arrSz(P_443)),(u8)(arrSz(P_444)),(u8)(arrSz(P_445)),(u8)(arrSz(P_446)),(u8)(arrSz(P_447)),(u8)(arrSz(P_448)),(u8)(arrSz(P_449)),(u8)(arrSz(P_450)),(u8)(arrSz(P_451)),(u8)(arrSz(P_452)),(u8)(arrSz(P_453)),(u8)(arrSz(P_454)),(u8)(arrSz(P_455)),(u8)(arrSz(P_456)),(u8)(arrSz(P_457)),(u8)(arrSz(P_458)),(u8)(arrSz(P_459)),(u8)(arrSz(P_460)),
    (u8)(arrSz(P_461)),(u8)(arrSz(P_462)),(u8)(arrSz(P_463)),(u8)(arrSz(P_464)),(u8)(arrSz(P_465)),(u8)(arrSz(P_466)),(u8)(arrSz(P_467)),(u8)(arrSz(P_468)),(u8)(arrSz(P_469)),(u8)(arrSz(P_470)),(u8)(arrSz(P_471)),(u8)(arrSz(P_472)),(u8)(arrSz(P_473)),(u8)(arrSz(P_474)),(u8)(arrSz(P_475)),(u8)(arrSz(P_476)),(u8)(arrSz(P_477)),(u8)(arrSz(P_478)),(u8)(arrSz(P_479)),(u8)(arrSz(P_480)),
    (u8)(arrSz(P_481)),(u8)(arrSz(P_482)),(u8)(arrSz(P_483)),(u8)(arrSz(P_484)),(u8)(arrSz(P_485)),(u8)(arrSz(P_486)),(u8)(arrSz(P_487)),(u8)(arrSz(P_488)),(u8)(arrSz(P_489)),(u8)(arrSz(P_490)),(u8)(arrSz(P_491)),(u8)(arrSz(P_492)),(u8)(arrSz(P_493)),(u8)(arrSz(P_494)),(u8)(arrSz(P_495)),(u8)(arrSz(P_496)),(u8)(arrSz(P_497)),(u8)(arrSz(P_498)),(u8)(arrSz(P_499)),(u8)(arrSz(P_500)),
    (u8)(arrSz(P_501)),(u8)(arrSz(P_502)),(u8)(arrSz(P_503)),(u8)(arrSz(P_504)),(u8)(arrSz(P_505)),(u8)(arrSz(P_506)),(u8)(arrSz(P_507)),(u8)(arrSz(P_508)),(u8)(arrSz(P_509)),(u8)(arrSz(P_510)),(u8)(arrSz(P_511)),(u8)(arrSz(P_512)),(u8)(arrSz(P_513)),(u8)(arrSz(P_514)),(u8)(arrSz(P_515)),(u8)(arrSz(P_516)),(u8)(arrSz(P_517)),(u8)(arrSz(P_518)),(u8)(arrSz(P_519)),(u8)(arrSz(P_520)),
    (u8)(arrSz(P_521)),(u8)(arrSz(P_522)),(u8)(arrSz(P_523)),(u8)(arrSz(P_524)),(u8)(arrSz(P_525)),(u8)(arrSz(P_526)),(u8)(arrSz(P_527)),(u8)(arrSz(P_528)),(u8)(arrSz(P_529)),(u8)(arrSz(P_530)),(u8)(arrSz(P_531)),(u8)(arrSz(P_532)),(u8)(arrSz(P_533)),(u8)(arrSz(P_534)),(u8)(arrSz(P_535)),(u8)(arrSz(P_536)),(u8)(arrSz(P_537)),(u8)(arrSz(P_538)),(u8)(arrSz(P_539)),(u8)(arrSz(P_540)),
    (u8)(arrSz(P_541)),(u8)(arrSz(P_542)),(u8)(arrSz(P_543)),(u8)(arrSz(P_544)),(u8)(arrSz(P_545)),(u8)(arrSz(P_546)),(u8)(arrSz(P_547)),(u8)(arrSz(P_548)),(u8)(arrSz(P_549)),(u8)(arrSz(P_550)),(u8)(arrSz(P_551)),(u8)(arrSz(P_552)),(u8)(arrSz(P_553)),(u8)(arrSz(P_554)),(u8)(arrSz(P_555)),(u8)(arrSz(P_556)),(u8)(arrSz(P_557)),(u8)(arrSz(P_558)),(u8)(arrSz(P_559)),(u8)(arrSz(P_560)),
    (u8)(arrSz(P_561)),(u8)(arrSz(P_562)),(u8)(arrSz(P_563)),(u8)(arrSz(P_564)),(u8)(arrSz(P_565)),(u8)(arrSz(P_566)),(u8)(arrSz(P_567)),(u8)(arrSz(P_568)),(u8)(arrSz(P_569)),(u8)(arrSz(P_570)),(u8)(arrSz(P_571)),(u8)(arrSz(P_572)),(u8)(arrSz(P_573)),(u8)(arrSz(P_574)),(u8)(arrSz(P_575)),(u8)(arrSz(P_576)),(u8)(arrSz(P_577)),(u8)(arrSz(P_578)),(u8)(arrSz(P_579)),(u8)(arrSz(P_580)),
    (u8)(arrSz(P_581)),(u8)(arrSz(P_582)),(u8)(arrSz(P_583)),(u8)(arrSz(P_584)),(u8)(arrSz(P_585)),(u8)(arrSz(P_586)),(u8)(arrSz(P_587)),(u8)(arrSz(P_588)),(u8)(arrSz(P_589)),(u8)(arrSz(P_590)),(u8)(arrSz(P_591)),(u8)(arrSz(P_592)),(u8)(arrSz(P_593)),(u8)(arrSz(P_594)),(u8)(arrSz(P_595)),(u8)(arrSz(P_596)),(u8)(arrSz(P_597)),(u8)(arrSz(P_598)),(u8)(arrSz(P_599)),(u8)(arrSz(P_600)),
    (u8)(arrSz(P_601)),(u8)(arrSz(P_602)),(u8)(arrSz(P_603)),(u8)(arrSz(P_604)),(u8)(arrSz(P_605)),(u8)(arrSz(P_606)),(u8)(arrSz(P_607)),(u8)(arrSz(P_608)),(u8)(arrSz(P_609)),(u8)(arrSz(P_610)),(u8)(arrSz(P_611)),(u8)(arrSz(P_612)),(u8)(arrSz(P_613)),(u8)(arrSz(P_614)),(u8)(arrSz(P_615)),(u8)(arrSz(P_616)),(u8)(arrSz(P_617)),(u8)(arrSz(P_618)),(u8)(arrSz(P_619)),(u8)(arrSz(P_620)),
    (u8)(arrSz(P_621)),(u8)(arrSz(P_622)),(u8)(arrSz(P_623)),(u8)(arrSz(P_624)),(u8)(arrSz(P_625)),(u8)(arrSz(P_626)),(u8)(arrSz(P_627)),(u8)(arrSz(P_628)),(u8)(arrSz(P_629)),(u8)(arrSz(P_630)),(u8)(arrSz(P_631)),(u8)(arrSz(P_632)),(u8)(arrSz(P_633)),(u8)(arrSz(P_634)),(u8)(arrSz(P_635)),(u8)(arrSz(P_636)),(u8)(arrSz(P_637)),(u8)(arrSz(P_638)),(u8)(arrSz(P_639)),(u8)(arrSz(P_640)),
    (u8)(arrSz(P_641)),(u8)(arrSz(P_642)),(u8)(arrSz(P_643)),(u8)(arrSz(P_644)),(u8)(arrSz(P_645)),(u8)(arrSz(P_646)),(u8)(arrSz(P_647)),(u8)(arrSz(P_648)),(u8)(arrSz(P_649)),(u8)(arrSz(P_650)),(u8)(arrSz(P_651)),(u8)(arrSz(P_652)),(u8)(arrSz(P_653)),(u8)(arrSz(P_654)),(u8)(arrSz(P_655)),(u8)(arrSz(P_656)),(u8)(arrSz(P_657)),(u8)(arrSz(P_658)),(u8)(arrSz(P_659)),(u8)(arrSz(P_660)),
    (u8)(arrSz(P_661)),(u8)(arrSz(P_662)),(u8)(arrSz(P_663)),(u8)(arrSz(P_664)),(u8)(arrSz(P_665)),(u8)(arrSz(P_666)),(u8)(arrSz(P_667)),(u8)(arrSz(P_668)),(u8)(arrSz(P_669)),(u8)(arrSz(P_670)),(u8)(arrSz(P_671)),(u8)(arrSz(P_672)),(u8)(arrSz(P_673)),(u8)(arrSz(P_674)),(u8)(arrSz(P_675)),(u8)(arrSz(P_676)),(u8)(arrSz(P_677)),(u8)(arrSz(P_678)),(u8)(arrSz(P_679)),(u8)(arrSz(P_680)),
    (u8)(arrSz(P_681)),(u8)(arrSz(P_682)),(u8)(arrSz(P_683)),(u8)(arrSz(P_684)),(u8)(arrSz(P_685)),(u8)(arrSz(P_686)),(u8)(arrSz(P_687)),(u8)(arrSz(P_688)),(u8)(arrSz(P_689)),(u8)(arrSz(P_690)),(u8)(arrSz(P_691)),(u8)(arrSz(P_692)),(u8)(arrSz(P_693)),(u8)(arrSz(P_694)),(u8)(arrSz(P_695)),(u8)(arrSz(P_696)),(u8)(arrSz(P_697)),(u8)(arrSz(P_698)),(u8)(arrSz(P_699)),(u8)(arrSz(P_700)),
    (u8)(arrSz(P_701)),(u8)(arrSz(P_702)),(u8)(arrSz(P_703)),(u8)(arrSz(P_704)),(u8)(arrSz(P_705)),(u8)(arrSz(P_706)),(u8)(arrSz(P_707)),(u8)(arrSz(P_708)),(u8)(arrSz(P_709)),(u8)(arrSz(P_710)),(u8)(arrSz(P_711)),(u8)(arrSz(P_712)),(u8)(arrSz(P_713)),(u8)(arrSz(P_714)),(u8)(arrSz(P_715)),(u8)(arrSz(P_716)),(u8)(arrSz(P_717)),(u8)(arrSz(P_718)),(u8)(arrSz(P_719)),(u8)(arrSz(P_720)),
    (u8)(arrSz(P_721)),(u8)(arrSz(P_722)),(u8)(arrSz(P_723)),(u8)(arrSz(P_724)),(u8)(arrSz(P_725)),(u8)(arrSz(P_726)),(u8)(arrSz(P_727)),(u8)(arrSz(P_728)),(u8)(arrSz(P_729)),(u8)(arrSz(P_730)),(u8)(arrSz(P_731)),(u8)(arrSz(P_732)),(u8)(arrSz(P_733)),(u8)(arrSz(P_734)),(u8)(arrSz(P_735)),(u8)(arrSz(P_736)),(u8)(arrSz(P_737)),(u8)(arrSz(P_738)),(u8)(arrSz(P_739)),(u8)(arrSz(P_740)),
    (u8)(arrSz(P_741)),(u8)(arrSz(P_742)),(u8)(arrSz(P_743)),(u8)(arrSz(P_744)),(u8)(arrSz(P_745)),(u8)(arrSz(P_746)),(u8)(arrSz(P_747)),(u8)(arrSz(P_748)),(u8)(arrSz(P_749)),(u8)(arrSz(P_750)),(u8)(arrSz(P_751)),(u8)(arrSz(P_752)),(u8)(arrSz(P_753)),(u8)(arrSz(P_754)),(u8)(arrSz(P_755)),(u8)(arrSz(P_756)),(u8)(arrSz(P_757)),(u8)(arrSz(P_758)),(u8)(arrSz(P_759)),(u8)(arrSz(P_760)),
    (u8)(arrSz(P_761)),(u8)(arrSz(P_762)),(u8)(arrSz(P_763)),(u8)(arrSz(P_764)),(u8)(arrSz(P_765)),(u8)(arrSz(P_766)),(u8)(arrSz(P_767)),(u8)(arrSz(P_768)),(u8)(arrSz(P_769)),(u8)(arrSz(P_770)),(u8)(arrSz(P_771)),(u8)(arrSz(P_772)),(u8)(arrSz(P_773)),(u8)(arrSz(P_774)),(u8)(arrSz(P_775)),(u8)(arrSz(P_776)),(u8)(arrSz(P_777)),(u8)(arrSz(P_778)),(u8)(arrSz(P_779)),(u8)(arrSz(P_780)),
    (u8)(arrSz(P_781)),(u8)(arrSz(P_782)),(u8)(arrSz(P_783)),(u8)(arrSz(P_784)),(u8)(arrSz(P_785)),(u8)(arrSz(P_786)),(u8)(arrSz(P_787)),(u8)(arrSz(P_788)),(u8)(arrSz(P_789)),(u8)(arrSz(P_790)),(u8)(arrSz(P_791)),(u8)(arrSz(P_792)),(u8)(arrSz(P_793)),(u8)(arrSz(P_794)),(u8)(arrSz(P_795)),(u8)(arrSz(P_796)),(u8)(arrSz(P_797)),(u8)(arrSz(P_798)),(u8)(arrSz(P_799)),(u8)(arrSz(P_800)),
    (u8)(arrSz(P_801)),(u8)(arrSz(P_802))
};




// EXPERIENCE REQUIRED FOR EACH LEVEL IN EACH GROWTH
static const int EXP_BYLEVEL[][6] = {
	{ 0, 0, 0, 0, 0, 0 },
	{ 15, 6, 8, 9, 10, 4 },
	{ 52, 21, 27, 57, 33, 13 },
	{ 122, 51, 64, 96, 80, 32 },
	{ 237, 100, 125, 135, 156, 65 },
	{ 406, 172, 216, 179, 270, 112 },
	{ 637, 274, 343, 236, 428, 178 },
	{ 942, 409, 512, 314, 640, 276 },
	{ 1326, 583, 729, 419, 911, 393 },
	{ 1800, 800, 1000, 560, 1250, 540 },
	{ 2369, 1064, 1331, 742, 1663, 745 },
	{ 3041, 1382, 1728, 973, 2160, 967 },
	{ 3822, 1757, 2197, 1261, 2746, 1230 },
	{ 4719, 2195, 2744, 1612, 3430, 1591 },
	{ 5737, 2700, 3375, 2035, 4218, 1957 },
	{ 6881, 3276, 4096, 2535, 5120, 2457 },
	{ 8155, 3930, 4913, 3120, 6141, 3046 },
	{ 9564, 4665, 5832, 3798, 7290, 3732 },
	{ 11111, 5487, 6859, 4575, 8573, 4526 },
	{ 12800, 6400, 8000, 5460, 10000, 5440 },
	{ 14632, 7408, 9261, 6458, 11576, 6482 },
	{ 16610, 8518, 10648, 7577, 13310, 7666 },
	{ 18737, 9733, 12167, 8825, 15208, 9003 },
	{ 21012, 11059, 13824, 10208, 17280, 10506 },
	{ 23437, 12500, 15625, 11735, 19531, 12187 },
	{ 26012, 14060, 17576, 13411, 21970, 14060 },
	{ 28737, 15746, 19683, 15244, 24603, 16140 },
	{ 31610, 17561, 21952, 17242, 27440, 18439 },
	{ 34632, 19511, 24389, 19411, 30486, 20974 },
	{ 37800, 21600, 27000, 21760, 33750, 23760 },
	{ 41111, 23832, 29791, 24294, 37238, 26811 },
	{ 44564, 26214, 32768, 27021, 40960, 30146 },
	{ 48155, 28749, 35937, 29949, 44921, 33780 },
	{ 51881, 31443, 39304, 33084, 49130, 37731 },
	{ 55737, 34300, 42875, 36435, 53593, 42017 },
	{ 59719, 37324, 46656, 40007, 58320, 46656 },
	{ 63822, 40522, 50653, 43808, 63316, 50653 },
	{ 68041, 43897, 54872, 47846, 68590, 55969 },
	{ 72369, 47455, 59319, 52127, 74148, 60505 },
	{ 76800, 51200, 64000, 56660, 80000, 66560 },
	{ 81326, 55136, 68921, 61450, 86151, 71677 },
	{ 85942, 59270, 74088, 66505, 92610, 78533 },
	{ 90637, 63605, 79507, 71833, 99383, 84277 },
	{ 95406, 68147, 85184, 77440, 106480, 91998 },
	{ 100237, 72900, 91125, 83335, 113906, 98415 },
	{ 105122, 77868, 97336, 89523, 121670, 107069 },
	{ 110052, 83058, 103823, 96012, 129778, 114205 },
	{ 115015, 88473, 110592, 102810, 138240, 123863 },
	{ 120001, 94119, 117649, 109923, 147061, 131766 },
	{ 125000, 100000, 125000, 117360, 156250, 142500 },
	{ 131324, 106120, 132651, 125126, 165813, 151222 },
	{ 137795, 112486, 140608, 133229, 175760, 163105 },
	{ 144410, 119101, 148877, 141677, 186096, 172697 },
	{ 151165, 125971, 157464, 150476, 196830, 185807 },
	{ 158056, 133100, 166375, 159635, 207968, 196322 },
	{ 165079, 140492, 175616, 169159, 219520, 210739 },
	{ 172229, 148154, 185193, 179056, 231491, 222231 },
	{ 179503, 156089, 195112, 189334, 243890, 238036 },
	{ 186894, 164303, 205379, 199999, 256723, 250562 },
	{ 194400, 172800, 216000, 211060, 270000, 267840 },
	{ 202013, 181584, 226981, 222522, 283726, 281456 },
	{ 209728, 190662, 238328, 234393, 297910, 300293 },
	{ 217540, 200037, 250047, 246681, 312558, 315059 },
	{ 225443, 209715, 262144, 259392, 327680, 335544 },
	{ 233431, 219700, 274625, 272535, 343281, 351520 },
	{ 241496, 229996, 287496, 286115, 359370, 373744 },
	{ 249633, 240610, 300763, 300140, 375953, 390991 },
	{ 257834, 251545, 314432, 314618, 393040, 415050 },
	{ 267406, 262807, 328509, 329555, 410636, 433631 },
	{ 276458, 274400, 343000, 344960, 428750, 459620 },
	{ 286328, 286328, 357911, 360838, 447388, 479600 },
	{ 296358, 298598, 373248, 377197, 466560, 507617 },
	{ 305767, 311213, 389017, 394045, 486271, 529063 },
	{ 316074, 324179, 405224, 411388, 506530, 559209 },
	{ 326531, 337500, 421875, 429235, 527343, 582187 },
	{ 336255, 351180, 438976, 447591, 548720, 614566 },
	{ 346965, 365226, 456533, 466464, 570666, 639146 },
	{ 357812, 379641, 474552, 485862, 593190, 673863 },
	{ 367807, 394431, 493039, 505791, 616298, 700115 },
	{ 378880, 409600, 512000, 526260, 640000, 737280 },
	{ 390077, 425152, 531441, 547274, 664301, 765275 },
	{ 400293, 441094, 551368, 568841, 689210, 804997 },
	{ 411686, 457429, 571787, 590969, 714733, 834809 },
	{ 423190, 474163, 592704, 613664, 740880, 877201 },
	{ 433572, 491300, 614125, 636935, 767656, 908905 },
	{ 445239, 508844, 636056, 660787, 795070, 954084 },
	{ 457001, 526802, 658503, 685228, 823128, 987754 },
	{ 467489, 545177, 681472, 710266, 851840, 1035837 },
	{ 479378, 563975, 704969, 735907, 881211, 1071552 },
	{ 491346, 583200, 729000, 762160, 911250, 1122660 },
	{ 501878, 602856, 753571, 789030, 941963, 1160499 },
	{ 513934, 622950, 778688, 816525, 973360, 1214753 },
	{ 526049, 643485, 804357, 844653, 1005446, 1254796 },
	{ 536557, 664467, 830584, 873420, 1038230, 1312322 },
	{ 548720, 685900, 857375, 902835, 1071718, 1354652 },
	{ 560922, 707788, 884736, 932903, 1105920, 1415577 },
	{ 571333, 730138, 912673, 963632, 1140841, 1460276 },
	{ 583539, 752953, 941192, 995030, 1176490, 1524731 },
	{ 591882, 776239, 970299, 1027103, 1212873, 1571884 },
	{ 600000, 800000, 1000000, 1059860, 1250000, 1640000 }
};


// EXPERIENCE GROWTH BY PKMN TABLE
// 0 = Erratic
// 1 = Fast
// 2 = Medium Fast
// 3 = Medium Slow
// 4 = Slow
// 5 = Fluctuating
static const unsigned char EXP_RATE[] = {
3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 1, 1, 2, 2, 1, 1, 2, 2, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 4, 4, 2, 2, 2, 2, 2, 2, 2, 4, 4, 1, 2, 2, 2, 2, 2, 2, 4, 4, 2, 2, 2, 2, 2, 4, 4, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 2, 4, 4, 2, 1, 1, 1, 1, 2, 2, 3, 3, 3, 3, 1, 1, 2, 3, 3, 3, 3, 1, 3, 3, 2, 2, 2, 2, 2, 3, 2, 1, 2, 2, 2, 2, 2, 2, 3, 2, 1, 1, 2, 2, 3, 4, 3, 2, 2, 2, 2, 4, 4, 1, 2, 2, 1, 4, 4, 4, 4, 2, 2, 2, 2, 4, 1, 2, 2, 2, 2, 2, 4, 1, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 4, 4, 4, 2, 2, 5, 5, 4, 4, 4, 0, 0, 0, 3, 3, 3, 5, 5, 1, 2, 1, 1, 3, 1, 4, 4, 4, 2, 2, 4, 4, 2, 2, 0, 5, 3, 5, 5, 4, 4, 5, 5, 2, 2, 2, 1, 1, 1, 3, 3, 3, 3, 3, 0, 0, 0, 5, 1, 1, 2, 2, 5, 5, 2, 2, 0, 0, 0, 0, 0, 0, 2, 3, 1, 1, 1, 1, 4, 1, 3, 2, 2, 2, 3, 3, 3, 0, 0, 0, 4, 1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, 2, 2, 2, 3, 3, 2, 2, 2, 2, 2, 2, 2, 1, 5, 5, 2, 2, 1, 3, 1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 3, 2, 4, 4, 4, 4, 3, 3, 4, 4, 4, 4, 2, 2, 4, 0, 0, 4, 4, 4, 3, 2, 2, 4, 2, 2, 2, 1, 2, 2, 2, 3, 4, 2, 4, 2, 1, 2, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 3, 3, 3, 2, 2, 3, 3, 3, 2, 2, 2, 2, 1, 3, 3, 3, 3, 3, 3, 2, 2, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 1, 1, 3, 3, 3, 3, 3, 3, 2, 2, 4, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 2, 2, 3, 3, 3, 4, 4, 4, 2, 2, 2, 2, 2, 2, 3, 3, 2, 2, 2, 2, 2, 2, 4, 4, 4, 4, 2, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 3, 3, 3, 2, 2, 2, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 2, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 4, 4, 1, 2, 2, 2, 2, 2, 2, 2, 2, 4, 4, 4, 4, 4, 4, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 1, 4, 4, 2, 2, 2, 2, 1, 4, 4, 3, 4, 2, 2, 2, 2, 2, 2, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
};


static const char *TYPE_NAMES[] = {
    "Normal",       // 1
    "Fighting",     // 2
    "Flying",       // 3
    "Poison",       // 4
    "Ground",       // 5
    "Rock",         // 6
    "Bug",          // 7
    "Ghost",        // 8
    "Steel",        // 9
    "Fire",         // 10
    "Water",        // 11
    "Grass",        // 12
    "Electric",     // 13
    "Psychic",      // 14
    "Ice",          // 15
    "Dragon",       // 16
    "Dark",         // 17
    "Fairy"         // 18
};

static const unsigned char TYPE_COLORS[][3] = {
    {168,168,120},  // 1
    {192,48,40},    // 2
    {168,144,240},  // 3
    {160,64,160},   // 4
    {224,192,104},  // 5
    {184,160,56},   // 6
    {168,184,32},   // 7
    {112,88,152},   // 8
    {184,184,208},  // 9
    {240,128,48},   // 10
    {104,144,240},  // 11
    {120,200,80},   // 12
    {248,208,48},   // 13
    {248,88,136},   // 14
    {152,216,216},  // 15
    {112,56,248},   // 16
    {112,88,72},    // 17
    {238,153,172}   // 18
};

static const unsigned char TYPE_COLORS_DARK[][3] = {
    {109,109,78},   // 1
    {125,31,26},    // 2
    {109,94,156},   // 3
    {104,42,104},   // 4
    {146,125,68},   // 5
    {120,104,36},   // 6
    {109,120,21},   // 7
    {73,57,99},     // 8
    {120,120,135},  // 9
    {156,83,31},    // 10
    {68,94,156},    // 11
    {78,130,52},    // 12
    {161,135,31},   // 13
    {161,57,89},    // 14
    {99,141,141},   // 15
    {73,36,161},    // 16
    {73,57,47},     // 17
    {155,100,112}   // 18
};

static const unsigned char PKM_COLORS[][6] = {
    {133,133,133, 44,44,44},    // 0 Black
    {104,144,240, 68,94,156},   // 1 Blue
    {204,153,102, 112,66,20},   // 2 Brown
    {209,209,224, 120,120,135}, // 3 Gray
    {100,211,100, 17,187,17},   // 4 Green
    {244,189,201, 238,153,172}, // 5 Pink
    {193,131,193, 160,64,160},  // 6 Purple
    {236,132,132, 226,66,66},   // 7 Red
    {255,255,255, 227,206,208}, // 8 White
    {255,255,153, 255,215,51}   // 9 Yellow
};


    // TYPE, PHYSICAL/SPECIAL/STATUS/ , PP, POWER, ACC
static const unsigned char MOVE_DATA[][5] = {
    { 1 , 1 , -1 , -1 , -1 },	 // 	[NONE] [ Normal ]  ( Physical )
    { 1 , 1 , 35 , 40 , 100 },	 // 	Pound [ Normal ]  ( Physical )
    { 2 , 1 , 25 , 50 , 100 },	 // 	Karate Chop* [ Fighting ]  ( Physical )
    { 1 , 1 , 10 , 15 , 85 },	 // 	Double Slap [ Normal ]  ( Physical )
    { 1 , 1 , 15 , 18 , 85 },	 // 	Comet Punch [ Normal ]  ( Physical )
    { 1 , 1 , 20 , 80 , 85 },	 // 	Mega Punch [ Normal ]  ( Physical )
    { 1 , 1 , 20 , 40 , 100 },	 // 	Pay Day [ Normal ]  ( Physical )
    { 10 , 1 , 15 , 75 , 100 },	 // 	Fire Punch [ Fire ]  ( Physical )
    { 15 , 1 , 15 , 75 , 100 },	 // 	Ice Punch [ Ice ]  ( Physical )
    { 13 , 1 , 15 , 75 , 100 },	 // 	Thunder Punch [ Electric ]  ( Physical )
    { 1 , 1 , 35 , 40 , 100 },	 // 	Scratch [ Normal ]  ( Physical )
    { 1 , 1 , 30 , 55 , 100 },	 // 	Vice Grip [ Normal ]  ( Physical )
    { 1 , 1 , 5 , -1 , -1 },	 // 	Guillotine [ Normal ]  ( Physical )
    { 1 , 2 , 10 , 80 , 100 },	 // 	Razor Wind [ Normal ]  ( Special )
    { 1 , 3 , 20 , -1 , -1 },	 // 	Swords Dance [ Normal ]  ( Status )
    { 1 , 1 , 30 , 50 , 95 },	 // 	Cut [ Normal ]  ( Physical )
    { 3 , 2 , 35 , 40 , 100 },	 // 	Gust* [ Flying ]  ( Special )
    { 3 , 1 , 35 , 60 , 100 },	 // 	Wing Attack [ Flying ]  ( Physical )
    { 1 , 3 , 20 , -1 , -1 },	 // 	Whirlwind [ Normal ]  ( Status )
    { 3 , 1 , 15 , 90 , 95 },	 // 	Fly [ Flying ]  ( Physical )
    { 1 , 1 , 20 , 15 , 85 },	 // 	Bind [ Normal ]  ( Physical )
    { 1 , 1 , 20 , 80 , 75 },	 // 	Slam [ Normal ]  ( Physical )
    { 12 , 1 , 25 , 45 , 100 },	 // 	Vine Whip [ Grass ]  ( Physical )
    { 1 , 1 , 20 , 65 , 100 },	 // 	Stomp [ Normal ]  ( Physical )
    { 2 , 1 , 30 , 30 , 100 },	 // 	Double Kick [ Fighting ]  ( Physical )
    { 1 , 1 , 5 , 120 , 75 },	 // 	Mega Kick [ Normal ]  ( Physical )
    { 2 , 1 , 10 , 100 , 95 },	 // 	Jump Kick [ Fighting ]  ( Physical )
    { 2 , 1 , 15 , 60 , 85 },	 // 	Rolling Kick [ Fighting ]  ( Physical )
    { 5 , 3 , 15 , -1 , 100 },	 // 	Sand Attack* [ Ground ]  ( Status )
    { 1 , 1 , 15 , 70 , 100 },	 // 	Headbutt [ Normal ]  ( Physical )
    { 1 , 1 , 25 , 65 , 100 },	 // 	Horn Attack [ Normal ]  ( Physical )
    { 1 , 1 , 20 , 15 , 85 },	 // 	Fury Attack [ Normal ]  ( Physical )
    { 1 , 1 , 5 , -1 , -1 },	 // 	Horn Drill [ Normal ]  ( Physical )
    { 1 , 1 , 35 , 40 , 100 },	 // 	Tackle [ Normal ]  ( Physical )
    { 1 , 1 , 15 , 85 , 100 },	 // 	Body Slam [ Normal ]  ( Physical )
    { 1 , 1 , 20 , 15 , 90 },	 // 	Wrap [ Normal ]  ( Physical )
    { 1 , 1 , 20 , 90 , 85 },	 // 	Take Down [ Normal ]  ( Physical )
    { 1 , 1 , 10 , 120 , 100 },	 // 	Thrash [ Normal ]  ( Physical )
    { 1 , 1 , 15 , 120 , 100 },	 // 	Double-Edge [ Normal ]  ( Physical )
    { 1 , 3 , 30 , -1 , 100 },	 // 	Tail Whip [ Normal ]  ( Status )
    { 4 , 1 , 35 , 15 , 100 },	 // 	Poison Sting [ Poison ]  ( Physical )
    { 7 , 1 , 20 , 25 , 100 },	 // 	Twineedle [ Bug ]  ( Physical )
    { 7 , 1 , 20 , 25 , 95 },	 // 	Pin Missile [ Bug ]  ( Physical )
    { 1 , 3 , 30 , -1 , 100 },	 // 	Leer [ Normal ]  ( Status )
    { 17 , 1 , 25 , 60 , 100 },	 // 	Bite* [ Dark ]  ( Physical )
    { 1 , 3 , 40 , -1 , 100 },	 // 	Growl [ Normal ]  ( Status )
    { 1 , 3 , 20 , -1 , -1 },	 // 	Roar [ Normal ]  ( Status )
    { 1 , 3 , 15 , -1 , 55 },	 // 	Sing [ Normal ]  ( Status )
    { 1 , 3 , 20 , -1 , 55 },	 // 	Supersonic [ Normal ]  ( Status )
    { 1 , 2 , 20 , -1 , 90 },	 // 	Sonic Boom [ Normal ]  ( Special )
    { 1 , 3 , 20 , -1 , 100 },	 // 	Disable [ Normal ]  ( Status )
    { 4 , 2 , 30 , 40 , 100 },	 // 	Acid [ Poison ]  ( Special )
    { 10 , 2 , 25 , 40 , 100 },	 // 	Ember [ Fire ]  ( Special )
    { 10 , 2 , 15 , 90 , 100 },	 // 	Flamethrower [ Fire ]  ( Special )
    { 15 , 3 , 30 , -1 , -1 },	 // 	Mist [ Ice ]  ( Status )
    { 11 , 2 , 25 , 40 , 100 },	 // 	Water Gun [ Water ]  ( Special )
    { 11 , 2 , 5 , 110 , 80 },	 // 	Hydro Pump [ Water ]  ( Special )
    { 11 , 2 , 15 , 90 , 100 },	 // 	Surf [ Water ]  ( Special )
    { 15 , 2 , 10 , 90 , 100 },	 // 	Ice Beam [ Ice ]  ( Special )
    { 15 , 2 , 5 , 110 , 70 },	 // 	Blizzard [ Ice ]  ( Special )
    { 14 , 2 , 20 , 65 , 100 },	 // 	Psybeam [ Psychic ]  ( Special )
    { 11 , 2 , 20 , 65 , 100 },	 // 	Bubble Beam [ Water ]  ( Special )
    { 15 , 2 , 20 , 65 , 100 },	 // 	Aurora Beam [ Ice ]  ( Special )
    { 1 , 2 , 5 , 150 , 90 },	 // 	Hyper Beam [ Normal ]  ( Special )
    { 3 , 1 , 35 , 35 , 100 },	 // 	Peck [ Flying ]  ( Physical )
    { 3 , 1 , 20 , 80 , 100 },	 // 	Drill Peck [ Flying ]  ( Physical )
    { 2 , 1 , 20 , 80 , 80 },	 // 	Submission [ Fighting ]  ( Physical )
    { 2 , 1 , 20 , -1 , 100 },	 // 	Low Kick [ Fighting ]  ( Physical )
    { 2 , 1 , 20 , -1 , 100 },	 // 	Counter [ Fighting ]  ( Physical )
    { 2 , 1 , 20 , -1 , 100 },	 // 	Seismic Toss [ Fighting ]  ( Physical )
    { 1 , 1 , 15 , 80 , 100 },	 // 	Strength [ Normal ]  ( Physical )
    { 12 , 2 , 25 , 20 , 100 },	 // 	Absorb [ Grass ]  ( Special )
    { 12 , 2 , 15 , 40 , 100 },	 // 	Mega Drain [ Grass ]  ( Special )
    { 12 , 3 , 10 , -1 , 90 },	 // 	Leech Seed [ Grass ]  ( Status )
    { 1 , 3 , 20 , -1 , -1 },	 // 	Growth [ Normal ]  ( Status )
    { 12 , 1 , 25 , 55 , 95 },	 // 	Razor Leaf [ Grass ]  ( Physical )
    { 12 , 2 , 10 , 120 , 100 },	 // 	Solar Beam [ Grass ]  ( Special )
    { 4 , 3 , 35 , -1 , 75 },	 // 	Poison Powder [ Poison ]  ( Status )
    { 12 , 3 , 30 , -1 , 75 },	 // 	Stun Spore [ Grass ]  ( Status )
    { 12 , 3 , 15 , -1 , 75 },	 // 	Sleep Powder [ Grass ]  ( Status )
    { 12 , 2 , 10 , 120 , 100 },	 // 	Petal Dance [ Grass ]  ( Special )
    { 7 , 3 , 40 , -1 , 95 },	 // 	String Shot [ Bug ]  ( Status )
    { 16 , 2 , 10 , -1 , 100 },	 // 	Dragon Rage [ Dragon ]  ( Special )
    { 10 , 2 , 15 , 35 , 85 },	 // 	Fire Spin [ Fire ]  ( Special )
    { 13 , 2 , 30 , 40 , 100 },	 // 	Thunder Shock [ Electric ]  ( Special )
    { 13 , 2 , 15 , 90 , 100 },	 // 	Thunderbolt [ Electric ]  ( Special )
    { 13 , 3 , 20 , -1 , 90 },	 // 	Thunder Wave [ Electric ]  ( Status )
    { 13 , 2 , 10 , 110 , 70 },	 // 	Thunder [ Electric ]  ( Special )
    { 6 , 1 , 15 , 50 , 90 },	 // 	Rock Throw [ Rock ]  ( Physical )
    { 5 , 1 , 10 , 100 , 100 },	 // 	Earthquake [ Ground ]  ( Physical )
    { 5 , 1 , 5 , -1 , -1 },	 // 	Fissure [ Ground ]  ( Physical )
    { 5 , 1 , 10 , 80 , 100 },	 // 	Dig [ Ground ]  ( Physical )
    { 4 , 3 , 10 , -1 , 90 },	 // 	Toxic [ Poison ]  ( Status )
    { 14 , 2 , 25 , 50 , 100 },	 // 	Confusion [ Psychic ]  ( Special )
    { 14 , 2 , 10 , 90 , 100 },	 // 	Psychic [ Psychic ]  ( Special )
    { 14 , 3 , 20 , -1 , 60 },	 // 	Hypnosis [ Psychic ]  ( Status )
    { 14 , 3 , 40 , -1 , -1 },	 // 	Meditate [ Psychic ]  ( Status )
    { 14 , 3 , 30 , -1 , -1 },	 // 	Agility [ Psychic ]  ( Status )
    { 1 , 1 , 30 , 40 , 100 },	 // 	Quick Attack [ Normal ]  ( Physical )
    { 1 , 1 , 20 , 20 , 100 },	 // 	Rage [ Normal ]  ( Physical )
    { 14 , 3 , 20 , -1 , -1 },	 // 	Teleport [ Psychic ]  ( Status )
    { 8 , 2 , 15 , -1 , 100 },	 // 	Night Shade [ Ghost ]  ( Special )
    { 1 , 3 , 10 , -1 , -1 },	 // 	Mimic [ Normal ]  ( Status )
    { 1 , 3 , 40 , -1 , 85 },	 // 	Screech [ Normal ]  ( Status )
    { 1 , 3 , 15 , -1 , -1 },	 // 	Double Team [ Normal ]  ( Status )
    { 1 , 3 , 10 , -1 , -1 },	 // 	Recover [ Normal ]  ( Status )
    { 1 , 3 , 30 , -1 , -1 },	 // 	Harden [ Normal ]  ( Status )
    { 1 , 3 , 10 , -1 , -1 },	 // 	Minimize [ Normal ]  ( Status )
    { 1 , 3 , 20 , -1 , 100 },	 // 	Smokescreen [ Normal ]  ( Status )
    { 8 , 3 , 10 , -1 , 100 },	 // 	Confuse Ray [ Ghost ]  ( Status )
    { 11 , 3 , 40 , -1 , -1 },	 // 	Withdraw [ Water ]  ( Status )
    { 1 , 3 , 40 , -1 , -1 },	 // 	Defense Curl [ Normal ]  ( Status )
    { 14 , 3 , 20 , -1 , -1 },	 // 	Barrier [ Psychic ]  ( Status )
    { 14 , 3 , 30 , -1 , -1 },	 // 	Light Screen [ Psychic ]  ( Status )
    { 15 , 3 , 30 , -1 , -1 },	 // 	Haze [ Ice ]  ( Status )
    { 14 , 3 , 20 , -1 , -1 },	 // 	Reflect [ Psychic ]  ( Status )
    { 1 , 3 , 30 , -1 , -1 },	 // 	Focus Energy [ Normal ]  ( Status )
    { 1 , 1 , 10 , -1 , -1 },	 // 	Bide [ Normal ]  ( Physical )
    { 1 , 3 , 10 , -1 , -1 },	 // 	Metronome [ Normal ]  ( Status )
    { 3 , 3 , 20 , -1 , -1 },	 // 	Mirror Move [ Flying ]  ( Status )
    { 1 , 1 , 5 , 200 , 100 },	 // 	Self-Destruct [ Normal ]  ( Physical )
    { 1 , 1 , 10 , 100 , 75 },	 // 	Egg Bomb [ Normal ]  ( Physical )
    { 8 , 1 , 30 , 30 , 100 },	 // 	Lick [ Ghost ]  ( Physical )
    { 4 , 2 , 20 , 30 , 70 },	 // 	Smog [ Poison ]  ( Special )
    { 4 , 2 , 20 , 65 , 100 },	 // 	Sludge [ Poison ]  ( Special )
    { 5 , 1 , 20 , 65 , 85 },	 // 	Bone Club [ Ground ]  ( Physical )
    { 10 , 2 , 5 , 110 , 85 },	 // 	Fire Blast [ Fire ]  ( Special )
    { 11 , 1 , 15 , 80 , 100 },	 // 	Waterfall [ Water ]  ( Physical )
    { 11 , 1 , 15 , 35 , 85 },	 // 	Clamp [ Water ]  ( Physical )
    { 1 , 2 , 20 , 60 , -1 },	 // 	Swift [ Normal ]  ( Special )
    { 1 , 1 , 10 , 130 , 100 },	 // 	Skull Bash [ Normal ]  ( Physical )
    { 1 , 1 , 15 , 20 , 100 },	 // 	Spike Cannon [ Normal ]  ( Physical )
    { 1 , 1 , 35 , 10 , 100 },	 // 	Constrict [ Normal ]  ( Physical )
    { 14 , 3 , 20 , -1 , -1 },	 // 	Amnesia [ Psychic ]  ( Status )
    { 14 , 3 , 15 , -1 , 80 },	 // 	Kinesis [ Psychic ]  ( Status )
    { 1 , 3 , 10 , -1 , -1 },	 // 	Soft-Boiled [ Normal ]  ( Status )
    { 2 , 1 , 10 , 130 , 90 },	 // 	High Jump Kick [ Fighting ]  ( Physical )
    { 1 , 3 , 30 , -1 , 100 },	 // 	Glare [ Normal ]  ( Status )
    { 14 , 2 , 15 , 100 , 100 },	 // 	Dream Eater [ Psychic ]  ( Special )
    { 4 , 3 , 40 , -1 , 90 },	 // 	Poison Gas [ Poison ]  ( Status )
    { 1 , 1 , 20 , 15 , 85 },	 // 	Barrage [ Normal ]  ( Physical )
    { 7 , 1 , 10 , 80 , 100 },	 // 	Leech Life [ Bug ]  ( Physical )
    { 1 , 3 , 10 , -1 , 75 },	 // 	Lovely Kiss [ Normal ]  ( Status )
    { 3 , 1 , 5 , 140 , 90 },	 // 	Sky Attack [ Flying ]  ( Physical )
    { 1 , 3 , 10 , -1 , -1 },	 // 	Transform [ Normal ]  ( Status )
    { 11 , 2 , 30 , 40 , 100 },	 // 	Bubble [ Water ]  ( Special )
    { 1 , 1 , 10 , 70 , 100 },	 // 	Dizzy Punch [ Normal ]  ( Physical )
    { 12 , 3 , 15 , -1 , 100 },	 // 	Spore [ Grass ]  ( Status )
    { 1 , 3 , 20 , -1 , 100 },	 // 	Flash [ Normal ]  ( Status )
    { 14 , 2 , 15 , -1 , 100 },	 // 	Psywave [ Psychic ]  ( Special )
    { 1 , 3 , 40 , -1 , -1 },	 // 	Splash [ Normal ]  ( Status )
    { 4 , 3 , 20 , -1 , -1 },	 // 	Acid Armor [ Poison ]  ( Status )
    { 11 , 1 , 10 , 100 , 90 },	 // 	Crabhammer [ Water ]  ( Physical )
    { 1 , 1 , 5 , 250 , 100 },	 // 	Explosion [ Normal ]  ( Physical )
    { 1 , 1 , 15 , 18 , 80 },	 // 	Fury Swipes [ Normal ]  ( Physical )
    { 5 , 1 , 10 , 50 , 90 },	 // 	Bonemerang [ Ground ]  ( Physical )
    { 14 , 3 , 10 , -1 , -1 },	 // 	Rest [ Psychic ]  ( Status )
    { 6 , 1 , 10 , 75 , 90 },	 // 	Rock Slide [ Rock ]  ( Physical )
    { 1 , 1 , 15 , 80 , 90 },	 // 	Hyper Fang [ Normal ]  ( Physical )
    { 1 , 3 , 30 , -1 , -1 },	 // 	Sharpen [ Normal ]  ( Status )
    { 1 , 3 , 30 , -1 , -1 },	 // 	Conversion [ Normal ]  ( Status )
    { 1 , 2 , 10 , 80 , 100 },	 // 	Tri Attack [ Normal ]  ( Special )
    { 1 , 1 , 10 , -1 , 90 },	 // 	Super Fang [ Normal ]  ( Physical )
    { 1 , 1 , 20 , 70 , 100 },	 // 	Slash [ Normal ]  ( Physical )
    { 1 , 3 , 10 , -1 , -1 },	 // 	Substitute [ Normal ]  ( Status )
    { 1 , 1 , 1 , 50 , -1 },	 // 	Struggle [ Normal ]  ( Physical )
    { 1 , 3 , 1 , -1 , -1 },	 // 	Sketch [ Normal ]  ( Status )
    { 2 , 1 , 10 , 10 , 90 },	 // 	Triple Kick [ Fighting ]  ( Physical )
    { 17 , 1 , 25 , 60 , 100 },	 // 	Thief [ Dark ]  ( Physical )
    { 7 , 3 , 10 , -1 , -1 },	 // 	Spider Web [ Bug ]  ( Status )
    { 1 , 3 , 5 , -1 , -1 },	 // 	Mind Reader [ Normal ]  ( Status )
    { 8 , 3 , 15 , -1 , 100 },	 // 	Nightmare [ Ghost ]  ( Status )
    { 10 , 1 , 25 , 60 , 100 },	 // 	Flame Wheel [ Fire ]  ( Physical )
    { 1 , 2 , 15 , 50 , 100 },	 // 	Snore [ Normal ]  ( Special )
    { 8 , 3 , 10 , -1 , -1 },	 // 	Curse* [ Ghost ]  ( Status )
    { 1 , 1 , 15 , -1 , 100 },	 // 	Flail [ Normal ]  ( Physical )
    { 1 , 3 , 30 , -1 , -1 },	 // 	Conversion 2 [ Normal ]  ( Status )
    { 3 , 2 , 5 , 100 , 95 },	 // 	Aeroblast [ Flying ]  ( Special )
    { 12 , 3 , 40 , -1 , 100 },	 // 	Cotton Spore [ Grass ]  ( Status )
    { 2 , 1 , 15 , -1 , 100 },	 // 	Reversal [ Fighting ]  ( Physical )
    { 8 , 3 , 10 , -1 , 100 },	 // 	Spite [ Ghost ]  ( Status )
    { 15 , 2 , 25 , 40 , 100 },	 // 	Powder Snow [ Ice ]  ( Special )
    { 1 , 3 , 10 , -1 , -1 },	 // 	Protect [ Normal ]  ( Status )
    { 2 , 1 , 30 , 40 , 100 },	 // 	Mach Punch [ Fighting ]  ( Physical )
    { 1 , 3 , 10 , -1 , 100 },	 // 	Scary Face [ Normal ]  ( Status )
    { 17 , 1 , 20 , 60 , -1 },	 // 	Feint Attack [ Dark ]  ( Physical )
    { 18 , 3 , 10 , -1 , 75 },	 // 	Sweet Kiss* [ Fairy ]  ( Status )
    { 1 , 3 , 10 , -1 , -1 },	 // 	Belly Drum [ Normal ]  ( Status )
    { 4 , 2 , 10 , 90 , 100 },	 // 	Sludge Bomb [ Poison ]  ( Special )
    { 5 , 2 , 10 , 20 , 100 },	 // 	Mud-Slap [ Ground ]  ( Special )
    { 11 , 2 , 10 , 65 , 85 },	 // 	Octazooka [ Water ]  ( Special )
    { 5 , 3 , 20 , -1 , -1 },	 // 	Spikes [ Ground ]  ( Status )
    { 13 , 2 , 5 , 120 , 50 },	 // 	Zap Cannon [ Electric ]  ( Special )
    { 1 , 3 , 40 , -1 , -1 },	 // 	Foresight [ Normal ]  ( Status )
    { 8 , 3 , 5 , -1 , -1 },	 // 	Destiny Bond [ Ghost ]  ( Status )
    { 1 , 3 , 5 , -1 , -1 },	 // 	Perish Song [ Normal ]  ( Status )
    { 15 , 2 , 15 , 55 , 95 },	 // 	Icy Wind [ Ice ]  ( Special )
    { 2 , 3 , 5 , -1 , -1 },	 // 	Detect [ Fighting ]  ( Status )
    { 5 , 1 , 10 , 25 , 90 },	 // 	Bone Rush [ Ground ]  ( Physical )
    { 1 , 3 , 5 , -1 , -1 },	 // 	Lock-On [ Normal ]  ( Status )
    { 16 , 1 , 10 , 120 , 100 },	 // 	Outrage [ Dragon ]  ( Physical )
    { 6 , 3 , 10 , -1 , -1 },	 // 	Sandstorm [ Rock ]  ( Status )
    { 12 , 2 , 10 , 75 , 100 },	 // 	Giga Drain [ Grass ]  ( Special )
    { 1 , 3 , 10 , -1 , -1 },	 // 	Endure [ Normal ]  ( Status )
    { 18 , 3 , 20 , -1 , 100 },	 // 	Charm* [ Fairy ]  ( Status )
    { 6 , 1 , 20 , 30 , 90 },	 // 	Rollout [ Rock ]  ( Physical )
    { 1 , 1 , 40 , 40 , 100 },	 // 	False Swipe [ Normal ]  ( Physical )
    { 1 , 3 , 15 , -1 , 85 },	 // 	Swagger [ Normal ]  ( Status )
    { 1 , 3 , 10 , -1 , -1 },	 // 	Milk Drink [ Normal ]  ( Status )
    { 13 , 1 , 20 , 65 , 100 },	 // 	Spark [ Electric ]  ( Physical )
    { 7 , 1 , 20 , 40 , 95 },	 // 	Fury Cutter [ Bug ]  ( Physical )
    { 9 , 1 , 25 , 70 , 90 },	 // 	Steel Wing [ Steel ]  ( Physical )
    { 1 , 3 , 5 , -1 , -1 },	 // 	Mean Look [ Normal ]  ( Status )
    { 1 , 3 , 15 , -1 , 100 },	 // 	Attract [ Normal ]  ( Status )
    { 1 , 3 , 10 , -1 , -1 },	 // 	Sleep Talk [ Normal ]  ( Status )
    { 1 , 3 , 5 , -1 , -1 },	 // 	Heal Bell [ Normal ]  ( Status )
    { 1 , 1 , 20 , -1 , 100 },	 // 	Return [ Normal ]  ( Physical )
    { 1 , 1 , 15 , -1 , 90 },	 // 	Present [ Normal ]  ( Physical )
    { 1 , 1 , 20 , -1 , 100 },	 // 	Frustration [ Normal ]  ( Physical )
    { 1 , 3 , 25 , -1 , -1 },	 // 	Safeguard [ Normal ]  ( Status )
    { 1 , 3 , 20 , -1 , -1 },	 // 	Pain Split [ Normal ]  ( Status )
    { 10 , 1 , 5 , 100 , 95 },	 // 	Sacred 10 [ Fire ]  ( Physical )
    { 5 , 1 , 30 , -1 , 100 },	 // 	Magnitude [ Ground ]  ( Physical )
    { 2 , 1 , 5 , 100 , 50 },	 // 	Dynamic Punch [ Fighting ]  ( Physical )
    { 7 , 1 , 10 , 120 , 85 },	 // 	Megahorn [ Bug ]  ( Physical )
    { 16 , 2 , 20 , 60 , 100 },	 // 	Dragon Breath [ Dragon ]  ( Special )
    { 1 , 3 , 40 , -1 , -1 },	 // 	Baton Pass [ Normal ]  ( Status )
    { 1 , 3 , 5 , -1 , 100 },	 // 	Encore [ Normal ]  ( Status )
    { 17 , 1 , 20 , 40 , 100 },	 // 	Pursuit [ Dark ]  ( Physical )
    { 1 , 1 , 40 , 20 , 100 },	 // 	Rapid Spin [ Normal ]  ( Physical )
    { 1 , 3 , 20 , -1 , 100 },	 // 	Sweet Scent [ Normal ]  ( Status )
    { 9 , 1 , 15 , 100 , 75 },	 // 	Iron Tail [ Steel ]  ( Physical )
    { 9 , 1 , 35 , 50 , 95 },	 // 	Metal Claw [ Steel ]  ( Physical )
    { 2 , 1 , 10 , 70 , -1 },	 // 	Vital Throw [ Fighting ]  ( Physical )
    { 1 , 3 , 5 , -1 , -1 },	 // 	Morning Sun [ Normal ]  ( Status )
    { 12 , 3 , 5 , -1 , -1 },	 // 	Synthesis [ Grass ]  ( Status )
    { 18 , 3 , 5 , -1 , -1 },	 // 	Moonlight* [ Fairy ]  ( Status )
    { 1 , 2 , 15 , 60 , 100 },	 // 	Hidden Power [ Normal ]  ( Special )
    { 2 , 1 , 5 , 100 , 80 },	 // 	Cross Chop [ Fighting ]  ( Physical )
    { 16 , 2 , 20 , 40 , 100 },	 // 	Twister [ Dragon ]  ( Special )
    { 11 , 3 , 5 , -1 , -1 },	 // 	Rain Dance [ Water ]  ( Status )
    { 10 , 3 , 5 , -1 , -1 },	 // 	Sunny Day [ Fire ]  ( Status )
    { 17 , 1 , 15 , 80 , 100 },	 // 	Crunch [ Dark ]  ( Physical )
    { 14 , 2 , 20 , -1 , 100 },	 // 	Mirror Coat [ Psychic ]  ( Special )
    { 1 , 3 , 10 , -1 , -1 },	 // 	Psych Up [ Normal ]  ( Status )
    { 1 , 1 , 5 , 80 , 100 },	 // 	Extreme Speed [ Normal ]  ( Physical )
    { 6 , 2 , 5 , 60 , 100 },	 // 	Ancient Power [ Rock ]  ( Special )
    { 8 , 2 , 15 , 80 , 100 },	 // 	Shadow Ball [ Ghost ]  ( Special )
    { 14 , 2 , 10 , 120 , 100 },	 // 	Future Sight [ Psychic ]  ( Special )
    { 2 , 1 , 15 , 40 , 100 },	 // 	Rock Smash [ Fighting ]  ( Physical )
    { 11 , 2 , 15 , 35 , 85 },	 // 	Whirlpool [ Water ]  ( Special )
    { 17 , 1 , 10 , -1 , 100 },	 // 	Beat Up [ Dark ]  ( Physical )
    { 1 , 1 , 10 , 40 , 100 },	 // 	Fake Out [ Normal ]  ( Physical )
    { 1 , 2 , 10 , 90 , 100 },	 // 	Uproar [ Normal ]  ( Special )
    { 1 , 3 , 20 , -1 , -1 },	 // 	Stockpile [ Normal ]  ( Status )
    { 1 , 2 , 10 , -1 , 100 },	 // 	Spit Up [ Normal ]  ( Special )
    { 1 , 3 , 10 , -1 , -1 },	 // 	Swallow [ Normal ]  ( Status )
    { 10 , 2 , 10 , 95 , 90 },	 // 	Heat Wave [ Fire ]  ( Special )
    { 15 , 3 , 10 , -1 , -1 },	 // 	Hail [ Ice ]  ( Status )
    { 17 , 3 , 15 , -1 , 100 },	 // 	Torment [ Dark ]  ( Status )
    { 17 , 3 , 15 , -1 , 100 },	 // 	Flatter [ Dark ]  ( Status )
    { 10 , 3 , 15 , -1 , 85 },	 // 	Will-O-Wisp [ Fire ]  ( Status )
    { 17 , 3 , 10 , -1 , 100 },	 // 	Memento [ Dark ]  ( Status )
    { 1 , 1 , 20 , 70 , 100 },	 // 	Facade [ Normal ]  ( Physical )
    { 2 , 1 , 20 , 150 , 100 },	 // 	Focus Punch [ Fighting ]  ( Physical )
    { 1 , 1 , 10 , 70 , 100 },	 // 	Smelling Salts [ Normal ]  ( Physical )
    { 1 , 3 , 20 , -1 , -1 },	 // 	Follow Me [ Normal ]  ( Status )
    { 1 , 3 , 20 , -1 , -1 },	 // 	Nature Power [ Normal ]  ( Status )
    { 13 , 3 , 20 , -1 , -1 },	 // 	Charge [ Electric ]  ( Status )
    { 17 , 3 , 20 , -1 , 100 },	 // 	Taunt [ Dark ]  ( Status )
    { 1 , 3 , 20 , -1 , -1 },	 // 	Helping Hand [ Normal ]  ( Status )
    { 14 , 3 , 10 , -1 , 100 },	 // 	Trick [ Psychic ]  ( Status )
    { 14 , 3 , 10 , -1 , -1 },	 // 	Role Play [ Psychic ]  ( Status )
    { 1 , 3 , 10 , -1 , -1 },	 // 	Wish [ Normal ]  ( Status )
    { 1 , 3 , 20 , -1 , -1 },	 // 	Assist [ Normal ]  ( Status )
    { 12 , 3 , 20 , -1 , -1 },	 // 	Ingrain [ Grass ]  ( Status )
    { 2 , 1 , 5 , 120 , 100 },	 // 	Superpower [ Fighting ]  ( Physical )
    { 14 , 3 , 15 , -1 , -1 },	 // 	Magic Coat [ Psychic ]  ( Status )
    { 1 , 3 , 10 , -1 , -1 },	 // 	Recycle [ Normal ]  ( Status )
    { 2 , 1 , 10 , 60 , 100 },	 // 	Revenge [ Fighting ]  ( Physical )
    { 2 , 1 , 15 , 75 , 100 },	 // 	Brick Break [ Fighting ]  ( Physical )
    { 1 , 3 , 10 , -1 , -1 },	 // 	Yawn [ Normal ]  ( Status )
    { 17 , 1 , 20 , 65 , 100 },	 // 	Knock Off [ Dark ]  ( Physical )
    { 1 , 1 , 5 , -1 , 100 },	 // 	Endeavor [ Normal ]  ( Physical )
    { 10 , 2 , 5 , 150 , 100 },	 // 	Eruption [ Fire ]  ( Special )
    { 14 , 3 , 10 , -1 , -1 },	 // 	Skill Swap [ Psychic ]  ( Status )
    { 14 , 3 , 10 , -1 , -1 },	 // 	Imprison [ Psychic ]  ( Status )
    { 1 , 3 , 20 , -1 , -1 },	 // 	Refresh [ Normal ]  ( Status )
    { 8 , 3 , 5 , -1 , -1 },	 // 	Grudge [ Ghost ]  ( Status )
    { 17 , 3 , 10 , -1 , -1 },	 // 	Snatch [ Dark ]  ( Status )
    { 1 , 1 , 20 , 70 , 100 },	 // 	Secret Power [ Normal ]  ( Physical )
    { 11 , 1 , 10 , 80 , 100 },	 // 	Dive [ Water ]  ( Physical )
    { 2 , 1 , 20 , 15 , 100 },	 // 	Arm Thrust [ Fighting ]  ( Physical )
    { 1 , 3 , 20 , -1 , -1 },	 // 	Camouflage [ Normal ]  ( Status )
    { 7 , 3 , 20 , -1 , -1 },	 // 	Tail Glow [ Bug ]  ( Status )
    { 14 , 2 , 5 , 70 , 100 },	 // 	Luster Purge [ Psychic ]  ( Special )
    { 14 , 2 , 5 , 70 , 100 },	 // 	Mist Ball [ Psychic ]  ( Special )
    { 3 , 3 , 15 , -1 , 100 },	 // 	Feather Dance [ Flying ]  ( Status )
    { 1 , 3 , 20 , -1 , 100 },	 // 	Teeter Dance [ Normal ]  ( Status )
    { 10 , 1 , 10 , 85 , 90 },	 // 	Blaze Kick [ Fire ]  ( Physical )
    { 5 , 3 , 15 , -1 , -1 },	 // 	Mud Sport [ Ground ]  ( Status )
    { 15 , 1 , 20 , 30 , 90 },	 // 	Ice Ball [ Ice ]  ( Physical )
    { 12 , 1 , 15 , 60 , 100 },	 // 	Needle Arm [ Grass ]  ( Physical )
    { 1 , 3 , 10 , -1 , -1 },	 // 	Slack Off [ Normal ]  ( Status )
    { 1 , 2 , 10 , 90 , 100 },	 // 	Hyper Voice [ Normal ]  ( Special )
    { 4 , 1 , 15 , 50 , 100 },	 // 	Poison Fang [ Poison ]  ( Physical )
    { 1 , 1 , 10 , 75 , 95 },	 // 	Crush Claw [ Normal ]  ( Physical )
    { 10 , 2 , 5 , 150 , 90 },	 // 	Blast Burn [ Fire ]  ( Special )
    { 11 , 2 , 5 , 150 , 90 },	 // 	Hydro Cannon [ Water ]  ( Special )
    { 9 , 1 , 10 , 90 , 90 },	 // 	Meteor Mash [ Steel ]  ( Physical )
    { 8 , 1 , 15 , 30 , 100 },	 // 	Astonish [ Ghost ]  ( Physical )
    { 1 , 2 , 10 , 50 , 100 },	 // 	Weather Ball [ Normal ]  ( Special )
    { 12 , 3 , 5 , -1 , -1 },	 // 	Aromatherapy [ Grass ]  ( Status )
    { 17 , 3 , 20 , -1 , 100 },	 // 	Fake Tears [ Dark ]  ( Status )
    { 3 , 2 , 25 , 60 , 95 },	 // 	Air Cutter [ Flying ]  ( Special )
    { 10 , 2 , 5 , 130 , 90 },	 // 	Overheat [ Fire ]  ( Special )
    { 1 , 3 , 40 , -1 , -1 },	 // 	Odor Sleuth [ Normal ]  ( Status )
    { 6 , 1 , 15 , 60 , 95 },	 // 	Rock Tomb [ Rock ]  ( Physical )
    { 7 , 2 , 5 , 60 , 100 },	 // 	Silver Wind [ Bug ]  ( Special )
    { 9 , 3 , 40 , -1 , 85 },	 // 	Metal Sound [ Steel ]  ( Status )
    { 12 , 3 , 15 , -1 , 55 },	 // 	Grass Whistle [ Grass ]  ( Status )
    { 1 , 3 , 20 , -1 , 100 },	 // 	Tickle [ Normal ]  ( Status )
    { 14 , 3 , 20 , -1 , -1 },	 // 	Cosmic Power [ Psychic ]  ( Status )
    { 11 , 2 , 5 , 150 , 100 },	 // 	Water Spout [ Water ]  ( Special )
    { 7 , 2 , 15 , 75 , 100 },	 // 	Signal Beam [ Bug ]  ( Special )
    { 8 , 1 , 20 , 60 , -1 },	 // 	Shadow Punch [ Ghost ]  ( Physical )
    { 14 , 2 , 20 , 80 , 100 },	 // 	Extrasensory [ Psychic ]  ( Special )
    { 2 , 1 , 15 , 85 , 90 },	 // 	Sky Uppercut [ Fighting ]  ( Physical )
    { 5 , 1 , 15 , 35 , 85 },	 // 	Sand Tomb [ Ground ]  ( Physical )
    { 15 , 2 , 5 , -1 , -1 },	 // 	Sheer Cold [ Ice ]  ( Special )
    { 11 , 2 , 10 , 90 , 85 },	 // 	Muddy 11 [ Water ]  ( Special )
    { 12 , 1 , 30 , 25 , 100 },	 // 	Bullet Seed [ Grass ]  ( Physical )
    { 3 , 1 , 20 , 60 , -1 },	 // 	Aerial Ace [ Flying ]  ( Physical )
    { 15 , 1 , 30 , 25 , 100 },	 // 	Icicle Spear [ Ice ]  ( Physical )
    { 9 , 3 , 15 , -1 , -1 },	 // 	Iron Defense [ Steel ]  ( Status )
    { 1 , 3 , 5 , -1 , -1 },	 // 	Block [ Normal ]  ( Status )
    { 1 , 3 , 40 , -1 , -1 },	 // 	Howl [ Normal ]  ( Status )
    { 16 , 1 , 15 , 80 , 100 },	 // 	Dragon Claw [ Dragon ]  ( Physical )
    { 12 , 2 , 5 , 150 , 90 },	 // 	Frenzy Plant [ Grass ]  ( Special )
    { 2 , 3 , 20 , -1 , -1 },	 // 	Bulk Up [ Fighting ]  ( Status )
    { 3 , 1 , 5 , 85 , 85 },	 // 	Bounce [ Flying ]  ( Physical )
    { 5 , 2 , 15 , 55 , 95 },	 // 	Mud Shot [ Ground ]  ( Special )
    { 4 , 1 , 25 , 50 , 100 },	 // 	Poison Tail [ Poison ]  ( Physical )
    { 1 , 1 , 25 , 60 , 100 },	 // 	Covet [ Normal ]  ( Physical )
    { 13 , 1 , 15 , 120 , 100 },	 // 	Volt Tackle [ Electric ]  ( Physical )
    { 12 , 2 , 20 , 60 , -1 },	 // 	Magical Leaf [ Grass ]  ( Special )
    { 11 , 3 , 15 , -1 , -1 },	 // 	Water Sport [ Water ]  ( Status )
    { 14 , 3 , 20 , -1 , -1 },	 // 	Calm Mind [ Psychic ]  ( Status )
    { 12 , 1 , 15 , 90 , 100 },	 // 	Leaf Blade [ Grass ]  ( Physical )
    { 16 , 3 , 20 , -1 , -1 },	 // 	Dragon Dance [ Dragon ]  ( Status )
    { 6 , 1 , 10 , 25 , 90 },	 // 	Rock Blast [ Rock ]  ( Physical )
    { 13 , 2 , 20 , 60 , -1 },	 // 	Shock Wave [ Electric ]  ( Special )
    { 11 , 2 , 20 , 60 , 100 },	 // 	Water Pulse [ Water ]  ( Special )
    { 9 , 2 , 5 , 140 , 100 },	 // 	Doom Desire [ Steel ]  ( Special )
    { 14 , 2 , 5 , 140 , 90 },	 // 	Psycho Boost [ Psychic ]  ( Special )
    { 3 , 3 , 10 , -1 , -1 },	 // 	Roost [ Flying ]  ( Status )
    { 14 , 3 , 5 , -1 , -1 },	 // 	Gravity [ Psychic ]  ( Status )
    { 14 , 3 , 40 , -1 , -1 },	 // 	Miracle Eye [ Psychic ]  ( Status )
    { 2 , 1 , 10 , 70 , 100 },	 // 	Wake-Up Slap [ Fighting ]  ( Physical )
    { 2 , 1 , 10 , 100 , 90 },	 // 	Hammer Arm [ Fighting ]  ( Physical )
    { 9 , 1 , 5 , -1 , 100 },	 // 	Gyro Ball [ Steel ]  ( Physical )
    { 14 , 3 , 10 , -1 , -1 },	 // 	Healing Wish [ Psychic ]  ( Status )
    { 11 , 2 , 10 , 65 , 100 },	 // 	Brine [ Water ]  ( Special )
    { 1 , 1 , 15 , -1 , 100 },	 // 	Natural Gift [ Normal ]  ( Physical )
    { 1 , 1 , 10 , 30 , 100 },	 // 	Feint [ Normal ]  ( Physical )
    { 3 , 1 , 20 , 60 , 100 },	 // 	Pluck [ Flying ]  ( Physical )
    { 3 , 3 , 15 , -1 , -1 },	 // 	Tailwind [ Flying ]  ( Status )
    { 1 , 3 , 30 , -1 , -1 },	 // 	Acupressure [ Normal ]  ( Status )
    { 9 , 1 , 10 , -1 , 100 },	 // 	Metal Burst [ Steel ]  ( Physical )
    { 7 , 1 , 20 , 70 , 100 },	 // 	U-turn [ Bug ]  ( Physical )
    { 2 , 1 , 5 , 120 , 100 },	 // 	Close Combat [ Fighting ]  ( Physical )
    { 17 , 1 , 10 , 50 , 100 },	 // 	Payback [ Dark ]  ( Physical )
    { 17 , 1 , 10 , 60 , 100 },	 // 	Assurance [ Dark ]  ( Physical )
    { 17 , 3 , 15 , -1 , 100 },	 // 	Embargo [ Dark ]  ( Status )
    { 17 , 1 , 10 , -1 , 100 },	 // 	Fling [ Dark ]  ( Physical )
    { 14 , 3 , 10 , -1 , 100 },	 // 	Psycho Shift [ Psychic ]  ( Status )
    { 1 , 2 , 5 , -1 , -1 },	 // 	Trump Card [ Normal ]  ( Special )
    { 14 , 3 , 15 , -1 , 100 },	 // 	Heal Block [ Psychic ]  ( Status )
    { 1 , 2 , 5 , -1 , 100 },	 // 	Wring Out [ Normal ]  ( Special )
    { 14 , 3 , 10 , -1 , -1 },	 // 	Power Trick [ Psychic ]  ( Status )
    { 4 , 3 , 10 , -1 , 100 },	 // 	Gastro Acid [ Poison ]  ( Status )
    { 1 , 3 , 30 , -1 , -1 },	 // 	Lucky Chant [ Normal ]  ( Status )
    { 1 , 3 , 20 , -1 , -1 },	 // 	Me First [ Normal ]  ( Status )
    { 1 , 3 , 20 , -1 , -1 },	 // 	Copycat [ Normal ]  ( Status )
    { 14 , 3 , 10 , -1 , -1 },	 // 	Power Swap [ Psychic ]  ( Status )
    { 14 , 3 , 10 , -1 , -1 },	 // 	Guard Swap [ Psychic ]  ( Status )
    { 17 , 1 , 5 , -1 , 100 },	 // 	Punishment [ Dark ]  ( Physical )
    { 1 , 1 , 5 , 140 , 100 },	 // 	Last Resort [ Normal ]  ( Physical )
    { 12 , 3 , 10 , -1 , 100 },	 // 	Worry Seed [ Grass ]  ( Status )
    { 17 , 1 , 5 , 70 , 100 },	 // 	Sucker Punch [ Dark ]  ( Physical )
    { 4 , 3 , 20 , -1 , -1 },	 // 	Toxic Spikes [ Poison ]  ( Status )
    { 14 , 3 , 10 , -1 , -1 },	 // 	Heart Swap [ Psychic ]  ( Status )
    { 11 , 3 , 20 , -1 , -1 },	 // 	Aqua Ring [ Water ]  ( Status )
    { 13 , 3 , 10 , -1 , -1 },	 // 	Magnet Rise [ Electric ]  ( Status )
    { 10 , 1 , 15 , 120 , 100 },	 // 	Flare Blitz [ Fire ]  ( Physical )
    { 2 , 1 , 10 , 60 , 100 },	 // 	Force Palm [ Fighting ]  ( Physical )
    { 2 , 2 , 20 , 80 , -1 },	 // 	Aura Sphere [ Fighting ]  ( Special )
    { 6 , 3 , 20 , -1 , -1 },	 // 	Rock Polish [ Rock ]  ( Status )
    { 4 , 1 , 20 , 80 , 100 },	 // 	Poison Jab [ Poison ]  ( Physical )
    { 17 , 2 , 15 , 80 , 100 },	 // 	Dark Pulse [ Dark ]  ( Special )
    { 17 , 1 , 15 , 70 , 100 },	 // 	Night Slash [ Dark ]  ( Physical )
    { 11 , 1 , 10 , 90 , 90 },	 // 	Aqua Tail [ Water ]  ( Physical )
    { 12 , 1 , 15 , 80 , 100 },	 // 	Seed Bomb [ Grass ]  ( Physical )
    { 3 , 2 , 15 , 75 , 95 },	 // 	Air Slash [ Flying ]  ( Special )
    { 7 , 1 , 15 , 80 , 100 },	 // 	X-Scissor [ Bug ]  ( Physical )
    { 7 , 2 , 10 , 90 , 100 },	 // 	Bug Buzz [ Bug ]  ( Special )
    { 16 , 2 , 10 , 85 , 100 },	 // 	Dragon Pulse [ Dragon ]  ( Special )
    { 16 , 1 , 10 , 100 , 75 },	 // 	Dragon Rush [ Dragon ]  ( Physical )
    { 6 , 2 , 20 , 80 , 100 },	 // 	Power Gem [ Rock ]  ( Special )
    { 2 , 1 , 10 , 75 , 100 },	 // 	Drain Punch [ Fighting ]  ( Physical )
    { 2 , 2 , 30 , 40 , 100 },	 // 	Vacuum Wave [ Fighting ]  ( Special )
    { 2 , 2 , 5 , 120 , 70 },	 // 	Focus Blast [ Fighting ]  ( Special )
    { 12 , 2 , 10 , 90 , 100 },	 // 	Energy Ball [ Grass ]  ( Special )
    { 3 , 1 , 15 , 120 , 100 },	 // 	Brave Bird [ Flying ]  ( Physical )
    { 5 , 2 , 10 , 90 , 100 },	 // 	Earth Power [ Ground ]  ( Special )
    { 17 , 3 , 10 , -1 , 100 },	 // 	Switcheroo [ Dark ]  ( Status )
    { 1 , 1 , 5 , 150 , 90 },	 // 	Giga Impact [ Normal ]  ( Physical )
    { 17 , 3 , 20 , -1 , -1 },	 // 	Nasty Plot [ Dark ]  ( Status )
    { 9 , 1 , 30 , 40 , 100 },	 // 	Bullet Punch [ Steel ]  ( Physical )
    { 15 , 1 , 10 , 60 , 100 },	 // 	Avalanche [ Ice ]  ( Physical )
    { 15 , 1 , 30 , 40 , 100 },	 // 	Ice Shard [ Ice ]  ( Physical )
    { 8 , 1 , 15 , 70 , 100 },	 // 	Shadow Claw [ Ghost ]  ( Physical )
    { 13 , 1 , 15 , 65 , 95 },	 // 	Thunder Fang [ Electric ]  ( Physical )
    { 15 , 1 , 15 , 65 , 95 },	 // 	Ice Fang [ Ice ]  ( Physical )
    { 10 , 1 , 15 , 65 , 95 },	 // 	Fire Fang [ Fire ]  ( Physical )
    { 8 , 1 , 30 , 40 , 100 },	 // 	Shadow Sneak [ Ghost ]  ( Physical )
    { 5 , 2 , 10 , 65 , 85 },	 // 	Mud Bomb [ Ground ]  ( Special )
    { 14 , 1 , 20 , 70 , 100 },	 // 	Psycho Cut [ Psychic ]  ( Physical )
    { 14 , 1 , 15 , 80 , 90 },	 // 	Zen Headbutt [ Psychic ]  ( Physical )
    { 9 , 2 , 10 , 65 , 85 },	 // 	Mirror Shot [ Steel ]  ( Special )
    { 9 , 2 , 10 , 80 , 100 },	 // 	Flash Cannon [ Steel ]  ( Special )
    { 1 , 1 , 20 , 90 , 85 },	 // 	Rock Climb [ Normal ]  ( Physical )
    { 3 , 3 , 15 , -1 , -1 },	 // 	Defog [ Flying ]  ( Status )
    { 14 , 3 , 5 , -1 , -1 },	 // 	Trick Room [ Psychic ]  ( Status )
    { 16 , 2 , 5 , 130 , 90 },	 // 	Draco Meteor [ Dragon ]  ( Special )
    { 13 , 2 , 15 , 80 , 100 },	 // 	Discharge [ Electric ]  ( Special )
    { 10 , 2 , 15 , 80 , 100 },	 // 	Lava Plume [ Fire ]  ( Special )
    { 12 , 2 , 5 , 130 , 90 },	 // 	Leaf Storm [ Grass ]  ( Special )
    { 12 , 1 , 10 , 120 , 85 },	 // 	Power Whip [ Grass ]  ( Physical )
    { 6 , 1 , 5 , 150 , 90 },	 // 	Rock Wrecker [ Rock ]  ( Physical )
    { 4 , 1 , 20 , 70 , 100 },	 // 	Cross 4 [ Poison ]  ( Physical )
    { 4 , 1 , 5 , 120 , 80 },	 // 	Gunk Shot [ Poison ]  ( Physical )
    { 9 , 1 , 15 , 80 , 100 },	 // 	Iron Head [ Steel ]  ( Physical )
    { 9 , 1 , 20 , 60 , -1 },	 // 	Magnet Bomb [ Steel ]  ( Physical )
    { 6 , 1 , 5 , 100 , 80 },	 // 	Stone Edge [ Rock ]  ( Physical )
    { 1 , 3 , 20 , -1 , 100 },	 // 	Captivate [ Normal ]  ( Status )
    { 6 , 3 , 20 , -1 , -1 },	 // 	Stealth 6 [ Rock ]  ( Status )
    { 12 , 2 , 20 , -1 , 100 },	 // 	Grass Knot [ Grass ]  ( Special )
    { 3 , 2 , 20 , 65 , 100 },	 // 	Chatter [ Flying ]  ( Special )
    { 1 , 2 , 10 , 100 , 100 },	 // 	Judgment [ Normal ]  ( Special )
    { 7 , 1 , 20 , 60 , 100 },	 // 	Bug Bite [ Bug ]  ( Physical )
    { 13 , 2 , 10 , 50 , 90 },	 // 	Charge Beam [ Electric ]  ( Special )
    { 12 , 1 , 15 , 120 , 100 },	 // 	Wood Hammer [ Grass ]  ( Physical )
    { 11 , 1 , 20 , 40 , 100 },	 // 	Aqua Jet [ Water ]  ( Physical )
    { 7 , 1 , 15 , 90 , 100 },	 // 	Attack Order [ Bug ]  ( Physical )
    { 7 , 3 , 10 , -1 , -1 },	 // 	Defend Order [ Bug ]  ( Status )
    { 7 , 3 , 10 , -1 , -1 },	 // 	Heal Order [ Bug ]  ( Status )
    { 6 , 1 , 5 , 150 , 80 },	 // 	Head Smash [ Rock ]  ( Physical )
    { 1 , 1 , 10 , 35 , 90 },	 // 	Double Hit [ Normal ]  ( Physical )
    { 16 , 2 , 5 , 150 , 90 },	 // 	Roar of Time [ Dragon ]  ( Special )
    { 16 , 2 , 5 , 100 , 95 },	 // 	Spacial Rend [ Dragon ]  ( Special )
    { 14 , 3 , 10 , -1 , -1 },	 // 	Lunar Dance [ Psychic ]  ( Status )
    { 1 , 1 , 5 , -1 , 100 },	 // 	Crush Grip [ Normal ]  ( Physical )
    { 10 , 2 , 5 , 100 , 75 },	 // 	Magma Storm [ Fire ]  ( Special )
    { 17 , 3 , 10 , -1 , 50 },	 // 	Dark Void [ Dark ]  ( Status )
    { 12 , 2 , 5 , 120 , 85 },	 // 	Seed Flare [ Grass ]  ( Special )
    { 8 , 2 , 5 , 60 , 100 },	 // 	Ominous Wind [ Ghost ]  ( Special )
    { 8 , 1 , 5 , 120 , 100 },	 // 	Shadow Force [ Ghost ]  ( Physical )
    { 17 , 3 , 15 , -1 , -1 },	 // 	Hone Claws [ Dark ]  ( Status )
    { 6 , 3 , 10 , -1 , -1 },	 // 	Wide Guard [ Rock ]  ( Status )
    { 14 , 3 , 10 , -1 , -1 },	 // 	Guard Split [ Psychic ]  ( Status )
    { 14 , 3 , 10 , -1 , -1 },	 // 	Power Split [ Psychic ]  ( Status )
    { 14 , 3 , 10 , -1 , -1 },	 // 	Wonder Room [ Psychic ]  ( Status )
    { 14 , 2 , 10 , 80 , 100 },	 // 	Psyshock [ Psychic ]  ( Special )
    { 4 , 2 , 10 , 65 , 100 },	 // 	Venoshock [ Poison ]  ( Special )
    { 9 , 3 , 15 , -1 , -1 },	 // 	Autotomize [ Steel ]  ( Status )
    { 7 , 3 , 20 , -1 , -1 },	 // 	Rage Powder [ Bug ]  ( Status )
    { 14 , 3 , 15 , -1 , -1 },	 // 	Telekinesis [ Psychic ]  ( Status )
    { 14 , 3 , 10 , -1 , -1 },	 // 	Magic Room [ Psychic ]  ( Status )
    { 6 , 1 , 15 , 50 , 100 },	 // 	Smack Down [ Rock ]  ( Physical )
    { 2 , 1 , 10 , 60 , 100 },	 // 	Storm Throw [ Fighting ]  ( Physical )
    { 10 , 2 , 15 , 70 , 100 },	 // 	Flame Burst [ Fire ]  ( Special )
    { 4 , 2 , 10 , 95 , 100 },	 // 	Sludge Wave [ Poison ]  ( Special )
    { 7 , 3 , 20 , -1 , -1 },	 // 	Quiver Dance [ Bug ]  ( Status )
    { 9 , 1 , 10 , -1 , 100 },	 // 	Heavy Slam [ Steel ]  ( Physical )
    { 14 , 2 , 10 , 120 , 100 },	 // 	Synchronoise [ Psychic ]  ( Special )
    { 13 , 2 , 10 , -1 , 100 },	 // 	Electro Ball [ Electric ]  ( Special )
    { 11 , 3 , 20 , -1 , 100 },	 // 	Soak [ Water ]  ( Status )
    { 10 , 1 , 20 , 50 , 100 },	 // 	Flame Charge [ Fire ]  ( Physical )
    { 4 , 3 , 20 , -1 , -1 },	 // 	Coil [ Poison ]  ( Status )
    { 2 , 1 , 20 , 65 , 100 },	 // 	Low Sweep [ Fighting ]  ( Physical )
    { 4 , 2 , 20 , 40 , 100 },	 // 	Acid Spray [ Poison ]  ( Special )
    { 17 , 1 , 15 , 95 , 100 },	 // 	Foul Play [ Dark ]  ( Physical )
    { 1 , 3 , 15 , -1 , 100 },	 // 	Simple Beam [ Normal ]  ( Status )
    { 1 , 3 , 15 , -1 , 100 },	 // 	Entrainment [ Normal ]  ( Status )
    { 1 , 3 , 15 , -1 , -1 },	 // 	After You [ Normal ]  ( Status )
    { 1 , 2 , 15 , 60 , 100 },	 // 	Round [ Normal ]  ( Special )
    { 1 , 2 , 15 , 40 , 100 },	 // 	Echoed Voice [ Normal ]  ( Special )
    { 1 , 1 , 20 , 70 , 100 },	 // 	Chip Away [ Normal ]  ( Physical )
    { 4 , 2 , 15 , 50 , -1 },	 // 	Clear Smog [ Poison ]  ( Special )
    { 14 , 2 , 10 , 20 , 100 },	 // 	Stored Power [ Psychic ]  ( Special )
    { 2 , 3 , 15 , -1 , -1 },	 // 	Quick Guard [ Fighting ]  ( Status )
    { 14 , 3 , 15 , -1 , -1 },	 // 	Ally Switch [ Psychic ]  ( Status )
    { 11 , 2 , 15 , 80 , 100 },	 // 	Scald [ Water ]  ( Special )
    { 1 , 3 , 15 , -1 , -1 },	 // 	Shell Smash [ Normal ]  ( Status )
    { 14 , 3 , 10 , -1 , -1 },	 // 	Heal Pulse [ Psychic ]  ( Status )
    { 8 , 2 , 10 , 65 , 100 },	 // 	Hex [ Ghost ]  ( Special )
    { 3 , 1 , 10 , 60 , 100 },	 // 	Sky Drop [ Flying ]  ( Physical )
    { 9 , 3 , 10 , -1 , -1 },	 // 	Shift Gear [ Steel ]  ( Status )
    { 2 , 1 , 10 , 60 , 90 },	 // 	Circle Throw [ Fighting ]  ( Physical )
    { 10 , 2 , 15 , 60 , 100 },	 // 	Incinerate [ Fire ]  ( Special )
    { 17 , 3 , 15 , -1 , 100 },	 // 	Quash [ Dark ]  ( Status )
    { 3 , 1 , 15 , 55 , 100 },	 // 	Acrobatics [ Flying ]  ( Physical )
    { 1 , 3 , 15 , -1 , -1 },	 // 	Reflect Type [ Normal ]  ( Status )
    { 1 , 1 , 5 , 70 , 100 },	 // 	Retaliate [ Normal ]  ( Physical )
    { 2 , 2 , 5 , -1 , 100 },	 // 	Final Gambit [ Fighting ]  ( Special )
    { 1 , 3 , 15 , -1 , -1 },	 // 	Bestow [ Normal ]  ( Status )
    { 10 , 2 , 5 , 100 , 50 },	 // 	Inferno [ Fire ]  ( Special )
    { 11 , 2 , 10 , 80 , 100 },	 // 	Water Pledge [ Water ]  ( Special )
    { 10 , 2 , 10 , 80 , 100 },	 // 	Fire Pledge [ Fire ]  ( Special )
    { 12 , 2 , 10 , 80 , 100 },	 // 	Grass Pledge [ Grass ]  ( Special )
    { 13 , 2 , 20 , 70 , 100 },	 // 	Volt Switch [ Electric ]  ( Special )
    { 7 , 2 , 20 , 50 , 100 },	 // 	Struggle 7 [ Bug ]  ( Special )
    { 5 , 1 , 20 , 60 , 100 },	 // 	Bulldoze [ Ground ]  ( Physical )
    { 15 , 2 , 10 , 60 , 90 },	 // 	Frost Breath [ Ice ]  ( Special )
    { 16 , 1 , 10 , 60 , 90 },	 // 	Dragon Tail [ Dragon ]  ( Physical )
    { 1 , 3 , 30 , -1 , -1 },	 // 	Work Up [ Normal ]  ( Status )
    { 13 , 2 , 15 , 55 , 95 },	 // 	Electroweb [ Electric ]  ( Special )
    { 13 , 1 , 15 , 90 , 100 },	 // 	Wild Charge [ Electric ]  ( Physical )
    { 5 , 1 , 10 , 80 , 95 },	 // 	Drill Run [ Ground ]  ( Physical )
    { 16 , 1 , 15 , 40 , 90 },	 // 	Dual Chop [ Dragon ]  ( Physical )
    { 14 , 1 , 25 , 60 , 100 },	 // 	Heart Stamp [ Psychic ]  ( Physical )
    { 12 , 1 , 10 , 75 , 100 },	 // 	Horn Leech [ Grass ]  ( Physical )
    { 2 , 1 , 15 , 90 , 100 },	 // 	Sacred Sword [ Fighting ]  ( Physical )
    { 11 , 1 , 10 , 75 , 95 },	 // 	Razor Shell [ Water ]  ( Physical )
    { 10 , 1 , 10 , -1 , 100 },	 // 	Heat Crash [ Fire ]  ( Physical )
    { 12 , 2 , 10 , 65 , 90 },	 // 	Leaf Tornado [ Grass ]  ( Special )
    { 7 , 1 , 20 , 65 , 100 },	 // 	Steamroller [ Bug ]  ( Physical )
    { 12 , 3 , 10 , -1 , -1 },	 // 	Cotton Guard [ Grass ]  ( Status )
    { 17 , 2 , 10 , 85 , 95 },	 // 	Night Daze [ Dark ]  ( Special )
    { 14 , 2 , 10 , 100 , 100 },	 // 	Psystrike [ Psychic ]  ( Special )
    { 1 , 1 , 10 , 25 , 85 },	 // 	Tail Slap [ Normal ]  ( Physical )
    { 3 , 2 , 10 , 110 , 70 },	 // 	Hurricane [ Flying ]  ( Special )
    { 1 , 1 , 15 , 120 , 100 },	 // 	Head Charge [ Normal ]  ( Physical )
    { 9 , 1 , 15 , 50 , 85 },	 // 	Gear Grind [ Steel ]  ( Physical )
    { 10 , 2 , 5 , 100 , 100 },	 // 	Searing Shot [ Fire ]  ( Special )
    { 1 , 2 , 5 , 120 , 100 },	 // 	Techno Blast [ Normal ]  ( Special )
    { 1 , 2 , 10 , 75 , 100 },	 // 	Relic Song [ Normal ]  ( Special )
    { 2 , 2 , 10 , 85 , 100 },	 // 	Secret Sword [ Fighting ]  ( Special )
    { 15 , 2 , 10 , 65 , 95 },	 // 	Glaciate [ Ice ]  ( Special )
    { 13 , 1 , 5 , 130 , 85 },	 // 	Bolt Strike [ Electric ]  ( Physical )
    { 10 , 2 , 5 , 130 , 85 },	 // 	Blue Flare [ Fire ]  ( Special )
    { 10 , 2 , 10 , 80 , 100 },	 // 	Fiery Dance [ Fire ]  ( Special )
    { 15 , 1 , 5 , 140 , 90 },	 // 	Freeze Shock [ Ice ]  ( Physical )
    { 15 , 2 , 5 , 140 , 90 },	 // 	Ice Burn [ Ice ]  ( Special )
    { 17 , 2 , 15 , 55 , 95 },	 // 	Snarl [ Dark ]  ( Special )
    { 15 , 1 , 10 , 85 , 90 },	 // 	Icicle Crash [ Ice ]  ( Physical )
    { 10 , 1 , 5 , 180 , 95 },	 // 	V-create [ Fire ]  ( Physical )
    { 10 , 2 , 5 , 100 , 100 },	 // 	Fusion Flare [ Fire ]  ( Special )
    { 13 , 1 , 5 , 100 , 100 },	 // 	Fusion Bolt [ Electric ]  ( Physical )
    { 2 , 1 , 10 , 100 , 95 },	 // 	Flying Press [ Fighting ]  ( Physical )
    { 2 , 3 , 10 , -1 , -1 },	 // 	Mat Block [ Fighting ]  ( Status )
    { 4 , 2 , 10 , 120 , 90 },	 // 	Belch [ Poison ]  ( Special )
    { 5 , 3 , 10 , -1 , -1 },	 // 	Rototiller [ Ground ]  ( Status )
    { 7 , 3 , 20 , -1 , -1 },	 // 	Sticky Web [ Bug ]  ( Status )
    { 7 , 1 , 25 , 50 , 100 },	 // 	Fell Stinger [ Bug ]  ( Physical )
    { 8 , 1 , 10 , 90 , 100 },	 // 	Phantom Force [ Ghost ]  ( Physical )
    { 8 , 3 , 20 , -1 , 100 },	 // 	Trick-or-Treat [ Ghost ]  ( Status )
    { 1 , 3 , 30 , -1 , 100 },	 // 	Noble Roar [ Normal ]  ( Status )
    { 13 , 3 , 25 , -1 , -1 },	 // 	Ion Deluge [ Electric ]  ( Status )
    { 13 , 2 , 20 , 65 , 100 },	 // 	Parabolic Charge [ Electric ]  ( Special )
    { 12 , 3 , 20 , -1 , 100 },	 // 	Forest's Curse [ Grass ]  ( Status )
    { 12 , 1 , 15 , 90 , 100 },	 // 	Petal Blizzard [ Grass ]  ( Physical )
    { 15 , 2 , 20 , 70 , 100 },	 // 	Freeze-Dry [ Ice ]  ( Special )
    { 18 , 2 , 15 , 40 , -1 },	 // 	Disarming Voice [ Fairy ]  ( Special )
    { 17 , 3 , 20 , -1 , 100 },	 // 	Parting Shot [ Dark ]  ( Status )
    { 17 , 3 , 20 , -1 , -1 },	 // 	Topsy-Turvy [ Dark ]  ( Status )
    { 18 , 2 , 10 , 50 , 100 },	 // 	Draining Kiss [ Fairy ]  ( Special )
    { 18 , 3 , 10 , -1 , -1 },	 // 	Crafty Shield [ Fairy ]  ( Status )
    { 18 , 3 , 10 , -1 , -1 },	 // 	Flower Shield [ Fairy ]  ( Status )
    { 12 , 3 , 10 , -1 , -1 },	 // 	Grassy Terrain [ Grass ]  ( Status )
    { 18 , 3 , 10 , -1 , -1 },	 // 	Misty Terrain [ Fairy ]  ( Status )
    { 13 , 3 , 20 , -1 , -1 },	 // 	Electrify [ Electric ]  ( Status )
    { 18 , 1 , 10 , 90 , 90 },	 // 	Play Rough [ Fairy ]  ( Physical )
    { 18 , 2 , 30 , 40 , 100 },	 // 	Fairy Wind [ Fairy ]  ( Special )
    { 18 , 2 , 15 , 95 , 100 },	 // 	Moonblast [ Fairy ]  ( Special )
    { 1 , 2 , 10 , 140 , 100 },	 // 	Boomburst [ Normal ]  ( Special )
    { 18 , 3 , 10 , -1 , -1 },	 // 	Fairy Lock [ Fairy ]  ( Status )
    { 9 , 3 , 10 , -1 , -1 },	 // 	King's Shield [ Steel ]  ( Status )
    { 1 , 3 , 20 , -1 , -1 },	 // 	Play Nice [ Normal ]  ( Status )
    { 1 , 3 , 20 , -1 , -1 },	 // 	Confide [ Normal ]  ( Status )
    { 6 , 1 , 5 , 100 , 95 },	 // 	Diamond Storm [ Rock ]  ( Physical )
    { 11 , 2 , 5 , 110 , 95 },	 // 	Steam Eruption [ Water ]  ( Special )
    { 14 , 2 , 5 , 80 , -1 },	 // 	Hyperspace Hole [ Psychic ]  ( Special )
    { 11 , 2 , 20 , 15 , 100 },	 // 	Water Shuriken* [ Water ]  ( Special )
    { 10 , 2 , 10 , 75 , 100 },	 // 	Mystical 10 [ Fire ]  ( Special )
    { 12 , 3 , 10 , -1 , -1 },	 // 	Spiky Shield [ Grass ]  ( Status )
    { 18 , 3 , 20 , -1 , -1 },	 // 	Aromatic Mist [ Fairy ]  ( Status )
    { 13 , 3 , 15 , -1 , 100 },	 // 	Eerie Impulse [ Electric ]  ( Status )
    { 4 , 3 , 20 , -1 , 100 },	 // 	Venom Drench [ Poison ]  ( Status )
    { 7 , 3 , 20 , -1 , 100 },	 // 	Powder [ Bug ]  ( Status )
    { 18 , 3 , 10 , -1 , -1 },	 // 	Geomancy [ Fairy ]  ( Status )
    { 13 , 3 , 20 , -1 , -1 },	 // 	Magnetic Flux [ Electric ]  ( Status )
    { 1 , 3 , 30 , -1 , -1 },	 // 	Happy Hour [ Normal ]  ( Status )
    { 13 , 3 , 10 , -1 , -1 },	 // 	Electric Terrain [ Electric ]  ( Status )
    { 18 , 2 , 10 , 80 , 100 },	 // 	Dazzling Gleam [ Fairy ]  ( Special )
    { 1 , 3 , 40 , -1 , -1 },	 // 	Celebrate [ Normal ]  ( Status )
    { 1 , 3 , 40 , -1 , -1 },	 // 	Hold Hands [ Normal ]  ( Status )
    { 18 , 3 , 30 , -1 , 100 },	 // 	Baby-Doll Eyes [ Fairy ]  ( Status )
    { 13 , 1 , 20 , 20 , 100 },	 // 	Nuzzle [ Electric ]  ( Physical )
    { 1 , 1 , 40 , 40 , 100 },	 // 	Hold Back [ Normal ]  ( Physical )
    { 7 , 2 , 20 , 20 , 100 },	 // 	Infestation [ Bug ]  ( Special )
    { 2 , 1 , 20 , 40 , 100 },	 // 	Power-Up Punch [ Fighting ]  ( Physical )
    { 3 , 2 , 10 , 80 , 100 },	 // 	Oblivion Wing [ Flying ]  ( Special )
    { 5 , 1 , 10 , 90 , 100 },	 // 	Thousand Arrows [ Ground ]  ( Physical )
    { 5 , 1 , 10 , 90 , 100 },	 // 	Thousand Waves [ Ground ]  ( Physical )
    { 5 , 1 , 10 , 90 , 100 },	 // 	Land's Wrath [ Ground ]  ( Physical )
    { 18 , 2 , 5 , 140 , 90 },	 // 	Light of Ruin [ Fairy ]  ( Special )
    { 11 , 2 , 10 , 110 , 85 },	 // 	Origin Pulse [ Water ]  ( Special )
    { 5 , 1 , 10 , 120 , 85 },	 // 	Precipice Blades [ Ground ]  ( Physical )
    { 3 , 1 , 5 , 120 , 100 },	 // 	Dragon Ascent [ Flying ]  ( Physical )
    { 17 , 1 , 5 , 100 , -1 },	 // 	Hyperspace Fury [ Dark ]  ( Physical )
    { 1 , 1 , 1 , -1 , -1 },	 // 	Breakneck Blitz [ Normal ]  ( Physical )
    { 1 , 2 , 1 , -1 , -1 },	 // 	Breakneck Blitz [ Normal ]  ( Special )
    { 2 , 1 , 1 , -1 , -1 },	 // 	All-Out Pummeling [ Fighting ]  ( Physical )
    { 2 , 2 , 1 , -1 , -1 },	 // 	All-Out Pummeling [ Fighting ]  ( Special )
    { 3 , 1 , 1 , -1 , -1 },	 // 	Supersonic Skystrike [ Flying ]  ( Physical )
    { 3 , 2 , 1 , -1 , -1 },	 // 	Supersonic Skystrike [ Flying ]  ( Special )
    { 4 , 1 , 1 , -1 , -1 },	 // 	Acid Downpour [ Poison ]  ( Physical )
    { 4 , 2 , 1 , -1 , -1 },	 // 	Acid Downpour [ Poison ]  ( Special )
    { 5 , 1 , 1 , -1 , -1 },	 // 	Tectonic Rage [ Ground ]  ( Physical )
    { 5 , 2 , 1 , -1 , -1 },	 // 	Tectonic Rage [ Ground ]  ( Special )
    { 6 , 1 , 1 , -1 , -1 },	 // 	Continental Crush [ Rock ]  ( Physical )
    { 6 , 2 , 1 , -1 , -1 },	 // 	Continental Crush [ Rock ]  ( Special )
    { 7 , 1 , 1 , -1 , -1 },	 // 	Savage Spin-Out [ Bug ]  ( Physical )
    { 7 , 2 , 1 , -1 , -1 },	 // 	Savage Spin-Out [ Bug ]  ( Special )
    { 8 , 1 , 1 , -1 , -1 },	 // 	Never-Ending Nightmare [ Ghost ]  ( Physical )
    { 8 , 2 , 1 , -1 , -1 },	 // 	Never-Ending Nightmare [ Ghost ]  ( Special )
    { 9 , 1 , 1 , -1 , -1 },	 // 	Corkscrew Crash [ Steel ]  ( Physical )
    { 9 , 2 , 1 , -1 , -1 },	 // 	Corkscrew Crash [ Steel ]  ( Special )
    { 10 , 1 , 1 , -1 , -1 },	 // 	Inferno Overdrive [ Fire ]  ( Physical )
    { 10 , 2 , 1 , -1 , -1 },	 // 	Inferno Overdrive [ Fire ]  ( Special )
    { 11 , 1 , 1 , -1 , -1 },	 // 	Hydro Vortex [ Water ]  ( Physical )
    { 11 , 2 , 1 , -1 , -1 },	 // 	Hydro Vortex [ Water ]  ( Special )
    { 12 , 1 , 1 , -1 , -1 },	 // 	Bloom Doom [ Grass ]  ( Physical )
    { 12 , 2 , 1 , -1 , -1 },	 // 	Bloom Doom [ Grass ]  ( Special )
    { 13 , 1 , 1 , -1 , -1 },	 // 	Gigavolt Havoc [ Electric ]  ( Physical )
    { 13 , 2 , 1 , -1 , -1 },	 // 	Gigavolt Havoc [ Electric ]  ( Special )
    { 14 , 1 , 1 , -1 , -1 },	 // 	Shattered Psyche [ Psychic ]  ( Physical )
    { 14 , 2 , 1 , -1 , -1 },	 // 	Shattered Psyche [ Psychic ]  ( Special )
    { 15 , 1 , 1 , -1 , -1 },	 // 	Subzero Slammer [ Ice ]  ( Physical )
    { 15 , 2 , 1 , -1 , -1 },	 // 	Subzero Slammer [ Ice ]  ( Special )
    { 16 , 1 , 1 , -1 , -1 },	 // 	Devastating Drake [ Dragon ]  ( Physical )
    { 16 , 2 , 1 , -1 , -1 },	 // 	Devastating Drake [ Dragon ]  ( Special )
    { 17 , 1 , 1 , -1 , -1 },	 // 	Black Hole Eclipse [ Dark ]  ( Physical )
    { 17 , 2 , 1 , -1 , -1 },	 // 	Black Hole Eclipse [ Dark ]  ( Special )
    { 18 , 1 , 1 , -1 , -1 },	 // 	Twinkle Tackle [ Fairy ]  ( Physical )
    { 18 , 2 , 1 , -1 , -1 },	 // 	Twinkle Tackle [ Fairy ]  ( Special )
    { 13 , 1 , 1 , 210 , -1 },	 // 	Catastropika [ Electric ]  ( Physical )
    { 5 , 3 , 10 , -1 , -1 },	 // 	Shore Up [ Ground ]  ( Status )
    { 7 , 1 , 10 , 90 , 100 },	 // 	First Impression [ Bug ]  ( Physical )
    { 4 , 3 , 10 , -1 , -1 },	 // 	Baneful Bunker [ Poison ]  ( Status )
    { 8 , 1 , 10 , 80 , 100 },	 // 	Spirit Shackle [ Ghost ]  ( Physical )
    { 17 , 1 , 10 , 85 , 100 },	 // 	Darkest Lariat [ Dark ]  ( Physical )
    { 11 , 2 , 10 , 90 , 100 },	 // 	Sparkling Aria [ Water ]  ( Special )
    { 15 , 1 , 10 , 100 , 90 },	 // 	Ice Hammer [ Ice ]  ( Physical )
    { 18 , 3 , 10 , -1 , -1 },	 // 	Floral Healing [ Fairy ]  ( Status )
    { 5 , 1 , 10 , 95 , 95 },	 // 	High Horsepower [ Ground ]  ( Physical )
    { 12 , 3 , 10 , -1 , 100 },	 // 	Strength Sap [ Grass ]  ( Status )
    { 12 , 1 , 10 , 125 , 100 },	 // 	Solar Blade [ Grass ]  ( Physical )
    { 12 , 1 , 40 , 40 , 100 },	 // 	Leafage [ Grass ]  ( Physical )
    { 1 , 3 , 15 , -1 , -1 },	 // 	Spotlight [ Normal ]  ( Status )
    { 4 , 3 , 20 , -1 , 100 },	 // 	Toxic Thread [ Poison ]  ( Status )
    { 1 , 3 , 30 , -1 , -1 },	 // 	Laser Focus [ Normal ]  ( Status )
    { 9 , 3 , 20 , -1 , -1 },	 // 	Gear Up [ Steel ]  ( Status )
    { 17 , 1 , 15 , 80 , 100 },	 // 	Throat Chop [ Dark ]  ( Physical )
    { 7 , 2 , 15 , 90 , 100 },	 // 	Pollen Puff [ Bug ]  ( Special )
    { 9 , 1 , 20 , 80 , 100 },	 // 	Anchor Shot [ Steel ]  ( Physical )
    { 14 , 3 , 10 , -1 , -1 },	 // 	Psychic Terrain [ Psychic ]  ( Status )
    { 7 , 1 , 15 , 80 , 100 },	 // 	Lunge [ Bug ]  ( Physical )
    { 10 , 1 , 15 , 80 , 100 },	 // 	Fire Lash [ Fire ]  ( Physical )
    { 17 , 1 , 10 , 20 , 100 },	 // 	Power Trip [ Dark ]  ( Physical )
    { 10 , 2 , 5 , 130 , 100 },	 // 	Burn Up [ Fire ]  ( Special )
    { 14 , 3 , 10 , -1 , -1 },	 // 	Speed Swap [ Psychic ]  ( Status )
    { 9 , 1 , 10 , 70 , -1 },	 // 	Smart Strike [ Steel ]  ( Physical )
    { 4 , 3 , 20 , -1 , -1 },	 // 	Purify [ Poison ]  ( Status )
    { 1 , 2 , 15 , 90 , 100 },	 // 	Revelation Dance [ Normal ]  ( Special )
    { 16 , 2 , 10 , 100 , 100 },	 // 	Core Enforcer [ Dragon ]  ( Special )
    { 12 , 1 , 15 , 70 , 100 },	 // 	Trop Kick [ Grass ]  ( Physical )
    { 14 , 3 , 15 , -1 , -1 },	 // 	Instruct [ Psychic ]  ( Status )
    { 3 , 1 , 15 , 100 , 100 },	 // 	Beak Blast [ Flying ]  ( Physical )
    { 16 , 2 , 5 , 110 , 100 },	 // 	Clanging Scales [ Dragon ]  ( Special )
    { 16 , 1 , 15 , 90 , 100 },	 // 	Dragon Hammer [ Dragon ]  ( Physical )
    { 17 , 1 , 20 , 60 , 100 },	 // 	Brutal Swing [ Dark ]  ( Physical )
    { 15 , 3 , 20 , -1 , -1 },	 // 	Aurora Veil [ Ice ]  ( Status )
    { 8 , 1 , 1 , 180 , -1 },	 // 	Sinister Arrow Raid [ Ghost ]  ( Physical )
    { 17 , 1 , 1 , 180 , -1 },	 // 	Malicious Moonsault [ Dark ]  ( Physical )
    { 11 , 2 , 1 , 195 , -1 },	 // 	Oceanic Operetta [ Water ]  ( Special )
    { 18 , 2 , 1 , -1 , -1 },	 // 	Guardian of Alola [ Fairy ]  ( Special )
    { 8 , 1 , 1 , 195 , -1 },	 // 	Soul-Stealing 7-Star Strike [ Ghost ]  ( Physical )
    { 13 , 2 , 1 , 175 , -1 },	 // 	Stoked Sparksurfer [ Electric ]  ( Special )
    { 1 , 1 , 1 , 210 , -1 },	 // 	Pulverizing Pancake [ Normal ]  ( Physical )
    { 1 , 3 , 1 , -1 , -1 },	 // 	Extreme Evoboost [ Normal ]  ( Status )
    { 14 , 2 , 1 , 185 , -1 },	 // 	Genesis Supernova [ Psychic ]  ( Special )
    { 10 , 2 , 5 , 150 , 100 },	 // 	Shell Trap [ Fire ]  ( Special )
    { 18 , 2 , 5 , 130 , 90 },	 // 	Fleur Cannon [ Fairy ]  ( Special )
    { 14 , 1 , 10 , 85 , 100 },	 // 	Psychic Fangs [ Psychic ]  ( Physical )
    { 5 , 1 , 10 , 75 , 100 },	 // 	Stomping Tantrum [ Ground ]  ( Physical )
    { 8 , 1 , 10 , 85 , 100 },	 // 	Shadow Bone [ Ghost ]  ( Physical )
    { 6 , 1 , 20 , 40 , 100 },	 // 	Accelerock [ Rock ]  ( Physical )
    { 11 , 1 , 10 , 85 , 100 },	 // 	Liquidation [ Water ]  ( Physical )
    { 14 , 2 , 10 , 160 , 100 },	 // 	Prismatic Laser [ Psychic ]  ( Special )
    { 8 , 1 , 10 , 90 , 100 },	 // 	Spectral Thief [ Ghost ]  ( Physical )
    { 9 , 1 , 5 , 100 , 100 },	 // 	Sunsteel Strike [ Steel ]  ( Physical )
    { 8 , 2 , 5 , 100 , 100 },	 // 	Moongeist Beam [ Ghost ]  ( Special )
    { 1 , 3 , 20 , -1 , -1 },	 // 	Tearful Look [ Normal ]  ( Status )
    { 13 , 1 , 10 , 80 , 100 },	 // 	Zing Zap [ Electric ]  ( Physical )
    { 18 , 2 , 10 , -1 , 90 },	 // 	Nature's Madness [ Fairy ]  ( Special )
    { 1 , 1 , 10 , 90 , 100 },	 // 	Multi-Attack [ Normal ]  ( Physical )
    { 13 , 2 , 1 , 195 , -1 }	 // 	10,000,000 Volt Thunderbolt [ Electric ]  ( Special )
};


// // MOVE COLOR CODING
// static const unsigned char MOVE_TYPE_RED[] = {
// 255, 168, 192, 168, 168, 168, 168, 240, 152, 248, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 120, 168, 192, 168, 192, 192, 224, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 160, 168, 168, 168, 112, 168, 168, 168, 168, 168, 168, 160, 240, 240, 152, 104, 104, 104, 152, 152, 248, 104, 152, 168, 168, 168, 192, 192, 192, 192, 168, 120, 120, 120, 168, 120, 120, 160, 120, 120, 120, 168, 112, 240, 248, 248, 248, 248, 184, 224, 224, 224, 160, 248, 248, 248, 248, 248, 168, 168, 248, 112, 168, 168, 168, 168, 168, 168, 168, 112, 104, 168, 248, 248, 152, 248, 168, 168, 168, 168, 168, 168, 112, 160, 160, 224, 240, 104, 104, 168, 168, 168, 168, 248, 248, 168, 192, 168, 248, 160, 168, 168, 168, 168, 168, 104, 168, 120, 168, 248, 168, 160, 104, 168, 168, 224, 248, 184, 168, 168, 168, 168, 168, 168, 168, 168, 168, 192, 112, 168, 168, 112, 240, 168, 112, 168, 168, 168, 120, 192, 112, 152, 168, 192, 168, 112, 238, 168, 160, 224, 104, 224, 248, 168, 112, 168, 152, 192, 224, 168, 112, 184, 120, 168, 238, 184, 168, 168, 168, 248, 168, 184, 168, 168, 168, 168, 168, 168, 168, 168, 168, 240, 224, 192, 168, 112, 168, 168, 112, 168, 168, 184, 184, 192, 168, 120, 238, 168, 192, 112, 104, 240, 112, 248, 168, 168, 184, 112, 248, 192, 104, 112, 168, 168, 168, 168, 168, 240, 152, 112, 112, 240, 112, 168, 192, 168, 168, 168, 248, 112, 168, 248, 248, 168, 168, 120, 192, 248, 168, 192, 192, 168, 112, 168, 240, 248, 248, 168, 112, 112, 168, 104, 192, 168, 168, 248, 248, 168, 168, 240, 224, 152, 120, 168, 168, 160, 168, 240, 104, 184, 112, 168, 120, 112, 168, 240, 168, 184, 168, 184, 120, 168, 248, 104, 168, 112, 248, 192, 224, 152, 104, 120, 168, 152, 184, 168, 168, 112, 120, 192, 168, 224, 160, 168, 248, 120, 104, 248, 120, 112, 184, 248, 104, 184, 248, 168, 248, 248, 192, 192, 184, 248, 104, 168, 168, 168, 168, 168, 184, 168, 192, 112, 112, 112, 112, 248, 168, 248, 168, 248, 160, 168, 168, 168, 248, 248, 112, 168, 120, 112, 160, 248, 104, 248, 240, 192, 192, 184, 160, 112, 112, 104, 120, 168, 168, 168, 112, 112, 184, 192, 192, 192, 120, 168, 224, 112, 168, 112, 184, 152, 152, 112, 248, 152, 240, 112, 224, 248, 248, 184, 184, 168, 168, 248, 112, 248, 240, 120, 120, 184, 160, 160, 184, 184, 184, 168, 184, 120, 168, 168, 168, 248, 120, 104, 168, 168, 168, 184, 168, 112, 112, 248, 168, 240, 112, 120, 112, 112, 112, 184, 248, 248, 248, 248, 160, 184, 168, 248, 248, 184, 192, 240, 160, 168, 184, 248, 248, 104, 240, 160, 192, 160, 112, 168, 168, 168, 168, 168, 168, 160, 248, 192, 248, 104, 168, 248, 112, 168, 184, 192, 240, 112, 168, 168, 168, 192, 168, 240, 104, 240, 120, 248, 168, 224, 152, 112, 168, 248, 248, 224, 112, 248, 120, 192, 104, 240, 120, 168, 120, 112, 248, 168, 168, 168, 184, 240, 168, 168, 192, 152, 248, 240, 240, 152, 152, 112, 152, 240, 240, 248, 192, 192, 160, 224, 168, 168, 112, 112, 168, 248, 248, 120, 120, 152, 238, 112, 112, 238, 238, 238, 120, 238, 248, 238, 238, 238, 168, 238, 184, 168, 168, 184, 104, 248, 104, 240, 120, 238, 248, 160, 168, 238, 248, 168, 248, 238, 168, 168, 238, 248, 168, 168, 192, 168, 224, 224, 224, 238, 104, 224, 168, 112, 168, 168, 192, 192, 168, 168, 160, 160, 224, 224, 184, 184, 168, 168, 112, 112, 184, 184, 240, 240, 104, 104, 120, 120, 248, 248, 248, 248, 152, 152, 112, 112, 112, 112, 238, 238, 248, 224, 168, 160, 112, 112, 104, 152, 238, 224, 120, 120, 120, 168, 160, 168, 184, 112, 168, 184, 248, 168, 240, 112, 240, 248, 184, 160, 168, 112, 120, 248, 168, 112, 112, 112, 152, 112, 112, 104, 238, 112, 248, 168, 168, 248, 240, 238, 248, 224, 112, 184, 104, 248, 112, 184, 112, 168, 248, 238, 168, 248
// };
// static const unsigned char MOVE_TYPE_GREEN[] = {
// 255, 168, 48, 168, 168, 168, 168, 128, 216, 208, 168, 168, 168, 168, 168, 168, 144, 144, 168, 144, 168, 168, 200, 168, 48, 168, 48, 48, 192, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 64, 184, 184, 168, 88, 168, 168, 168, 168, 168, 168, 64, 128, 128, 216, 144, 144, 144, 216, 216, 88, 144, 216, 168, 144, 144, 48, 48, 48, 48, 168, 200, 200, 200, 168, 200, 200, 64, 200, 200, 200, 184, 56, 128, 208, 208, 208, 208, 160, 192, 192, 192, 64, 88, 88, 88, 88, 88, 168, 168, 88, 88, 168, 168, 168, 168, 168, 168, 168, 88, 144, 168, 88, 88, 216, 88, 168, 168, 168, 144, 168, 168, 88, 64, 64, 192, 128, 144, 144, 168, 168, 168, 168, 88, 88, 168, 48, 168, 88, 64, 168, 184, 168, 144, 168, 144, 168, 200, 168, 88, 168, 64, 144, 168, 168, 192, 88, 160, 168, 168, 168, 168, 168, 168, 168, 168, 168, 48, 88, 184, 168, 88, 128, 168, 88, 168, 168, 144, 200, 48, 88, 216, 168, 48, 168, 88, 153, 168, 64, 192, 144, 192, 208, 168, 88, 168, 216, 48, 192, 168, 56, 160, 200, 168, 153, 160, 168, 168, 168, 208, 184, 184, 168, 168, 168, 168, 168, 168, 168, 168, 168, 128, 192, 48, 184, 56, 168, 168, 88, 168, 168, 184, 184, 48, 168, 200, 153, 168, 48, 56, 144, 128, 88, 88, 168, 168, 160, 88, 88, 48, 144, 88, 168, 168, 168, 168, 168, 128, 216, 88, 88, 128, 88, 168, 48, 168, 168, 168, 208, 88, 168, 88, 88, 168, 168, 200, 48, 88, 168, 48, 48, 168, 88, 168, 128, 88, 88, 168, 88, 88, 168, 144, 48, 168, 184, 88, 88, 144, 168, 128, 192, 216, 200, 168, 168, 64, 168, 128, 144, 184, 88, 168, 200, 88, 144, 128, 168, 160, 184, 184, 200, 168, 88, 144, 184, 88, 88, 48, 192, 216, 144, 200, 144, 216, 184, 168, 168, 56, 200, 48, 144, 192, 64, 168, 208, 200, 144, 88, 200, 56, 160, 208, 144, 184, 88, 144, 88, 88, 48, 48, 184, 88, 144, 168, 168, 144, 144, 168, 184, 184, 48, 88, 88, 88, 88, 88, 168, 88, 168, 88, 64, 168, 168, 168, 88, 88, 88, 168, 200, 88, 64, 88, 144, 208, 128, 48, 48, 160, 64, 88, 88, 144, 200, 144, 184, 184, 56, 56, 160, 48, 48, 48, 200, 144, 192, 88, 168, 88, 184, 216, 216, 88, 208, 216, 128, 88, 192, 88, 88, 184, 184, 168, 144, 88, 56, 208, 128, 200, 200, 160, 64, 64, 184, 184, 160, 168, 160, 200, 144, 168, 184, 208, 200, 144, 184, 184, 184, 160, 168, 56, 56, 88, 168, 128, 88, 200, 88, 88, 88, 160, 88, 88, 88, 88, 64, 184, 184, 88, 88, 160, 48, 128, 64, 184, 184, 88, 208, 144, 128, 64, 48, 64, 88, 168, 168, 168, 168, 168, 168, 64, 88, 48, 88, 144, 168, 88, 88, 144, 184, 48, 128, 88, 144, 168, 168, 48, 168, 128, 144, 128, 200, 208, 184, 192, 216, 56, 168, 208, 208, 192, 56, 88, 200, 48, 144, 128, 200, 184, 200, 88, 88, 168, 144, 168, 184, 128, 168, 168, 48, 216, 208, 128, 128, 216, 216, 88, 216, 128, 128, 208, 48, 48, 64, 192, 184, 184, 88, 88, 168, 208, 208, 200, 200, 216, 153, 88, 88, 153, 153, 153, 200, 153, 208, 153, 153, 153, 168, 153, 184, 168, 168, 160, 144, 88, 144, 128, 200, 153, 208, 64, 184, 153, 208, 168, 208, 153, 168, 168, 153, 208, 168, 184, 48, 144, 192, 192, 192, 153, 144, 192, 144, 88, 168, 168, 48, 48, 144, 144, 64, 64, 192, 192, 160, 160, 184, 184, 88, 88, 184, 184, 128, 128, 144, 144, 200, 200, 208, 208, 88, 88, 216, 216, 56, 56, 88, 88, 153, 153, 208, 192, 184, 64, 88, 88, 144, 216, 153, 192, 200, 200, 200, 168, 64, 168, 184, 88, 184, 184, 88, 184, 128, 88, 128, 88, 184, 64, 168, 56, 200, 88, 144, 56, 56, 88, 216, 88, 88, 144, 153, 88, 208, 168, 168, 88, 128, 153, 88, 192, 88, 160, 144, 88, 88, 184, 88, 168, 208, 153, 168, 208
// };
// static const unsigned char MOVE_TYPE_BLUE[] = {
// 255, 120, 40, 120, 120, 120, 120, 48, 216, 48, 120, 120, 120, 120, 120, 120, 240, 240, 120, 240, 120, 120, 80, 120, 40, 120, 40, 40, 104, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 160, 32, 32, 120, 72, 120, 120, 120, 120, 120, 120, 160, 48, 48, 216, 240, 240, 240, 216, 216, 136, 240, 216, 120, 240, 240, 40, 40, 40, 40, 120, 80, 80, 80, 120, 80, 80, 160, 80, 80, 80, 32, 248, 48, 48, 48, 48, 48, 56, 104, 104, 104, 160, 136, 136, 136, 136, 136, 120, 120, 136, 152, 120, 120, 120, 120, 120, 120, 120, 152, 240, 120, 136, 136, 216, 136, 120, 120, 120, 240, 120, 120, 152, 160, 160, 104, 48, 240, 240, 120, 120, 120, 120, 136, 136, 120, 40, 120, 136, 160, 120, 32, 120, 240, 120, 240, 120, 80, 120, 136, 120, 160, 240, 120, 120, 104, 136, 56, 120, 120, 120, 120, 120, 120, 120, 120, 120, 40, 72, 32, 120, 152, 48, 120, 152, 120, 120, 240, 80, 40, 152, 216, 120, 40, 120, 72, 172, 120, 160, 104, 240, 104, 48, 120, 152, 120, 216, 40, 104, 120, 248, 56, 80, 120, 172, 56, 120, 120, 120, 48, 32, 208, 120, 120, 120, 120, 120, 120, 120, 120, 120, 48, 104, 40, 32, 248, 120, 120, 72, 120, 120, 208, 208, 40, 120, 80, 172, 120, 40, 248, 240, 48, 72, 136, 120, 120, 56, 152, 136, 40, 240, 72, 120, 120, 120, 120, 120, 48, 216, 72, 72, 48, 72, 120, 40, 120, 120, 120, 48, 72, 120, 136, 136, 120, 120, 80, 40, 136, 120, 40, 40, 120, 72, 120, 48, 136, 136, 120, 152, 72, 120, 240, 40, 120, 32, 136, 136, 240, 120, 48, 104, 216, 80, 120, 120, 160, 120, 48, 240, 208, 152, 120, 80, 72, 240, 48, 120, 56, 32, 208, 80, 120, 136, 240, 32, 152, 136, 40, 104, 216, 240, 80, 240, 216, 208, 120, 120, 248, 80, 40, 240, 104, 160, 120, 48, 80, 240, 136, 80, 248, 56, 48, 240, 208, 136, 240, 136, 136, 40, 40, 208, 136, 240, 120, 120, 240, 240, 120, 208, 32, 40, 72, 72, 72, 72, 136, 120, 136, 120, 136, 160, 120, 120, 120, 136, 136, 72, 120, 80, 72, 160, 136, 240, 48, 48, 40, 40, 56, 160, 72, 72, 240, 80, 240, 32, 32, 248, 248, 56, 40, 40, 40, 80, 240, 104, 72, 120, 72, 208, 216, 216, 152, 48, 216, 48, 152, 104, 136, 136, 208, 208, 120, 240, 136, 248, 48, 48, 80, 80, 56, 160, 160, 208, 208, 56, 120, 56, 80, 240, 120, 32, 48, 80, 240, 32, 32, 32, 56, 120, 248, 248, 136, 120, 48, 72, 80, 152, 152, 72, 56, 136, 136, 136, 136, 160, 208, 32, 136, 136, 56, 40, 48, 160, 32, 208, 136, 48, 240, 48, 160, 40, 160, 72, 120, 120, 120, 120, 120, 120, 160, 136, 40, 136, 240, 120, 136, 152, 240, 208, 40, 48, 72, 240, 120, 120, 40, 120, 48, 240, 48, 80, 48, 32, 104, 216, 248, 120, 48, 48, 104, 248, 136, 80, 40, 240, 48, 80, 32, 80, 72, 136, 120, 240, 120, 208, 48, 120, 120, 40, 216, 48, 48, 48, 216, 216, 72, 216, 48, 48, 48, 40, 40, 160, 104, 32, 32, 152, 152, 120, 48, 48, 80, 80, 216, 172, 72, 72, 172, 172, 172, 80, 172, 48, 172, 172, 172, 120, 172, 208, 120, 120, 56, 240, 136, 240, 48, 80, 172, 48, 160, 32, 172, 48, 120, 48, 172, 120, 120, 172, 48, 120, 32, 40, 240, 104, 104, 104, 172, 240, 104, 240, 72, 120, 120, 40, 40, 240, 240, 160, 160, 104, 104, 56, 56, 32, 32, 152, 152, 208, 208, 48, 48, 240, 240, 80, 80, 48, 48, 136, 136, 216, 216, 248, 248, 72, 72, 172, 172, 48, 104, 32, 160, 152, 72, 240, 216, 172, 104, 80, 80, 80, 120, 160, 120, 208, 72, 32, 208, 136, 32, 48, 72, 48, 136, 208, 160, 120, 248, 80, 136, 240, 248, 248, 72, 216, 152, 72, 240, 172, 152, 48, 120, 120, 136, 48, 172, 136, 104, 152, 56, 240, 136, 152, 208, 152, 120, 48, 172, 120, 48
// };


// static const short MOVE_DAMAGE[] = {
// -1, 40, 50, 15, 18, 80, 40, 75, 75, 75, 40, 55, -1, 80, -1, 50, 40, 60, -1, 90, 15, 80, 45, 65, 30, 120, 100, 60, -1, 70, 65, 15, -1, 40, 85, 15, 90, 120, 120, -1, 15, 25, 25, -1, 60, -1, -1, -1, -1, -1, -1, 40, 40, 90, -1, 40, 110, 90, 90, 110, 65, 65, 65, 150, 35, 80, 80, -1, -1, -1, 80, 20, 40, -1, -1, 55, 120, -1, -1, -1, 120, -1, -1, 35, 40, 90, -1, 110, 50, 100, -1, 80, -1, 50, 90, -1, -1, -1, 40, 20, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 200, 100, 30, 30, 65, 65, 110, 80, 35, 60, 130, 20, 10, -1, -1, -1, 130, -1, 100, -1, 15, 80, -1, 140, -1, 40, 70, -1, -1, -1, -1, -1, 100, 250, 18, 50, -1, 75, 80, -1, -1, 80, -1, 70, -1, 50, -1, 10, 60, -1, -1, -1, 60, 50, -1, -1, -1, 100, -1, -1, -1, 40, -1, 40, -1, 60, -1, -1, 90, 20, 65, -1, 120, -1, -1, -1, 55, -1, 25, -1, 120, -1, 75, -1, -1, 30, 40, -1, -1, 65, 40, 70, -1, -1, -1, -1, -1, -1, -1, -1, -1, 100, -1, 100, 120, 60, -1, -1, 40, 20, -1, 100, 50, 70, -1, -1, -1, 60, 100, 40, -1, -1, 80, -1, -1, 80, 60, 80, 120, 40, 35, -1, 40, 90, -1, -1, -1, 95, -1, -1, -1, -1, -1, 70, 150, 70, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 120, -1, -1, 60, 75, -1, 65, -1, 150, -1, -1, -1, -1, -1, 70, 80, 15, -1, -1, 70, 70, -1, -1, 85, -1, 30, 60, -1, 90, 50, 75, 150, 150, 90, 30, 50, -1, -1, 60, 130, -1, 60, 60, -1, -1, -1, -1, 150, 75, 60, 80, 85, 35, -1, 90, 25, 60, 25, -1, -1, -1, 80, 150, -1, 85, 55, 50, 60, 120, 60, -1, -1, 90, -1, 25, 60, 60, 140, 140, -1, -1, -1, 70, 100, -1, -1, 65, -1, 30, 60, -1, -1, -1, 70, 120, 50, 60, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 140, -1, 70, -1, -1, -1, -1, 120, 60, 80, -1, 80, 80, 70, 90, 80, 75, 80, 90, 85, 100, 80, 75, 40, 120, 90, 120, 90, -1, 150, -1, 40, 60, 40, 70, 65, 65, 65, 40, 65, 70, 80, 65, 80, 90, -1, -1, 130, 80, 80, 130, 120, 150, 70, 120, 80, 60, 100, -1, -1, -1, 65, 100, 60, 50, 120, 40, 90, -1, -1, 150, 35, 150, 100, -1, -1, 120, -1, 120, 60, 120, -1, -1, -1, -1, -1, 80, 65, -1, -1, -1, -1, 50, 60, 70, 95, -1, -1, 120, -1, -1, 50, -1, 65, 40, 95, -1, -1, -1, 60, 40, 70, 50, 20, -1, -1, 80, -1, -1, 65, 60, -1, 60, 60, -1, 55, -1, 70, -1, -1, 100, 80, 80, 80, 70, 50, 60, 60, 60, -1, 55, 90, 80, 40, 60, 75, 90, 75, -1, 65, 65, -1, 85, 100, 25, 110, 120, 50, 100, 120, 75, 85, 65, 130, 130, 80, 140, 140, 55, 85, 180, 100, 100, 100, -1, 120, -1, -1, 50, 90, -1, -1, -1, 65, -1, 90, 70, 40, -1, -1, 50, -1, -1, -1, -1, -1, 90, 40, 95, 140, -1, -1, -1, -1, 100, 110, 80, 15, 75, -1, -1, -1, -1, -1, -1, -1, -1, -1, 80, -1, -1, -1, 20, 40, 20, 40, 80, 90, 90, 90, 140, 110, 120, 120, 100, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 210, -1, 90, -1, 80, 85, 90, 100, -1, 95, -1, 125, 40, -1, -1, -1, -1, 80, 90, 80, -1, 80, 80, 20, 130, -1, 70, -1, 90, 100, 70, -1, 100, 110, 90, 60, -1, 180, 180, 195, -1, 195, 175, 210, -1, 185, 150, 130, 85, 75, 85, 40, 85, 160, 90, 100, 100, -1, 80, -1, 90, 195
// };
//
// // MOVE ACCURACY
// static const short MOVE_ACC[] = {
// -1, 100, 100, 85, 85, 85, 100, 100, 100, 100, 100, 100, -1, 100, -1, 95, 100, 100, -1, 95, 85, 75, 100, 100, 100, 75, 95, 85, 100, 100, 100, 85, -1, 100, 100, 90, 85, 100, 100, 100, 100, 100, 95, 100, 100, 100, -1, 55, 55, 90, 100, 100, 100, 100, -1, 100, 80, 100, 100, 70, 100, 100, 100, 90, 100, 100, 80, 100, 100, 100, 100, 100, 100, 90, -1, 95, 100, 75, 75, 75, 100, 95, 100, 85, 100, 100, 90, 70, 90, 100, -1, 100, 90, 100, 100, 60, -1, -1, 100, 100, -1, 100, -1, 85, -1, -1, -1, -1, 100, 100, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 100, 75, 100, 70, 100, 85, 85, 100, 85, 999, 100, 100, 100, -1, 80, -1, 90, 100, 100, 90, 85, 100, 75, 90, -1, 100, 100, 100, 100, 80, -1, -1, 90, 100, 80, 90, -1, 90, 90, -1, -1, 100, 90, 100, -1, 100, -1, 90, 100, -1, -1, 100, 100, 100, -1, 100, -1, 95, 100, 100, 100, 100, -1, 100, 100, 999, 75, -1, 100, 100, 85, -1, 50, -1, -1, -1, 95, -1, 90, -1, 100, -1, 100, -1, 100, 90, 100, 85, -1, 100, 95, 90, -1, 100, -1, -1, 100, 90, 100, -1, -1, 95, 100, 50, 85, 100, -1, 100, 100, 100, -1, 75, 95, 999, -1, -1, -1, 100, 80, 100, -1, -1, 100, 100, -1, 100, 100, 100, 100, 100, 85, 100, 100, 100, -1, 100, -1, 90, -1, 100, 100, 85, 100, 100, 100, 100, -1, -1, -1, 100, -1, 100, -1, -1, -1, -1, 100, -1, -1, 100, 100, -1, 100, 100, 100, -1, -1, -1, -1, -1, 100, 100, 100, -1, -1, 100, 100, 100, 100, 90, -1, 90, 100, -1, 100, 100, 95, 90, 90, 90, 100, 100, -1, 100, 95, 90, -1, 95, 100, 85, 55, 100, -1, 100, 100, 999, 100, 90, 85, -1, 85, 100, 999, 100, -1, -1, -1, 100, 90, -1, 85, 95, 100, 100, 100, 999, -1, -1, 100, -1, 90, 999, 100, 100, 90, -1, -1, -1, 100, 90, 100, -1, 100, 100, 100, 100, -1, -1, 100, 100, 100, 100, 100, 100, 100, 90, 999, -1, 100, -1, 100, -1, -1, -1, -1, -1, 100, 100, 100, 100, -1, -1, -1, -1, 100, 100, 999, -1, 100, 100, 100, 90, 100, 95, 100, 100, 100, 75, 100, 100, 100, 70, 100, 100, 100, 100, 90, -1, 100, 100, 100, 100, 95, 95, 95, 100, 85, 100, 90, 85, 100, 85, -1, -1, 90, 100, 100, 90, 85, 90, 100, 80, 100, 999, 80, 100, -1, 100, 100, 100, 100, 90, 100, 100, 100, -1, -1, 80, 90, 90, 95, -1, 100, 75, 50, 85, 100, 100, -1, -1, -1, -1, -1, 100, 100, -1, -1, -1, -1, 100, 100, 100, 100, -1, 100, 100, 100, 100, 100, -1, 100, 100, 100, 100, 100, -1, 100, 100, 100, -1, 100, -1, -1, 100, -1, -1, 100, 100, -1, 90, 100, 100, 100, -1, 100, 100, -1, 50, 100, 100, 100, 100, 100, 100, 90, 90, -1, 95, 100, 95, 90, 100, 100, 100, 95, 100, 90, 100, -1, 95, 100, 85, 70, 100, 85, 100, 100, 100, 100, 95, 85, 85, 100, 90, 90, 95, 90, 95, 100, 100, 95, -1, 90, -1, -1, 100, 100, 100, 100, -1, 100, 100, 100, 100, 999, 100, -1, 100, -1, -1, -1, -1, -1, 90, 100, 100, 100, -1, -1, -1, -1, 95, 95, 999, 100, 100, -1, -1, 100, 100, 100, -1, -1, -1, -1, 100, -1, -1, 100, 100, 100, 100, 100, 100, 100, 100, 100, 90, 85, 85, 100, 999, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 100, -1, 100, 100, 100, 90, -1, 95, 100, 100, 100, -1, 100, -1, -1, 100, 100, 100, -1, 100, 100, 100, 100, -1, -1, -1, 100, 100, 100, -1, 100, 100, 100, 100, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 100, 90, 100, 100, 100, 100, 100, 100, 100, 100, 100, -1, 100, 90, 100, -1
// };
//
// // MOVE PP
// static const char MOVE_PP[] = {
// -1, 35, 25, 10, 15, 20, 20, 15, 15, 15, 35, 30, 5, 10, 20, 30, 35, 35, 20, 15, 20, 20, 25, 20, 30, 5, 10, 15, 15, 15, 25, 20, 5, 35, 15, 20, 20, 10, 15, 30, 35, 20, 20, 30, 25, 40, 20, 15, 20, 20, 20, 30, 25, 15, 30, 25, 5, 15, 10, 5, 20, 20, 20, 5, 35, 20, 20, 20, 20, 20, 15, 25, 15, 10, 40, 25, 10, 35, 30, 15, 10, 40, 10, 15, 30, 15, 20, 10, 15, 10, 5, 10, 10, 25, 10, 20, 40, 30, 30, 20, 20, 15, 10, 40, 15, 10, 30, 10, 20, 10, 40, 40, 20, 30, 30, 20, 30, 10, 10, 20, 5, 10, 30, 20, 20, 20, 5, 15, 10, 20, 10, 15, 35, 20, 15, 10, 10, 30, 15, 40, 20, 10, 10, 5, 10, 30, 10, 15, 20, 15, 40, 20, 10, 5, 15, 10, 10, 10, 15, 30, 30, 10, 10, 20, 10, -1, 1, 10, 25, 10, 5, 15, 25, 15, 10, 15, 30, 5, 40, 15, 10, 25, 10, 30, 10, 20, 10, 10, 10, 10, 10, 20, 5, 40, 5, 5, 15, 5, 10, 5, 10, 10, 10, 10, 20, 20, 40, 15, 10, 20, 20, 25, 5, 15, 10, 5, 20, 15, 20, 25, 20, 5, 30, 5, 10, 20, 40, 5, 20, 40, 20, 15, 35, 10, 5, 5, 5, 15, 5, 20, 5, 5, 15, 20, 10, 5, 5, 15, 10, 15, 15, 30, 10, 10, 20, 10, 10, 10, 10, 15, 15, 15, 10, 20, 20, 10, 20, 20, 20, 20, 20, 10, 15, 10, 20, 20, 5, 15, 10, 10, 15, 10, 20, 5, 5, 10, 10, 20, 5, 10, 20, 10, 20, 20, 20, 5, 5, 15, 20, 10, 15, 20, 15, 10, 10, 15, 10, 5, 5, 10, 15, 10, 5, 20, 25, 5, 40, 15, 5, 40, 15, 20, 20, 5, 15, 20, 20, 15, 15, 5, 10, 30, 20, 30, 15, 5, 40, 15, 5, 20, 5, 15, 25, 25, 15, 20, 15, 20, 15, 20, 10, 20, 20, 5, 5, 10, 5, 40, 10, 10, 5, 10, 10, 15, 10, 20, 30, 30, 10, 20, 5, 10, 10, 15, 10, 10, 5, 15, 5, 10, 10, 30, 20, 20, 10, 10, 5, 5, 10, 5, 20, 10, 20, 10, 15, 10, 20, 20, 20, 15, 15, 10, 15, 20, 15, 10, 10, 10, 20, 10, 30, 5, 10, 15, 10, 15, 5, 20, 30, 10, 30, 15, 15, 15, 15, 30, 10, 20, 15, 10, 10, 20, 15, 5, 5, 15, 15, 5, 10, 5, 20, 5, 15, 20, 5, 20, 20, 20, 20, 10, 20, 10, 15, 20, 15, 10, 10, 5, 10, 5, 5, 10, 5, 5, 10, 5, 5, 5, 15, 10, 10, 10, 10, 10, 10, 15, 20, 15, 10, 15, 10, 15, 10, 20, 10, 15, 10, 20, 20, 20, 20, 20, 15, 15, 15, 15, 15, 15, 20, 15, 10, 15, 15, 15, 15, 10, 10, 10, 10, 10, 15, 15, 15, 15, 5, 5, 15, 5, 10, 10, 10, 20, 20, 20, 10, 10, 30, 15, 15, 10, 15, 25, 10, 20, 10, 10, 10, 20, 10, 10, 10, 10, 10, 15, 15, 5, 5, 10, 10, 10, 5, 5, 10, 5, 5, 15, 10, 5, 5, 5, 10, 10, 10, 10, 20, 25, 10, 20, 30, 25, 20, 20, 15, 20, 15, 20, 20, 10, 10, 10, 10, 10, 20, 10, 30, 15, 10, 10, 10, 20, 20, 5, 5, 5, 20, 10, 10, 20, 15, 20, 20, 10, 20, 30, 10, 10, 40, 40, 30, 20, 40, 20, 10, 10, 10, 10, 10, 5, 10, 10, 5, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 40, 15, 20, 30, 20, 15, 15, 20, 10, 15, 15, 10, 5, 10, 10, 20, 15, 10, 15, 15, 15, 5, 15, 20, 20, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 10, 10, 10, 20, 10, 10, 10, 5, 5, 20, 10, 10, 10, 1
// };

// CATCH RATE PER POKEMON
static const unsigned char CATCH_RATE[] = { 45,45,45,45,45,45,45,45,45,255,120,45,255,120,45,255,120,45,255,127,255,90,255,90,190,75,255,90,235,120,45,235,120,45,150,25,190,75,170,50,255,90,255,120,45,190,75,190,75,255,50,255,90,190,75,190,75,190,75,255,120,45,200,100,50,180,90,45,255,120,45,190,60,255,120,45,190,60,190,75,190,60,45,190,45,190,75,190,75,190,60,190,90,45,45,190,75,225,60,190,60,90,45,190,75,45,45,45,190,60,120,60,30,45,45,225,75,225,60,225,60,45,45,45,45,45,45,45,255,45,45,35,45,45,45,45,45,45,45,45,45,45,25,3,3,3,45,45,45,3,45,45,45,45,45,45,45,45,45,45,255,90,255,90,255,90,255,90,90,190,75,190,150,170,190,75,190,75,235,120,45,45,190,75,65,45,255,120,45,45,235,120,75,255,90,45,45,30,70,45,225,45,60,190,75,190,60,25,190,75,45,25,190,45,60,120,60,190,75,225,75,60,190,75,45,25,25,120,45,45,120,60,45,45,45,75,45,45,45,45,45,30,3,3,3,45,45,45,3,3,45,45,45,45,45,45,45,45,45,45,255,127,255,90,255,120,45,120,45,255,120,45,255,120,45,200,45,190,45,235,120,45,200,75,255,90,255,120,45,255,120,45,190,120,45,180,200,150,255,255,60,45,45,180,90,45,180,90,120,45,200,200,150,150,150,225,75,225,60,125,60,255,150,90,255,60,255,255,120,45,190,60,255,45,90,90,45,45,190,75,205,155,255,90,45,45,45,45,255,60,45,200,225,45,190,90,200,45,30,125,190,75,255,120,45,255,60,60,25,225,45,45,45,3,3,3,3,3,3,3,3,3,3,45,3,3,45,45,45,45,45,45,45,45,45,255,120,45,255,127,255,45,235,120,45,255,75,45,45,45,45,120,45,45,120,45,200,190,75,190,75,190,75,45,125,60,190,60,45,30,190,75,120,225,60,255,90,255,145,130,30,100,45,45,45,50,75,45,140,60,120,45,140,75,200,190,75,25,120,60,45,30,30,30,30,30,30,30,30,45,45,30,50,30,45,60,45,75,45,3,3,3,3,3,3,3,3,3,30,3,3,45,3,3,45,45,45,45,45,45,45,45,45,255,255,255,120,45,255,90,190,75,190,75,190,75,190,75,255,120,45,190,75,255,120,45,190,45,120,60,255,180,90,45,255,120,45,45,45,255,120,45,255,120,45,190,75,190,75,25,180,90,45,120,60,255,190,75,180,90,45,190,90,45,45,45,45,190,60,75,45,255,60,200,100,50,200,100,50,190,45,255,120,45,190,75,200,200,75,190,75,190,60,75,190,75,255,90,130,60,30,190,60,30,255,90,190,90,45,75,60,45,120,60,25,200,75,75,180,45,45,190,90,120,45,45,190,60,190,60,90,90,45,45,45,45,15,3,3,3,3,3,3,3,3,3,3,3,3,45,45,45,45,45,45,45,45,45,255,127,255,120,45,255,120,45,220,65,225,120,45,200,45,220,65,160,190,75,180,90,45,200,140,200,140,190,80,120,45,225,55,225,55,190,75,45,45,45,45,45,100,180,60,45,45,45,75,120,60,120,60,190,55,190,45,45,45,3,3,3,3,45,45,45,45,45,45,45,45,45,255,120,45,255,127,255,120,45,225,60,45,190,75,190,90,60,190,75,190,60,200,100,190,75,190,75,120,45,140,70,235,120,45,60,45,45,90,45,140,60,60,3,3,30,45,70,180,45,80,70,25,45,45,45,3,3,3,3,45,45,45,45,45,25,255,30,25,255,15,3,3,3
};
