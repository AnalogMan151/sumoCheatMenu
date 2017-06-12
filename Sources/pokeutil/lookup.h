
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
    "Mental Herb", "Choice Band", "King’s Rock", "Silver Powder", "Amulet Coin",
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
    "Bike", "Suite Key", "Oak’s Letter", "Lunar Wing", "Member Card",
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
    "Prof’s Letter", "Roller Skates", "Pixie Plate", "Ability Capsule",
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
    "Forage Bag", "Fishing Rod", "Professor’s Mask", "Festival Ticket",
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
    "[None]", "Pound", "Karate Chop", "Double Slap", "Comet Punch",
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
    "Noble Roar", "Ion Deluge", "Parabolic Charge", "Forest’s Curse",
    "Petal Blizzard", "Freeze-Dry", "Disarming Voice", "Parting Shot",
    "Topsy-Turvy", "Draining Kiss", "Crafty Shield", "Flower Shield",
    "Grassy Terrain", "Misty Terrain", "Electrify", "Play Rough", "Fairy Wind",
    "Moonblast", "Boomburst", "Fairy Lock", "King’s Shield", "Play Nice",
    "Confide", "Diamond Storm", "Steam Eruption", "Hyperspace Hole",
    "Water Shuriken", "Mystical Fire", "Spiky Shield", "Aromatic Mist",
    "Eerie Impulse", "Venom Drench", "Powder", "Geomancy", "Magnetic Flux",
    "Happy Hour", "Electric Terrain", "Dazzling Gleam", "Celebrate",
    "Hold Hands", "Baby-Doll Eyes", "Nuzzle", "Hold Back", "Infestation",
    "Power-Up Punch", "Oblivion Wing", "Thousand Arrows", "Thousand Waves",
    "Land’s Wrath", "Light of Ruin", "Origin Pulse", "Precipice Blades",
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
    "Tearful Look", "Zing Zap", "Nature’s Madness", "Multi-Attack",
    "10,000,000 Volt Thunderbolt"
};




static const char *POKEMON_LOOKUP_NAME[][6][1] = {
	{
	    {"Bulbasaur"}
	},{
	    {"Ivysaur"}
	},{
	    {"Venusaur"},
	    {"Venusaur (Mega Venusaur)"}
	},{
	    {"Charmander"}
	},{
	    {"Charmeleon"}
	},{
	    {"Charizard"},
	    {"Charizard (Mega Charizard X)"},
	    {"Charizard (Mega Charizard Y)"}
	},{
	    {"Squirtle"}
	},{
	    {"Wartortle"}
	},{
	    {"Blastoise"},
	    {"Blastoise (Mega Blastoise)"}
	},{
	    {"Caterpie"}
	},{
	    {"Metapod"}
	},{
	    {"Butterfree"}
	},{
	    {"Weedle"}
	},{
	    {"Kakuna"}
	},{
	    {"Beedrill"},
	    {"Beedrill (Mega Beedrill)"}
	},{
	    {"Pidgey"}
	},{
	    {"Pidgeotto"}
	},{
	    {"Pidgeot"},
	    {"Pidgeot (Mega Pidgeot)"}
	},{
	    {"Rattata"},
	    {"Rattata (Alolan Rattata)"}
	},{
	    {"Raticate"},
	    {"Raticate (Alolan Raticate)"}
	},{
	    {"Spearow"}
	},{
	    {"Fearow"}
	},{
	    {"Ekans"}
	},{
	    {"Arbok"}
	},{
	    {"Pikachu"}
	},{
	    {"Raichu"},
	    {"Raichu (Alolan Raichu)"}
	},{
	    {"Sandshrew"},
	    {"Sandshrew (Alolan Sandshrew)"}
	},{
	    {"Sandslash"},
	    {"Sandslash (Alolan Sandslash)"}
	},{
	    {"Nidoran♀"}
	},{
	    {"Nidorina"}
	},{
	    {"Nidoqueen"}
	},{
	    {"Nidoran♂"}
	},{
	    {"Nidorino"}
	},{
	    {"Nidoking"}
	},{
	    {"Clefairy"}
	},{
	    {"Clefable"}
	},{
	    {"Vulpix"},
	    {"Vulpix (Alolan Vulpix)"}
	},{
	    {"Ninetales"},
	    {"Ninetales (Alolan Ninetales)"}
	},{
	    {"Jigglypuff"}
	},{
	    {"Wigglytuff"}
	},{
	    {"Zubat"}
	},{
	    {"Golbat"}
	},{
	    {"Oddish"}
	},{
	    {"Gloom"}
	},{
	    {"Vileplume"}
	},{
	    {"Paras"}
	},{
	    {"Parasect"}
	},{
	    {"Venonat"}
	},{
	    {"Venomoth"}
	},{
	    {"Diglett"},
	    {"Diglett (Alolan Diglett)"}
	},{
	    {"Dugtrio"},
	    {"Dugtrio (Alolan Dugtrio)"}
	},{
	    {"Meowth"},
	    {"Meowth (Alolan Meowth)"}
	},{
	    {"Persian"},
	    {"Persian (Alolan Persian)"}
	},{
	    {"Psyduck"}
	},{
	    {"Golduck"}
	},{
	    {"Mankey"}
	},{
	    {"Primeape"}
	},{
	    {"Growlithe"}
	},{
	    {"Arcanine"}
	},{
	    {"Poliwag"}
	},{
	    {"Poliwhirl"}
	},{
	    {"Poliwrath"}
	},{
	    {"Abra"}
	},{
	    {"Kadabra"}
	},{
	    {"Alakazam"},
	    {"Alakazam (Mega Alakazam)"}
	},{
	    {"Machop"}
	},{
	    {"Machoke"}
	},{
	    {"Machamp"}
	},{
	    {"Bellsprout"}
	},{
	    {"Weepinbell"}
	},{
	    {"Victreebel"}
	},{
	    {"Tentacool"}
	},{
	    {"Tentacruel"}
	},{
	    {"Geodude"},
	    {"Geodude (Alolan Geodude)"}
	},{
	    {"Graveler"},
	    {"Graveler (Alolan Graveler)"}
	},{
	    {"Golem"},
	    {"Golem (Alolan Golem)"}
	},{
	    {"Ponyta"}
	},{
	    {"Rapidash"}
	},{
	    {"Slowpoke"}
	},{
	    {"Slowbro"},
	    {"Slowbro (Mega Slowbro)"}
	},{
	    {"Magnemite"}
	},{
	    {"Magneton"}
	},{
	    {"Farfetch'd"}
	},{
	    {"Doduo"}
	},{
	    {"Dodrio"}
	},{
	    {"Seel"}
	},{
	    {"Dewgong"}
	},{
	    {"Grimer"},
	    {"Grimer (Alolan Grimer)"}
	},{
	    {"Muk"},
	    {"Muk (Alolan Muk)"}
	},{
	    {"Shellder"}
	},{
	    {"Cloyster"}
	},{
	    {"Gastly"}
	},{
	    {"Haunter"}
	},{
	    {"Gengar"},
	    {"Gengar (Mega Gengar)"}
	},{
	    {"Onix"}
	},{
	    {"Drowzee"}
	},{
	    {"Hypno"}
	},{
	    {"Krabby"}
	},{
	    {"Kingler"}
	},{
	    {"Voltorb"}
	},{
	    {"Electrode"}
	},{
	    {"Exeggcute"}
	},{
	    {"Exeggutor"},
	    {"Exeggutor (Alolan Exeggutor)"}
	},{
	    {"Cubone"}
	},{
	    {"Marowak"},
	    {"Marowak (Alolan Marowak)"}
	},{
	    {"Hitmonlee"}
	},{
	    {"Hitmonchan"}
	},{
	    {"Lickitung"}
	},{
	    {"Koffing"}
	},{
	    {"Weezing"}
	},{
	    {"Rhyhorn"}
	},{
	    {"Rhydon"}
	},{
	    {"Chansey"}
	},{
	    {"Tangela"}
	},{
	    {"Kangaskhan"},
	    {"Kangaskhan (Mega Kangaskhan)"}
	},{
	    {"Horsea"}
	},{
	    {"Seadra"}
	},{
	    {"Goldeen"}
	},{
	    {"Seaking"}
	},{
	    {"Staryu"}
	},{
	    {"Starmie"}
	},{
	    {"Mr. Mime"}
	},{
	    {"Scyther"}
	},{
	    {"Jynx"}
	},{
	    {"Electabuzz"}
	},{
	    {"Magmar"}
	},{
	    {"Pinsir"},
	    {"Pinsir (Mega Pinsir)"}
	},{
	    {"Tauros"}
	},{
	    {"Magikarp"}
	},{
	    {"Gyarados"},
	    {"Gyarados (Mega Gyarados)"}
	},{
	    {"Lapras"}
	},{
	    {"Ditto"}
	},{
	    {"Eevee"}
	},{
	    {"Vaporeon"}
	},{
	    {"Jolteon"}
	},{
	    {"Flareon"}
	},{
	    {"Porygon"}
	},{
	    {"Omanyte"}
	},{
	    {"Omastar"}
	},{
	    {"Kabuto"}
	},{
	    {"Kabutops"}
	},{
	    {"Aerodactyl"},
	    {"Aerodactyl (Mega Aerodactyl)"}
	},{
	    {"Snorlax"}
	},{
	    {"Articuno"}
	},{
	    {"Zapdos"}
	},{
	    {"Moltres"}
	},{
	    {"Dratini"}
	},{
	    {"Dragonair"}
	},{
	    {"Dragonite"}
	},{
	    {"Mewtwo"},
	    {"Mewtwo (Mega Mewtwo X)"},
	    {"Mewtwo (Mega Mewtwo Y)"}
	},{
	    {"Mew"}
	},{
	    {"Chikorita"}
	},{
	    {"Bayleef"}
	},{
	    {"Meganium"}
	},{
	    {"Cyndaquil"}
	},{
	    {"Quilava"}
	},{
	    {"Typhlosion"}
	},{
	    {"Totodile"}
	},{
	    {"Croconaw"}
	},{
	    {"Feraligatr"}
	},{
	    {"Sentret"}
	},{
	    {"Furret"}
	},{
	    {"Hoothoot"}
	},{
	    {"Noctowl"}
	},{
	    {"Ledyba"}
	},{
	    {"Ledian"}
	},{
	    {"Spinarak"}
	},{
	    {"Ariados"}
	},{
	    {"Crobat"}
	},{
	    {"Chinchou"}
	},{
	    {"Lanturn"}
	},{
	    {"Pichu"}
	},{
	    {"Cleffa"}
	},{
	    {"Igglybuff"}
	},{
	    {"Togepi"}
	},{
	    {"Togetic"}
	},{
	    {"Natu"}
	},{
	    {"Xatu"}
	},{
	    {"Mareep"}
	},{
	    {"Flaaffy"}
	},{
	    {"Ampharos"},
	    {"Ampharos (Mega Ampharos)"}
	},{
	    {"Bellossom"}
	},{
	    {"Marill"}
	},{
	    {"Azumarill"}
	},{
	    {"Sudowoodo"}
	},{
	    {"Politoed"}
	},{
	    {"Hoppip"}
	},{
	    {"Skiploom"}
	},{
	    {"Jumpluff"}
	},{
	    {"Aipom"}
	},{
	    {"Sunkern"}
	},{
	    {"Sunflora"}
	},{
	    {"Yanma"}
	},{
	    {"Wooper"}
	},{
	    {"Quagsire"}
	},{
	    {"Espeon"}
	},{
	    {"Umbreon"}
	},{
	    {"Murkrow"}
	},{
	    {"Slowking"}
	},{
	    {"Misdreavus"}
	},{
	    {"Unown"}
	},{
	    {"Wobbuffet"}
	},{
	    {"Girafarig"}
	},{
	    {"Pineco"}
	},{
	    {"Forretress"}
	},{
	    {"Dunsparce"}
	},{
	    {"Gligar"}
	},{
	    {"Steelix"},
	    {"Steelix (Mega Steelix)"}
	},{
	    {"Snubbull"}
	},{
	    {"Granbull"}
	},{
	    {"Qwilfish"}
	},{
	    {"Scizor"},
	    {"Scizor (Mega Scizor)"}
	},{
	    {"Shuckle"}
	},{
	    {"Heracross"},
	    {"Heracross (Mega Heracross)"}
	},{
	    {"Sneasel"}
	},{
	    {"Teddiursa"}
	},{
	    {"Ursaring"}
	},{
	    {"Slugma"}
	},{
	    {"Magcargo"}
	},{
	    {"Swinub"}
	},{
	    {"Piloswine"}
	},{
	    {"Corsola"}
	},{
	    {"Remoraid"}
	},{
	    {"Octillery"}
	},{
	    {"Delibird"}
	},{
	    {"Mantine"}
	},{
	    {"Skarmory"}
	},{
	    {"Houndour"}
	},{
	    {"Houndoom"},
	    {"Houndoom (Mega Houndoom)"}
	},{
	    {"Kingdra"}
	},{
	    {"Phanpy"}
	},{
	    {"Donphan"}
	},{
	    {"Porygon2"}
	},{
	    {"Stantler"}
	},{
	    {"Smeargle"}
	},{
	    {"Tyrogue"}
	},{
	    {"Hitmontop"}
	},{
	    {"Smoochum"}
	},{
	    {"Elekid"}
	},{
	    {"Magby"}
	},{
	    {"Miltank"}
	},{
	    {"Blissey"}
	},{
	    {"Raikou"}
	},{
	    {"Entei"}
	},{
	    {"Suicune"}
	},{
	    {"Larvitar"}
	},{
	    {"Pupitar"}
	},{
	    {"Tyranitar"},
	    {"Tyranitar (Mega Tyranitar)"}
	},{
	    {"Lugia"}
	},{
	    {"Ho-Oh"}
	},{
	    {"Celebi"}
	},{
	    {"Treecko"}
	},{
	    {"Grovyle"}
	},{
	    {"Sceptile"},
	    {"Sceptile (Mega Sceptile)"}
	},{
	    {"Torchic"}
	},{
	    {"Combusken"}
	},{
	    {"Blaziken"},
	    {"Blaziken (Mega Blaziken)"}
	},{
	    {"Mudkip"}
	},{
	    {"Marshtomp"}
	},{
	    {"Swampert"},
	    {"Swampert (Mega Swampert)"}
	},{
	    {"Poochyena"}
	},{
	    {"Mightyena"}
	},{
	    {"Zigzagoon"}
	},{
	    {"Linoone"}
	},{
	    {"Wurmple"}
	},{
	    {"Silcoon"}
	},{
	    {"Beautifly"}
	},{
	    {"Cascoon"}
	},{
	    {"Dustox"}
	},{
	    {"Lotad"}
	},{
	    {"Lombre"}
	},{
	    {"Ludicolo"}
	},{
	    {"Seedot"}
	},{
	    {"Nuzleaf"}
	},{
	    {"Shiftry"}
	},{
	    {"Taillow"}
	},{
	    {"Swellow"}
	},{
	    {"Wingull"}
	},{
	    {"Pelipper"}
	},{
	    {"Ralts"}
	},{
	    {"Kirlia"}
	},{
	    {"Gardevoir"},
	    {"Gardevoir (Mega Gardevoir)"}
	},{
	    {"Surskit"}
	},{
	    {"Masquerain"}
	},{
	    {"Shroomish"}
	},{
	    {"Breloom"}
	},{
	    {"Slakoth"}
	},{
	    {"Vigoroth"}
	},{
	    {"Slaking"}
	},{
	    {"Nincada"}
	},{
	    {"Ninjask"}
	},{
	    {"Shedinja"}
	},{
	    {"Whismur"}
	},{
	    {"Loudred"}
	},{
	    {"Exploud"}
	},{
	    {"Makuhita"}
	},{
	    {"Hariyama"}
	},{
	    {"Azurill"}
	},{
	    {"Nosepass"}
	},{
	    {"Skitty"}
	},{
	    {"Delcatty"}
	},{
	    {"Sableye"},
	    {"Sableye (Mega Sableye)"}
	},{
	    {"Mawile"},
	    {"Mawile (Mega Mawile)"}
	},{
	    {"Aron"}
	},{
	    {"Lairon"}
	},{
	    {"Aggron"},
	    {"Aggron (Mega Aggron)"}
	},{
	    {"Meditite"}
	},{
	    {"Medicham"},
	    {"Medicham (Mega Medicham)"}
	},{
	    {"Electrike"}
	},{
	    {"Manectric"},
	    {"Manectric (Mega Manectric)"}
	},{
	    {"Plusle"}
	},{
	    {"Minun"}
	},{
	    {"Volbeat"}
	},{
	    {"Illumise"}
	},{
	    {"Roselia"}
	},{
	    {"Gulpin"}
	},{
	    {"Swalot"}
	},{
	    {"Carvanha"}
	},{
	    {"Sharpedo"},
	    {"Sharpedo (Mega Sharpedo)"}
	},{
	    {"Wailmer"}
	},{
	    {"Wailord"}
	},{
	    {"Numel"}
	},{
	    {"Camerupt"},
	    {"Camerupt (Mega Camerupt)"}
	},{
	    {"Torkoal"}
	},{
	    {"Spoink"}
	},{
	    {"Grumpig"}
	},{
	    {"Spinda"}
	},{
	    {"Trapinch"}
	},{
	    {"Vibrava"}
	},{
	    {"Flygon"}
	},{
	    {"Cacnea"}
	},{
	    {"Cacturne"}
	},{
	    {"Swablu"}
	},{
	    {"Altaria"},
	    {"Altaria (Mega Altaria)"}
	},{
	    {"Zangoose"}
	},{
	    {"Seviper"}
	},{
	    {"Lunatone"}
	},{
	    {"Solrock"}
	},{
	    {"Barboach"}
	},{
	    {"Whiscash"}
	},{
	    {"Corphish"}
	},{
	    {"Crawdaunt"}
	},{
	    {"Baltoy"}
	},{
	    {"Claydol"}
	},{
	    {"Lileep"}
	},{
	    {"Cradily"}
	},{
	    {"Anorith"}
	},{
	    {"Armaldo"}
	},{
	    {"Feebas"}
	},{
	    {"Milotic"}
	},{
	    {"Castform"}
	},{
	    {"Kecleon"}
	},{
	    {"Shuppet"}
	},{
	    {"Banette"},
	    {"Banette (Mega Banette)"}
	},{
	    {"Duskull"}
	},{
	    {"Dusclops"}
	},{
	    {"Tropius"}
	},{
	    {"Chimecho"}
	},{
	    {"Absol"},
	    {"Absol (Mega Absol)"}
	},{
	    {"Wynaut"}
	},{
	    {"Snorunt"}
	},{
	    {"Glalie"},
	    {"Glalie (Mega Glalie)"}
	},{
	    {"Spheal"}
	},{
	    {"Sealeo"}
	},{
	    {"Walrein"}
	},{
	    {"Clamperl"}
	},{
	    {"Huntail"}
	},{
	    {"Gorebyss"}
	},{
	    {"Relicanth"}
	},{
	    {"Luvdisc"}
	},{
	    {"Bagon"}
	},{
	    {"Shelgon"}
	},{
	    {"Salamence"},
	    {"Salamence (Mega Salamence)"}
	},{
	    {"Beldum"}
	},{
	    {"Metang"}
	},{
	    {"Metagross"},
	    {"Metagross (Mega Metagross)"}
	},{
	    {"Regirock"}
	},{
	    {"Regice"}
	},{
	    {"Registeel"}
	},{
	    {"Latias"},
	    {"Latias (Mega Latias)"}
	},{
	    {"Latios"},
	    {"Latios (Mega Latios)"}
	},{
	    {"Kyogre"},
	    {"Kyogre (Primal Kyogre)"}
	},{
	    {"Groudon"},
	    {"Groudon (Primal Groudon)"}
	},{
	    {"Rayquaza"},
	    {"Rayquaza (Mega Rayquaza)"}
	},{
	    {"Jirachi"}
	},{
	    {"Deoxys (Normal Forme)"},
	    {"Deoxys (Attack Forme)"},
	    {"Deoxys (Defense Forme)"},
	    {"Deoxys (Speed Forme)"}
	},{
	    {"Turtwig"}
	},{
	    {"Grotle"}
	},{
	    {"Torterra"}
	},{
	    {"Chimchar"}
	},{
	    {"Monferno"}
	},{
	    {"Infernape"}
	},{
	    {"Piplup"}
	},{
	    {"Prinplup"}
	},{
	    {"Empoleon"}
	},{
	    {"Starly"}
	},{
	    {"Staravia"}
	},{
	    {"Staraptor"}
	},{
	    {"Bidoof"}
	},{
	    {"Bibarel"}
	},{
	    {"Kricketot"}
	},{
	    {"Kricketune"}
	},{
	    {"Shinx"}
	},{
	    {"Luxio"}
	},{
	    {"Luxray"}
	},{
	    {"Budew"}
	},{
	    {"Roserade"}
	},{
	    {"Cranidos"}
	},{
	    {"Rampardos"}
	},{
	    {"Shieldon"}
	},{
	    {"Bastiodon"}
	},{
	    {"Burmy"}
	},{
	    {"Wormadam (Plant Cloak)"},
	    {"Wormadam (Sandy Cloak)"},
	    {"Wormadam (Trash Cloak)"}
	},{
	    {"Mothim"}
	},{
	    {"Combee"}
	},{
	    {"Vespiquen"}
	},{
	    {"Pachirisu"}
	},{
	    {"Buizel"}
	},{
	    {"Floatzel"}
	},{
	    {"Cherubi"}
	},{
	    {"Cherrim"}
	},{
	    {"Shellos"}
	},{
	    {"Gastrodon"}
	},{
	    {"Ambipom"}
	},{
	    {"Drifloon"}
	},{
	    {"Drifblim"}
	},{
	    {"Buneary"}
	},{
	    {"Lopunny"},
	    {"Lopunny (Mega Lopunny)"}
	},{
	    {"Mismagius"}
	},{
	    {"Honchkrow"}
	},{
	    {"Glameow"}
	},{
	    {"Purugly"}
	},{
	    {"Chingling"}
	},{
	    {"Stunky"}
	},{
	    {"Skuntank"}
	},{
	    {"Bronzor"}
	},{
	    {"Bronzong"}
	},{
	    {"Bonsly"}
	},{
	    {"Mime Jr."}
	},{
	    {"Happiny"}
	},{
	    {"Chatot"}
	},{
	    {"Spiritomb"}
	},{
	    {"Gible"}
	},{
	    {"Gabite"}
	},{
	    {"Garchomp"},
	    {"Garchomp (Mega Garchomp)"}
	},{
	    {"Munchlax"}
	},{
	    {"Riolu"}
	},{
	    {"Lucario"},
	    {"Lucario (Mega Lucario)"}
	},{
	    {"Hippopotas"}
	},{
	    {"Hippowdon"}
	},{
	    {"Skorupi"}
	},{
	    {"Drapion"}
	},{
	    {"Croagunk"}
	},{
	    {"Toxicroak"}
	},{
	    {"Carnivine"}
	},{
	    {"Finneon"}
	},{
	    {"Lumineon"}
	},{
	    {"Mantyke"}
	},{
	    {"Snover"}
	},{
	    {"Abomasnow"},
	    {"Abomasnow (Mega Abomasnow)"}
	},{
	    {"Weavile"}
	},{
	    {"Magnezone"}
	},{
	    {"Lickilicky"}
	},{
	    {"Rhyperior"}
	},{
	    {"Tangrowth"}
	},{
	    {"Electivire"}
	},{
	    {"Magmortar"}
	},{
	    {"Togekiss"}
	},{
	    {"Yanmega"}
	},{
	    {"Leafeon"}
	},{
	    {"Glaceon"}
	},{
	    {"Gliscor"}
	},{
	    {"Mamoswine"}
	},{
	    {"Porygon-Z"}
	},{
	    {"Gallade"},
	    {"Gallade (Mega Gallade)"}
	},{
	    {"Probopass"}
	},{
	    {"Dusknoir"}
	},{
	    {"Froslass"}
	},{
	    {"Rotom"},
	    {"Rotom (Heat Rotom)"},
	    {"Rotom (Wash Rotom)"},
	    {"Rotom (Frost Rotom)"},
	    {"Rotom (Fan Rotom)"},
	    {"Rotom (Mow Rotom)"}
	},{
	    {"Uxie"}
	},{
	    {"Mesprit"}
	},{
	    {"Azelf"}
	},{
	    {"Dialga"}
	},{
	    {"Palkia"}
	},{
	    {"Heatran"}
	},{
	    {"Regigigas"}
	},{
	    {"Giratina (Altered Forme)"},
	    {"Giratina (Origin Forme)"}
	},{
	    {"Cresselia"}
	},{
	    {"Phione"}
	},{
	    {"Manaphy"}
	},{
	    {"Darkrai"}
	},{
	    {"Shaymin (Land Forme)"},
	    {"Shaymin (Sky Forme)"}
	},{
	    {"Arceus"}
	},{
	    {"Victini"}
	},{
	    {"Snivy"}
	},{
	    {"Servine"}
	},{
	    {"Serperior"}
	},{
	    {"Tepig"}
	},{
	    {"Pignite"}
	},{
	    {"Emboar"}
	},{
	    {"Oshawott"}
	},{
	    {"Dewott"}
	},{
	    {"Samurott"}
	},{
	    {"Patrat"}
	},{
	    {"Watchog"}
	},{
	    {"Lillipup"}
	},{
	    {"Herdier"}
	},{
	    {"Stoutland"}
	},{
	    {"Purrloin"}
	},{
	    {"Liepard"}
	},{
	    {"Pansage"}
	},{
	    {"Simisage"}
	},{
	    {"Pansear"}
	},{
	    {"Simisear"}
	},{
	    {"Panpour"}
	},{
	    {"Simipour"}
	},{
	    {"Munna"}
	},{
	    {"Musharna"}
	},{
	    {"Pidove"}
	},{
	    {"Tranquill"}
	},{
	    {"Unfezant"}
	},{
	    {"Blitzle"}
	},{
	    {"Zebstrika"}
	},{
	    {"Roggenrola"}
	},{
	    {"Boldore"}
	},{
	    {"Gigalith"}
	},{
	    {"Woobat"}
	},{
	    {"Swoobat"}
	},{
	    {"Drilbur"}
	},{
	    {"Excadrill"}
	},{
	    {"Audino"},
	    {"Audino (Mega Audino)"}
	},{
	    {"Timburr"}
	},{
	    {"Gurdurr"}
	},{
	    {"Conkeldurr"}
	},{
	    {"Tympole"}
	},{
	    {"Palpitoad"}
	},{
	    {"Seismitoad"}
	},{
	    {"Throh"}
	},{
	    {"Sawk"}
	},{
	    {"Sewaddle"}
	},{
	    {"Swadloon"}
	},{
	    {"Leavanny"}
	},{
	    {"Venipede"}
	},{
	    {"Whirlipede"}
	},{
	    {"Scolipede"}
	},{
	    {"Cottonee"}
	},{
	    {"Whimsicott"}
	},{
	    {"Petilil"}
	},{
	    {"Lilligant"}
	},{
	    {"Basculin"}
	},{
	    {"Sandile"}
	},{
	    {"Krokorok"}
	},{
	    {"Krookodile"}
	},{
	    {"Darumaka"}
	},{
	    {"Darmanitan (Standard Mode)"},
	    {"Darmanitan (Zen Mode)"}
	},{
	    {"Maractus"}
	},{
	    {"Dwebble"}
	},{
	    {"Crustle"}
	},{
	    {"Scraggy"}
	},{
	    {"Scrafty"}
	},{
	    {"Sigilyph"}
	},{
	    {"Yamask"}
	},{
	    {"Cofagrigus"}
	},{
	    {"Tirtouga"}
	},{
	    {"Carracosta"}
	},{
	    {"Archen"}
	},{
	    {"Archeops"}
	},{
	    {"Trubbish"}
	},{
	    {"Garbodor"}
	},{
	    {"Zorua"}
	},{
	    {"Zoroark"}
	},{
	    {"Minccino"}
	},{
	    {"Cinccino"}
	},{
	    {"Gothita"}
	},{
	    {"Gothorita"}
	},{
	    {"Gothitelle"}
	},{
	    {"Solosis"}
	},{
	    {"Duosion"}
	},{
	    {"Reuniclus"}
	},{
	    {"Ducklett"}
	},{
	    {"Swanna"}
	},{
	    {"Vanillite"}
	},{
	    {"Vanillish"}
	},{
	    {"Vanilluxe"}
	},{
	    {"Deerling"}
	},{
	    {"Sawsbuck"}
	},{
	    {"Emolga"}
	},{
	    {"Karrablast"}
	},{
	    {"Escavalier"}
	},{
	    {"Foongus"}
	},{
	    {"Amoonguss"}
	},{
	    {"Frillish"}
	},{
	    {"Jellicent"}
	},{
	    {"Alomomola"}
	},{
	    {"Joltik"}
	},{
	    {"Galvantula"}
	},{
	    {"Ferroseed"}
	},{
	    {"Ferrothorn"}
	},{
	    {"Klink"}
	},{
	    {"Klang"}
	},{
	    {"Klinklang"}
	},{
	    {"Tynamo"}
	},{
	    {"Eelektrik"}
	},{
	    {"Eelektross"}
	},{
	    {"Elgyem"}
	},{
	    {"Beheeyem"}
	},{
	    {"Litwick"}
	},{
	    {"Lampent"}
	},{
	    {"Chandelure"}
	},{
	    {"Axew"}
	},{
	    {"Fraxure"}
	},{
	    {"Haxorus"}
	},{
	    {"Cubchoo"}
	},{
	    {"Beartic"}
	},{
	    {"Cryogonal"}
	},{
	    {"Shelmet"}
	},{
	    {"Accelgor"}
	},{
	    {"Stunfisk"}
	},{
	    {"Mienfoo"}
	},{
	    {"Mienshao"}
	},{
	    {"Druddigon"}
	},{
	    {"Golett"}
	},{
	    {"Golurk"}
	},{
	    {"Pawniard"}
	},{
	    {"Bisharp"}
	},{
	    {"Bouffalant"}
	},{
	    {"Rufflet"}
	},{
	    {"Braviary"}
	},{
	    {"Vullaby"}
	},{
	    {"Mandibuzz"}
	},{
	    {"Heatmor"}
	},{
	    {"Durant"}
	},{
	    {"Deino"}
	},{
	    {"Zweilous"}
	},{
	    {"Hydreigon"}
	},{
	    {"Larvesta"}
	},{
	    {"Volcarona"}
	},{
	    {"Cobalion"}
	},{
	    {"Terrakion"}
	},{
	    {"Virizion"}
	},{
	    {"Tornadus (Incarnate Forme)"},
	    {"Tornadus (Therian Forme)"}
	},{
	    {"Thundurus (Incarnate Forme)"},
	    {"Thundurus (Therian Forme)"}
	},{
	    {"Reshiram"}
	},{
	    {"Zekrom"}
	},{
	    {"Landorus (Incarnate Forme)"},
	    {"Landorus (Therian Forme)"}
	},{
	    {"Kyurem (Normal Kyurem)"},
	    {"Kyurem (Black Kyurem)"},
	    {"Kyurem (White Kyurem)"}
	},{
	    {"Keldeo"}
	},{
	    {"Meloetta (Aria Forme)"},
	    {"Meloetta (Pirouette Forme)"}
	},{
	    {"Genesect"}
	},{
	    {"Chespin"}
	},{
	    {"Quilladin"}
	},{
	    {"Chesnaught"}
	},{
	    {"Fennekin"}
	},{
	    {"Braixen"}
	},{
	    {"Delphox"}
	},{
	    {"Froakie"}
	},{
	    {"Frogadier"}
	},{
	    {"Greninja"},
	    {"Greninja (Ash-Greninja)"}
	},{
	    {"Bunnelby"}
	},{
	    {"Diggersby"}
	},{
	    {"Fletchling"}
	},{
	    {"Fletchinder"}
	},{
	    {"Talonflame"}
	},{
	    {"Scatterbug"}
	},{
	    {"Spewpa"}
	},{
	    {"Vivillon"}
	},{
	    {"Litleo"}
	},{
	    {"Pyroar"}
	},{
	    {"Flabébé"}
	},{
	    {"Floette"}
	},{
	    {"Florges"}
	},{
	    {"Skiddo"}
	},{
	    {"Gogoat"}
	},{
	    {"Pancham"}
	},{
	    {"Pangoro"}
	},{
	    {"Furfrou"}
	},{
	    {"Espurr"}
	},{
	    {"Meowstic"}
	},{
	    {"Honedge"}
	},{
	    {"Doublade"}
	},{
	    {"Aegislash (Shield Forme)"},
	    {"Aegislash (Blade Forme)"}
	},{
	    {"Spritzee"}
	},{
	    {"Aromatisse"}
	},{
	    {"Swirlix"}
	},{
	    {"Slurpuff"}
	},{
	    {"Inkay"}
	},{
	    {"Malamar"}
	},{
	    {"Binacle"}
	},{
	    {"Barbaracle"}
	},{
	    {"Skrelp"}
	},{
	    {"Dragalge"}
	},{
	    {"Clauncher"}
	},{
	    {"Clawitzer"}
	},{
	    {"Helioptile"}
	},{
	    {"Heliolisk"}
	},{
	    {"Tyrunt"}
	},{
	    {"Tyrantrum"}
	},{
	    {"Amaura"}
	},{
	    {"Aurorus"}
	},{
	    {"Sylveon"}
	},{
	    {"Hawlucha"}
	},{
	    {"Dedenne"}
	},{
	    {"Carbink"}
	},{
	    {"Goomy"}
	},{
	    {"Sliggoo"}
	},{
	    {"Goodra"}
	},{
	    {"Klefki"}
	},{
	    {"Phantump"}
	},{
	    {"Trevenant"}
	},{
	    {"Pumpkaboo (Small Size)"},
	    {"Pumpkaboo (Average Size)"},
	    {"Pumpkaboo (Large Size)"},
	    {"Pumpkaboo (Super Size)"}
	},{
	    {"Gourgeist (Small Size)"},
	    {"Gourgeist (Average Size)"},
	    {"Gourgeist (Large Size)"},
	    {"Gourgeist (Super Size)"}
	},{
	    {"Bergmite"}
	},{
	    {"Avalugg"}
	},{
	    {"Noibat"}
	},{
	    {"Noivern"}
	},{
	    {"Xerneas"}
	},{
	    {"Yveltal"}
	},{
	    {"Zygarde (50% Forme)"},
	    {"Zygarde (10% Forme)"},
	    {"Zygarde (Complete Forme)"}
	},{
	    {"Diancie"},
	    {"Diancie (Mega Diancie)"}
	},{
	    {"Hoopa (Hoopa Confined)"},
	    {"Hoopa (Hoopa Unbound)"}
	},{
	    {"Volcanion"}
	},{
	    {"Rowlet"}
	},{
	    {"Dartrix"}
	},{
	    {"Decidueye"}
	},{
	    {"Litten"}
	},{
	    {"Torracat"}
	},{
	    {"Incineroar"}
	},{
	    {"Popplio"}
	},{
	    {"Brionne"}
	},{
	    {"Primarina"}
	},{
	    {"Pikipek"}
	},{
	    {"Trumbeak"}
	},{
	    {"Toucannon"}
	},{
	    {"Yungoos"}
	},{
	    {"Gumshoos"}
	},{
	    {"Grubbin"}
	},{
	    {"Charjabug"}
	},{
	    {"Vikavolt"}
	},{
	    {"Crabrawler"}
	},{
	    {"Crabominable"}
	},{
	    {"Oricorio (Pom-Pom)"},
	    {"Oricorio (Baile)"},
	    {"Oricorio (P'au)"},
	    {"Oricorio (Sensu)"}
	},{
	    {"Cutiefly"}
	},{
	    {"Ribombee"}
	},{
	    {"Rockruff"}
	},{
	    {"Lycanroc (Midday Form)"},
	    {"Lycanroc (Midnight Form)"}
	},{
	    {"Wishiwashi (Solo Form)"},
	    {"Wishiwashi (School Form)"}
	},{
	    {"Mareanie"}
	},{
	    {"Toxapex"}
	},{
	    {"Mudbray"}
	},{
	    {"Mudsdale"}
	},{
	    {"Dewpider"}
	},{
	    {"Araquanid"}
	},{
	    {"Fomantis"}
	},{
	    {"Lurantis"}
	},{
	    {"Morelull"}
	},{
	    {"Shiinotic"}
	},{
	    {"Salandit"}
	},{
	    {"Salazzle"}
	},{
	    {"Stufful"}
	},{
	    {"Bewear"}
	},{
	    {"Bounsweet"}
	},{
	    {"Steenee"}
	},{
	    {"Tsareena"}
	},{
	    {"Comfey"}
	},{
	    {"Oranguru"}
	},{
	    {"Passimian"}
	},{
	    {"Wimpod"}
	},{
	    {"Golisopod"}
	},{
	    {"Sandygast"}
	},{
	    {"Palossand"}
	},{
	    {"Pyukumuku"}
	},{
	    {"Type: Null"}
	},{
	    {"Silvally"}
	},{
	    {"Minior (Meteor Form)"},
	    {"Minior (Core)"}
	},{
	    {"Komala"}
	},{
	    {"Turtonator"}
	},{
	    {"Togedemaru"}
	},{
	    {"Mimikyu"}
	},{
	    {"Bruxish"}
	},{
	    {"Drampa"}
	},{
	    {"Dhelmise"}
	},{
	    {"Jangmo-o"}
	},{
	    {"Hakamo-o"}
	},{
	    {"Kommo-o"}
	},{
	    {"Tapu Koko"}
	},{
	    {"Tapu Lele"}
	},{
	    {"Tapu Bulu"}
	},{
	    {"Tapu Fini"}
	},{
	    {"Cosmog"}
	},{
	    {"Cosmoem"}
	},{
	    {"Solgaleo"}
	},{
	    {"Lunala"}
	},{
	    {"Nihilego"}
	},{
	    {"Buzzwole"}
	},{
	    {"Pheromosa"}
	},{
	    {"Xurkitree"}
	},{
	    {"Celesteela"}
	},{
	    {"Kartana"}
	},{
	    {"Guzzlord"}
	},{
	    {"Necrozma"}
	},{
	    {"Magearna"}
	},{
	    {"Marshadow"}
	}

};

// POKEMON FORMS AMMOUNT, POKEMON NUMBER, BASE STATS PER POKEMON PER FORM X6, COLOR, TYPE1, TYPE2
static const short POKEMON_LOOKUP[][6][11] = {
    {
        { 1 , 1 , 45 , 49 , 49 , 65 , 65 , 45 , 5 , 12 , 4 } // Bulbasaur Grass Poison
    },
    {
        { 1 , 2 , 60 , 62 , 63 , 80 , 80 , 60 , 5 , 12 , 4 } // Ivysaur Grass Poison
    },
    {
        { 2 , 3 , 80 , 82 , 83 , 100 , 100 , 80 , 5 , 12 , 4 }, // Venusaur Grass Poison
        { 2 , 3 , 80 , 100 , 123 , 122 , 120 , 80 , 5 , 12 , 4 } // Venusaur Grass Poison
    },
    {
        { 1 , 4 , 39 , 52 , 43 , 60 , 50 , 65 , 8 , 10 , 0 } // Charmander Fire
    },
    {
        { 1 , 5 , 58 , 64 , 58 , 80 , 65 , 80 , 8 , 10 , 0 } // Charmeleon Fire
    },
    {
        { 3 , 6 , 78 , 84 , 78 , 109 , 85 , 100 , 8 , 10 , 3 }, // Charizard Fire Flying
        { 3 , 6 , 78 , 130 , 111 , 130 , 85 , 100 , 1 , 10 , 16 }, // Charizard Fire Dragon
        { 3 , 6 , 78 , 104 , 78 , 159 , 115 , 100 , 8 , 10 , 3 } // Charizard Fire Flying
    },
    {
        { 1 , 7 , 44 , 48 , 65 , 50 , 64 , 43 , 2 , 11 , 0 } // Squirtle Water
    },
    {
        { 1 , 8 , 59 , 63 , 80 , 65 , 80 , 58 , 2 , 11 , 0 } // Wartortle Water
    },
    {
        { 2 , 9 , 79 , 83 , 100 , 85 , 105 , 78 , 2 , 11 , 0 }, // Blastoise Water
        { 2 , 9 , 79 , 103 , 120 , 135 , 115 , 78 , 2 , 11 , 0 } // Blastoise Water
    },
    {
        { 1 , 10 , 45 , 30 , 35 , 20 , 20 , 45 , 5 , 7 , 0 } // Caterpie Bug
    },
    {
        { 1 , 11 , 50 , 20 , 55 , 25 , 25 , 30 , 5 , 7 , 0 } // Metapod Bug
    },
    {
        { 1 , 12 , 60 , 45 , 50 , 90 , 80 , 70 , 9 , 7 , 3 } // Butterfree Bug Flying
    },
    {
        { 1 , 13 , 40 , 35 , 30 , 20 , 20 , 50 , 3 , 7 , 4 } // Weedle Bug Poison
    },
    {
        { 1 , 14 , 45 , 25 , 50 , 25 , 25 , 35 , 10 , 7 , 4 } // Kakuna Bug Poison
    },
    {
        { 2 , 15 , 65 , 90 , 40 , 45 , 80 , 75 , 10 , 7 , 4 }, // Beedrill Bug Poison
        { 2 , 15 , 65 , 150 , 40 , 15 , 80 , 145 , 10 , 7 , 4 } // Beedrill Bug Poison
    },
    {
        { 1 , 16 , 40 , 45 , 40 , 35 , 35 , 56 , 3 , 1 , 3 } // Pidgey Normal Flying
    },
    {
        { 1 , 17 , 63 , 60 , 55 , 50 , 50 , 71 , 3 , 1 , 3 } // Pidgeotto Normal Flying
    },
    {
        { 2 , 18 , 83 , 80 , 75 , 70 , 70 , 101 , 3 , 1 , 3 }, // Pidgeot Normal Flying
        { 2 , 18 , 83 , 80 , 80 , 135 , 80 , 121 , 3 , 1 , 3 } // Pidgeot Normal Flying
    },
    {
        { 2 , 19 , 30 , 56 , 35 , 25 , 35 , 72 , 7 , 1 , 0 }, // Rattata Normal
        { 2 , 19 , 30 , 56 , 35 , 25 , 35 , 72 , 1 , 17 , 1 } // Rattata Dark Normal
    },
    {
        { 2 , 20 , 55 , 81 , 60 , 50 , 70 , 97 , 3 , 1 , 0 }, // Raticate Normal
        { 2 , 20 , 75 , 71 , 70 , 40 , 80 , 77 , 1 , 17 , 1 } // Raticate Dark Normal
    },
    {
        { 1 , 21 , 40 , 60 , 30 , 31 , 31 , 70 , 3 , 1 , 3 } // Spearow Normal Flying
    },
    {
        { 1 , 22 , 65 , 90 , 65 , 61 , 61 , 100 , 3 , 1 , 3 } // Fearow Normal Flying
    },
    {
        { 1 , 23 , 35 , 60 , 44 , 40 , 54 , 55 , 7 , 4 , 0 } // Ekans Poison
    },
    {
        { 1 , 24 , 60 , 95 , 69 , 65 , 79 , 80 , 7 , 4 , 0 } // Arbok Poison
    },
    {
        { 1 , 25 , 35 , 55 , 40 , 50 , 50 , 90 , 10 , 13 , 0 } // Pikachu Electric
    },
    {
        { 2 , 26 , 60 , 90 , 55 , 90 , 80 , 110 , 10 , 13 , 0 }, // Raichu Electric
        { 2 , 26 , 60 , 85 , 50 , 95 , 85 , 110 , 3 , 13 , 14 } // Raichu Electric Psychic
    },
    {
        { 2 , 27 , 50 , 75 , 85 , 20 , 30 , 40 , 10 , 5 , 0 }, // Sandshrew Ground
        { 2 , 27 , 50 , 75 , 90 , 10 , 35 , 40 , 9 , 15 , 9 } // Sandshrew Ice Steel
    },
    {
        { 2 , 28 , 75 , 100 , 110 , 45 , 55 , 65 , 10 , 5 , 0 }, // Sandslash Ground
        { 2 , 28 , 75 , 100 , 120 , 25 , 65 , 65 , 9 , 15 , 9 } // Sandslash Ice Steel
    },
    {
        { 1 , 29 , 55 , 47 , 52 , 40 , 40 , 41 , 2 , 4 , 0 } // Nidoran♀ Poison
    },
    {
        { 1 , 30 , 70 , 62 , 67 , 55 , 55 , 56 , 2 , 4 , 0 } // Nidorina Poison
    },
    {
        { 1 , 31 , 90 , 92 , 87 , 75 , 85 , 76 , 2 , 4 , 5 } // Nidoqueen Poison Ground
    },
    {
        { 1 , 32 , 46 , 57 , 40 , 40 , 40 , 50 , 7 , 4 , 0 } // Nidoran♂ Poison
    },
    {
        { 1 , 33 , 61 , 72 , 57 , 55 , 55 , 65 , 7 , 4 , 0 } // Nidorino Poison
    },
    {
        { 1 , 34 , 81 , 102 , 77 , 85 , 75 , 85 , 7 , 4 , 5 } // Nidoking Poison Ground
    },
    {
        { 1 , 35 , 70 , 45 , 48 , 60 , 65 , 35 , 6 , 18 , 0 } // Clefairy Fairy
    },
    {
        { 1 , 36 , 95 , 70 , 73 , 95 , 90 , 60 , 6 , 18 , 0 } // Clefable Fairy
    },
    {
        { 2 , 37 , 38 , 41 , 40 , 50 , 65 , 65 , 3 , 10 , 0 }, // Vulpix Fire
        { 2 , 37 , 38 , 41 , 40 , 50 , 65 , 65 , 9 , 15 , 0 } // Vulpix Ice
    },
    {
        { 2 , 38 , 73 , 76 , 75 , 81 , 100 , 100 , 10 , 10 , 0 }, // Ninetales Fire
        { 2 , 38 , 73 , 67 , 75 , 81 , 100 , 109 , 2 , 15 , 18 } // Ninetales Ice Fairy
    },
    {
        { 1 , 39 , 115 , 45 , 20 , 45 , 25 , 20 , 6 , 1 , 18 } // Jigglypuff Normal Fairy
    },
    {
        { 1 , 40 , 140 , 70 , 45 , 85 , 50 , 45 , 6 , 1 , 18 } // Wigglytuff Normal Fairy
    },
    {
        { 1 , 41 , 40 , 45 , 35 , 30 , 40 , 55 , 7 , 4 , 3 } // Zubat Poison Flying
    },
    {
        { 1 , 42 , 75 , 80 , 70 , 65 , 75 , 90 , 7 , 4 , 3 } // Golbat Poison Flying
    },
    {
        { 1 , 43 , 45 , 50 , 55 , 75 , 65 , 30 , 2 , 12 , 4 } // Oddish Grass Poison
    },
    {
        { 1 , 44 , 60 , 65 , 70 , 85 , 75 , 40 , 2 , 12 , 4 } // Gloom Grass Poison
    },
    {
        { 1 , 45 , 75 , 80 , 85 , 110 , 90 , 50 , 8 , 12 , 4 } // Vileplume Grass Poison
    },
    {
        { 1 , 46 , 35 , 70 , 55 , 45 , 55 , 25 , 8 , 7 , 12 } // Paras Bug Grass
    },
    {
        { 1 , 47 , 60 , 95 , 80 , 60 , 80 , 30 , 8 , 7 , 12 } // Parasect Bug Grass
    },
    {
        { 1 , 48 , 60 , 55 , 50 , 40 , 55 , 45 , 7 , 7 , 4 } // Venonat Bug Poison
    },
    {
        { 1 , 49 , 70 , 65 , 60 , 90 , 75 , 90 , 7 , 7 , 4 } // Venomoth Bug Poison
    },
    {
        { 2 , 50 , 10 , 55 , 25 , 35 , 45 , 95 , 3 , 5 , 0 }, // Diglett Ground
        { 2 , 50 , 10 , 55 , 30 , 35 , 45 , 90 , 3 , 5 , 9 } // Diglett Ground Steel
    },
    {
        { 2 , 51 , 35 , 100 , 50 , 50 , 70 , 120 , 3 , 5 , 0 }, // Dugtrio Ground
        { 2 , 51 , 35 , 100 , 60 , 50 , 70 , 110 , 3 , 5 , 9 } // Dugtrio Ground Steel
    },
    {
        { 2 , 52 , 40 , 45 , 35 , 40 , 40 , 90 , 10 , 1 , 0 }, // Meowth Normal
        { 2 , 52 , 40 , 35 , 35 , 50 , 40 , 90 , 2 , 17 , 0 } // Meowth Dark
    },
    {
        { 2 , 53 , 65 , 70 , 60 , 65 , 65 , 115 , 10 , 1 , 0 }, // Persian Normal
        { 2 , 53 , 65 , 60 , 60 , 75 , 65 , 115 , 2 , 17 , 0 } // Persian Dark
    },
    {
        { 1 , 54 , 50 , 52 , 48 , 65 , 50 , 55 , 10 , 11 , 0 } // Psyduck Water
    },
    {
        { 1 , 55 , 80 , 82 , 78 , 95 , 80 , 85 , 2 , 11 , 0 } // Golduck Water
    },
    {
        { 1 , 56 , 40 , 80 , 35 , 35 , 45 , 70 , 3 , 2 , 0 } // Mankey Fighting
    },
    {
        { 1 , 57 , 65 , 105 , 60 , 60 , 70 , 95 , 3 , 2 , 0 } // Primeape Fighting
    },
    {
        { 1 , 58 , 55 , 70 , 45 , 70 , 50 , 60 , 3 , 10 , 0 } // Growlithe Fire
    },
    {
        { 1 , 59 , 90 , 110 , 80 , 100 , 80 , 95 , 3 , 10 , 0 } // Arcanine Fire
    },
    {
        { 1 , 60 , 40 , 50 , 40 , 40 , 40 , 90 , 2 , 11 , 0 } // Poliwag Water
    },
    {
        { 1 , 61 , 65 , 65 , 65 , 50 , 50 , 90 , 2 , 11 , 0 } // Poliwhirl Water
    },
    {
        { 1 , 62 , 90 , 95 , 95 , 70 , 90 , 70 , 2 , 11 , 2 } // Poliwrath Water Fighting
    },
    {
        { 1 , 63 , 25 , 20 , 15 , 105 , 55 , 90 , 3 , 14 , 0 } // Abra Psychic
    },
    {
        { 1 , 64 , 40 , 35 , 30 , 120 , 70 , 105 , 3 , 14 , 0 } // Kadabra Psychic
    },
    {
        { 2 , 65 , 55 , 50 , 45 , 135 , 95 , 120 , 3 , 14 , 0 }, // Alakazam Psychic
        { 2 , 65 , 55 , 50 , 65 , 175 , 105 , 150 , 3 , 14 , 0 }  // Alakazam Psychic
    },
    {
        { 1 , 66 , 70 , 80 , 50 , 35 , 35 , 35 , 4 , 2 , 0 }  // Machop Fighting
    },
    {
        { 1 , 67 , 80 , 100 , 70 , 50 , 60 , 45 , 4 , 2 , 0 }  // Machoke Fighting
    },
    {
        { 1 , 68 , 90 , 130 , 80 , 65 , 85 , 55 , 4 , 2 , 0 } // Machamp Fighting
    },
    {
        { 1 , 69 , 50 , 75 , 35 , 70 , 30 , 40 , 5 , 12 , 4 } // Bellsprout Grass Poison
    },
    {
        { 1 , 70 , 65 , 90 , 50 , 85 , 45 , 55 , 5 , 12 , 4 }  // Weepinbell Grass Poison
    },
    {
        { 1 , 71 , 80 , 105 , 65 , 100 , 70 , 70 , 5 , 12 , 4 }  // Victreebel Grass Poison
    },
    {
        { 1 , 72 , 40 , 40 , 35 , 50 , 100 , 70 , 2 , 11 , 4 }  // Tentacool Water Poison
    },
    {
        { 1 , 73 , 80 , 70 , 65 , 80 , 120 , 100 , 2 , 11 , 4 }  // Tentacruel Water Poison
    },
    {
        { 2 , 74 , 40 , 80 , 100 , 30 , 30 , 20 , 3 , 6 , 5 },  // Geodude Rock Ground
        { 2 , 74 , 40 , 80 , 100 , 30 , 30 , 20 , 4 , 6 , 13 }  // Geodude Rock Electric
    },
    {
        { 2 , 75 , 55 , 95 , 115 , 45 , 45 , 35 , 3 , 6 , 5 }, // Graveler Rock Ground
        { 2 , 75 , 55 , 95 , 115 , 45 , 45 , 35 , 4 , 6 , 13 }  // Graveler Rock Electric
    },
    {
        { 2 , 76 , 80 , 120 , 130 , 55 , 65 , 45 , 3 , 6 , 5 },  // Golem Rock Ground
        { 2 , 76 , 80 , 120 , 130 , 55 , 65 , 45 , 4 , 6 , 13 }  // Golem Rock Electric
    },
    {
        { 1 , 77 , 50 , 85 , 55 , 65 , 65 , 90 , 10 , 10 , 0 }  // Ponyta Fire
    },
    {
        { 1 , 78 , 65 , 100 , 70 , 80 , 80 , 105 , 10 , 10 , 0 } // Rapidash Fire
    },
    {
        { 1 , 79 , 90 , 65 , 65 , 40 , 40 , 15 , 6 , 11 , 14 } // Slowpoke Water Psychic
    },
    {
        { 2 , 80 , 95 , 75 , 110 , 100 , 80 , 30 , 6 , 11 , 14 }, // Slowbro Water Psychic
        { 2 , 80 , 95 , 75 , 180 , 130 , 80 , 30 , 6 , 11 , 14 } // Mega Slowbro Water Psychic
    },
    {
        { 1 , 81 , 25 , 35 , 70 , 95 , 55 , 45 , 4 , 13 , 9 } // Magnemite Electric Steel
    },
    {
        { 1 , 82 , 50 , 60 , 95 , 120 , 70 , 70 , 4 , 13 , 9 } // Magneton Electric Steel
    },
    {
        { 1 , 83 , 52 , 90 , 55 , 58 , 62 , 60 , 3 , 1 , 3 } // Farfetch'd Normal Flying
    },
    {
        { 1 , 84 , 35 , 85 , 45 , 35 , 35 , 75 , 3 , 1 , 3 } // Doduo Normal Flying
    },
    {
        { 1 , 85 , 60 , 110 , 70 , 60 , 60 , 110 , 3 , 1 , 3 } // Dodrio Normal Flying
    },
    {
        { 1 , 86 , 65 , 45 , 55 , 45 , 70 , 45 , 9 , 11 , 0 } // Seel Water
    },
    {
        { 1 , 87 , 90 , 70 , 80 , 70 , 95 , 70 , 9 , 11 , 15 } // Dewgong Water Ice
    },
    {
        { 2 , 88 , 80 , 80 , 50 , 40 , 50 , 25 , 7 , 4 , 0 }, // Grimer Poison
        { 2 , 88 , 80 , 80 , 50 , 40 , 50 , 25 , 5 , 4 , 17 } // Grimer Poison Dark
    },
    {
        { 2 , 89 , 105 , 105 , 75 , 65 , 100 , 50 , 7 , 4 , 0 }, // Muk Poison
        { 2 , 89 , 105 , 105 , 75 , 65 , 100 , 50 , 5 , 4 , 17 } // Muk Poison Dark
    },
    {
        { 1 , 90 , 30 , 65 , 100 , 45 , 25 , 40 , 7 , 11 , 0 } // Shellder Water
    },
    {
        { 1 , 91 , 50 , 95 , 180 , 85 , 45 , 70 , 7 , 11 , 15 } // Cloyster Water Ice
    },
    {
        { 1 , 92 , 30 , 35 , 30 , 100 , 35 , 80 , 7 , 8 , 4 } // Gastly Ghost Poison
    },
    {
        { 1 , 93 , 45 , 50 , 45 , 115 , 55 , 95 , 7 , 8 , 4 } // Haunter Ghost Poison
    },
    {
        { 2 , 94 , 60 , 65 , 60 , 130 , 75 , 110 , 7 , 8 , 4 }, // Gengar Ghost Poison
        { 2 , 94 , 60 , 65 , 80 , 170 , 95 , 130 , 7 , 8 , 4 } // Gengar Ghost Poison
    },
    {
        { 1 , 95 , 35 , 45 , 160 , 30 , 45 , 70 , 4 , 6 , 5 } // Onix Rock Ground
    },
    {
        { 1 , 96 , 60 , 48 , 45 , 43 , 90 , 42 , 10 , 14 , 0 } // Drowzee Psychic
    },
    {
        { 1 , 97 , 85 , 73 , 70 , 73 , 115 , 67 , 10 , 14 , 0 } // Hypno Psychic
    },
    {
        { 1 , 98 , 30 , 105 , 90 , 25 , 25 , 50 , 8 , 11 , 0 } // Krabby Water
    },
    {
        { 1 , 99 , 55 , 130 , 115 , 50 , 50 , 75 , 8 , 11 , 0 } // Kingler Water
    },
    {
        { 1 , 100 , 40 , 30 , 50 , 55 , 55 , 100 , 8 , 13 , 0 } // Voltorb Electric
    },
    {
        { 1 , 101 , 60 , 50 , 70 , 80 , 80 , 150 , 8 , 13 , 0 } // Electrode Electric
    },
    {
        { 1 , 102 , 60 , 40 , 80 , 60 , 45 , 40 , 6 , 12 , 14 } // Exeggcute Grass Psychic
    },
    {
        { 2 , 103 , 95 , 95 , 85 , 125 , 75 , 55 , 10 , 12 , 14 }, // Exeggutor Grass Psychic
        { 2 , 103 , 95 , 105 , 85 , 125 , 75 , 45 , 10 , 12 , 16 } // Exeggutor Grass Dragon
    },
    {
        { 1 , 104 , 50 , 50 , 95 , 40 , 50 , 35 , 3 , 5 , 0 } // Cubone Ground
    },
    {
        { 2 , 105 , 60 , 80 , 110 , 50 , 80 , 45 , 3 , 5 , 0 }, // Marowak Ground
        { 2 , 105 , 60 , 80 , 110 , 50 , 80 , 45 , 7 , 10 , 8 } // Marowak Fire Ghost
    },
    {
        { 1 , 106 , 50 , 120 , 53 , 35 , 110 , 87 , 3 , 2 , 0 } // Hitmonlee Fighting
    },
    {
        { 1 , 107 , 50 , 105 , 79 , 35 , 110 , 76 , 3 , 2 , 0 } // Hitmonchan Fighting
    },
    {
        { 1 , 108 , 90 , 55 , 75 , 60 , 75 , 30 , 6 , 1 , 0 } // Lickitung Normal
    },
    {
        { 1 , 109 , 40 , 65 , 95 , 60 , 45 , 35 , 7 , 4 , 0 } // Koffing Poison
    },
    {
        { 1 , 110 , 65 , 90 , 120 , 85 , 70 , 60 , 7 , 4 , 0 } // Weezing Poison
    },
    {
        { 1 , 111 , 80 , 85 , 95 , 30 , 30 , 25 , 4 , 5 , 6 } // Rhyhorn Ground Rock
    },
    {
        { 1 , 112 , 105 , 130 , 120 , 45 , 45 , 40 , 4 , 5 , 6 } // Rhydon Ground Rock
    },
    {
        { 1 , 113 , 250 , 5 , 5 , 35 , 105 , 50 , 6 , 1 , 0 } // Chansey Normal
    },
    {
        { 1 , 114 , 65 , 55 , 115 , 100 , 40 , 60 , 2 , 12 , 0 } // Tangela Grass
    },
    {
        { 2 , 115 , 105 , 95 , 80 , 40 , 80 , 90 , 3 , 1 , 0 }, // Kangaskhan Normal
        { 2 , 115 , 105 , 125 , 100 , 60 , 100 , 100 , 3 , 1 , 0 } // Kangaskhan Normal
    },
    {
        { 1 , 116 , 30 , 40 , 70 , 70 , 25 , 60 , 2 , 11 , 0 } // Horsea Water
    },
    {
        { 1 , 117 , 55 , 65 , 95 , 95 , 45 , 85 , 2 , 11 , 0 } // Seadra Water
    },
    {
        { 1 , 118 , 45 , 67 , 60 , 35 , 50 , 63 , 8 , 11 , 0 } // Goldeen Water
    },
    {
        { 1 , 119 , 80 , 92 , 65 , 65 , 80 , 68 , 8 , 11 , 0 } // Seaking Water
    },
    {
        { 1 , 120 , 30 , 45 , 55 , 70 , 55 , 85 , 3 , 11 , 0 } // Staryu Water
    },
    {
        { 1 , 121 , 60 , 75 , 85 , 100 , 85 , 115 , 7 , 11 , 14 } // Starmie Water Psychic
    },
    {
        { 1 , 122 , 40 , 45 , 65 , 100 , 120 , 90 , 6 , 14 , 18 } // Mr. Mime Psychic Fairy
    },
    {
        { 1 , 123 , 70 , 110 , 80 , 55 , 80 , 105 , 5 , 7 , 3 } // Scyther Bug Flying
    },
    {
        { 1 , 124 , 65 , 50 , 35 , 115 , 95 , 95 , 8 , 15 , 14 } // Jynx Ice Psychic
    },
    {
        { 1 , 125 , 65 , 83 , 57 , 95 , 85 , 105 , 10 , 13 , 0 } // Electabuzz Electric
    },
    {
        { 1 , 126 , 65 , 95 , 57 , 100 , 85 , 93 , 8 , 10 , 0 } // Magmar Fire
    },
    {
        { 2 , 127 , 65 , 125 , 100 , 55 , 70 , 85 , 3 , 7 , 0 }, // Pinsir Bug
        { 2 , 127 , 65 , 155 , 120 , 65 , 90 , 105 , 3 , 7 , 0 } // Pinsir Bug
    },
    {
        { 1 , 128 , 75 , 100 , 95 , 40 , 70 , 110 , 3 , 1 , 0 } // Tauros Normal
    },
    {
        { 1 , 129 , 20 , 10 , 55 , 15 , 20 , 80 , 8 , 11 , 0 } // Magikarp Water
    },
    {
        { 2 , 130 , 95 , 125 , 79 , 60 , 100 , 81 , 2 , 11 , 3 }, // Gyarados Water Flying
        { 2 , 130 , 95 , 155 , 109 , 70 , 130 , 81 , 2 , 11 , 3 } // Gyarados Water Flying
    },
    {
        { 1 , 131 , 130 , 85 , 80 , 85 , 95 , 60 , 2 , 11 , 15 } // Lapras Water Ice
    },
    {
        { 1 , 132 , 48 , 48 , 48 , 48 , 48 , 48 , 7 , 1 , 0 } // Ditto Normal
    },
    {
        { 1 , 133 , 55 , 55 , 50 , 45 , 65 , 55 , 3 , 1 , 0 } // Eevee Normal
    },
    {
        { 1 , 134 , 130 , 65 , 60 , 110 , 95 , 65 , 2 , 11 , 0 } // Vaporeon Water
    },
    {
        { 1 , 135 , 65 , 65 , 60 , 110 , 95 , 130 , 10 , 13 , 0 } // Jolteon Electric
    },
    {
        { 1 , 136 , 65 , 130 , 60 , 95 , 110 , 65 , 8 , 10 , 0 } // Flareon Fire
    },
    {
        { 1 , 137 , 65 , 60 , 70 , 85 , 75 , 40 , 6 , 1 , 0 } // Porygon Normal
    },
    {
        { 1 , 138 , 35 , 40 , 100 , 90 , 55 , 35 , 2 , 6 , 11 } // Omanyte Rock Water
    },
    {
        { 1 , 139 , 70 , 60 , 125 , 115 , 70 , 55 , 2 , 6 , 11 } // Omastar Rock Water
    },
    {
        { 1 , 140 , 30 , 80 , 90 , 55 , 45 , 55 , 3 , 6 , 11 } // Kabuto Rock Water
    },
    {
        { 1 , 141 , 60 , 115 , 105 , 65 , 70 , 80 , 3 , 6 , 11 } // Kabutops Rock Water
    },
    {
        { 2 , 142 , 80 , 105 , 65 , 60 , 75 , 130 , 7 , 6 , 3 }, // Aerodactyl Rock Flying
        { 2 , 142 , 80 , 135 , 85 , 70 , 95 , 150 , 7 , 6 , 3 } // Aerodactyl Rock Flying
    },
    {
        { 1 , 143 , 160 , 110 , 65 , 65 , 110 , 30 , 1 , 1 , 0 } // Snorlax Normal
    },
    {
        { 1 , 144 , 90 , 85 , 100 , 95 , 125 , 85 , 2 , 15 , 3 } // Articuno Ice Flying
    },
    {
        { 1 , 145 , 90 , 90 , 85 , 125 , 90 , 100 , 10 , 13 , 3 } // Zapdos Electric Flying
    },
    {
        { 1 , 146 , 90 , 100 , 90 , 125 , 85 , 90 , 10 , 10 , 3 } // Moltres Fire Flying
    },
    {
        { 1 , 147 , 41 , 64 , 45 , 50 , 50 , 50 , 2 , 16 , 0 } // Dratini Dragon
    },
    {
        { 1 , 148 , 61 , 84 , 65 , 70 , 70 , 70 , 2 , 16 , 0 } // Dragonair Dragon
    },
    {
        { 1 , 149 , 91 , 134 , 95 , 100 , 100 , 80 , 3 , 16 , 3 } // Dragonite Dragon Flying
    },
    {
        { 3 , 150 , 106 , 110 , 90 , 154 , 90 , 130 , 7 , 14 , 0 }, // Mewtwo Psychic
        { 3 , 150 , 106 , 190 , 100 , 154 , 100 , 130 , 7 , 14 , 0 }, // Mewtwo Psychic
        { 3 , 150 , 106 , 150 , 70 , 194 , 120 , 140 , 7 , 14 , 0 } // Mewtwo Psychic
    },
    {
        { 1 , 151 , 100 , 100 , 100 , 100 , 100 , 100 , 6 , 14 , 0 } // Mew Psychic
    },
    {
        { 1 , 152 , 45 , 49 , 65 , 49 , 65 , 45 , 5 , 12 , 0 } // Chikorita Grass
    },
    {
        { 1 , 153 , 60 , 62 , 80 , 63 , 80 , 60 , 5 , 12 , 0 } // Bayleef Grass
    },
    {
        { 1 , 154 , 80 , 82 , 100 , 83 , 100 , 80 , 5 , 12 , 0 } // Meganium Grass
    },
    {
        { 1 , 155 , 39 , 52 , 43 , 60 , 50 , 65 , 10 , 10 , 0 } // Cyndaquil Fire
    },
    {
        { 1 , 156 , 58 , 64 , 58 , 80 , 65 , 80 , 10 , 10 , 0 } // Quilava Fire
    },
    {
        { 1 , 157 , 78 , 84 , 78 , 109 , 85 , 100 , 10 , 10 , 0 } // Typhlosion Fire
    },
    {
        { 1 , 158 , 50 , 65 , 64 , 44 , 48 , 43 , 2 , 11 , 0 } // Totodile Water
    },
    {
        { 1 , 159 , 65 , 80 , 80 , 59 , 63 , 58 , 2 , 11 , 0 } // Croconaw Water
    },
    {
        { 1 , 160 , 85 , 105 , 100 , 79 , 83 , 78 , 2 , 11 , 0 } // Feraligatr Water
    },
    {
        { 1 , 161 , 35 , 46 , 34 , 35 , 45 , 20 , 3 , 1 , 0 } // Sentret Normal
    },
    {
        { 1 , 162 , 85 , 76 , 64 , 45 , 55 , 90 , 3 , 1 , 0 } // Furret Normal
    },
    {
        { 1 , 163 , 60 , 30 , 30 , 36 , 56 , 50 , 3 , 1 , 3 } // Hoothoot Normal Flying
    },
    {
        { 1 , 164 , 100 , 50 , 50 , 86 , 96 , 70 , 3 , 1 , 3 } // Noctowl Normal Flying
    },
    {
        { 1 , 165 , 40 , 20 , 30 , 40 , 80 , 55 , 8 , 7 , 3 } // Ledyba Bug Flying
    },
    {
        { 1 , 166 , 55 , 35 , 50 , 55 , 110 , 85 , 8 , 7 , 3 } // Ledian Bug Flying
    },
    {
        { 1 , 167 , 40 , 60 , 40 , 40 , 40 , 30 , 5 , 7 , 4 } // Spinarak Bug Poison
    },
    {
        { 1 , 168 , 70 , 90 , 70 , 60 , 70 , 40 , 8 , 7 , 4 } // Ariados Bug Poison
    },
    {
        { 1 , 169 , 85 , 90 , 80 , 70 , 80 , 130 , 7 , 4 , 3 } // Crobat Poison Flying
    },
    {
        { 1 , 170 , 75 , 38 , 38 , 56 , 56 , 67 , 2 , 11 , 13 } // Chinchou Water Electric
    },
    {
        { 1 , 171 , 125 , 58 , 58 , 76 , 76 , 67 , 2 , 11 , 13 } // Lanturn Water Electric
    },
    {
        { 1 , 172 , 20 , 40 , 15 , 35 , 35 , 60 , 10 , 13 , 0 } // Pichu Electric
    },
    {
        { 1 , 173 , 50 , 25 , 28 , 45 , 55 , 15 , 6 , 18 , 0 } // Cleffa Fairy
    },
    {
        { 1 , 174 , 90 , 30 , 15 , 40 , 20 , 15 , 6 , 1 , 18 } // Igglybuff Normal Fairy
    },
    {
        { 1 , 175 , 35 , 20 , 65 , 40 , 65 , 20 , 9 , 18 , 0 } // Togepi Fairy
    },
    {
        { 1 , 176 , 55 , 40 , 85 , 80 , 105 , 40 , 9 , 18 , 3 } // Togetic Fairy Flying
    },
    {
        { 1 , 177 , 40 , 50 , 45 , 70 , 45 , 70 , 5 , 14 , 3 } // Natu Psychic Flying
    },
    {
        { 1 , 178 , 65 , 75 , 70 , 95 , 70 , 95 , 5 , 14 , 3 } // Xatu Psychic Flying
    },
    {
        { 1 , 179 , 55 , 40 , 40 , 65 , 45 , 35 , 9 , 13 , 0 } // Mareep Electric
    },
    {
        { 1 , 180 , 70 , 55 , 55 , 80 , 60 , 45 , 6 , 13 , 0 } // Flaaffy Electric
    },
    {
        { 2 , 181 , 90 , 75 , 85 , 115 , 90 , 55 , 10 , 13 , 0 }, // Ampharos Electric
        { 2 , 181 , 90 , 95 , 105 , 165 , 110 , 45 , 10 , 13 , 0 } // Ampharos Electric
    },
    {
        { 1 , 182 , 75 , 80 , 95 , 90 , 100 , 50 , 5 , 12 , 0 } // Bellossom Grass
    },
    {
        { 1 , 183 , 70 , 20 , 50 , 20 , 50 , 40 , 2 , 11 , 18 } // Marill Water Fairy
    },
    {
        { 1 , 184 , 100 , 50 , 80 , 60 , 80 , 50 , 2 , 11 , 18 } // Azumarill Water Fairy
    },
    {
        { 1 , 185 , 70 , 100 , 115 , 30 , 65 , 30 , 3 , 6 , 0 } // Sudowoodo Rock
    },
    {
        { 1 , 186 , 90 , 75 , 75 , 90 , 100 , 70 , 5 , 11 , 0 } // Politoed Water
    },
    {
        { 1 , 187 , 35 , 35 , 40 , 35 , 55 , 50 , 6 , 12 , 3 } // Hoppip Grass Flying
    },
    {
        { 1 , 188 , 55 , 45 , 50 , 45 , 65 , 80 , 5 , 12 , 3 } // Skiploom Grass Flying
    },
    {
        { 1 , 189 , 75 , 55 , 70 , 55 , 95 , 110 , 2 , 12 , 3 } // Jumpluff Grass Flying
    },
    {
        { 1 , 190 , 55 , 70 , 55 , 40 , 55 , 85 , 7 , 1 , 0 } // Aipom Normal
    },
    {
        { 1 , 191 , 30 , 30 , 30 , 30 , 30 , 30 , 10 , 12 , 0 } // Sunkern Grass
    },
    {
        { 1 , 192 , 75 , 75 , 55 , 105 , 85 , 30 , 10 , 12 , 0 } // Sunflora Grass
    },
    {
        { 1 , 193 , 65 , 65 , 45 , 75 , 45 , 95 , 8 , 7 , 3 } // Yanma Bug Flying
    },
    {
        { 1 , 194 , 55 , 45 , 45 , 25 , 25 , 15 , 2 , 11 , 5 } // Wooper Water Ground
    },
    {
        { 1 , 195 , 95 , 85 , 85 , 65 , 65 , 35 , 2 , 11 , 5 } // Quagsire Water Ground
    },
    {
        { 1 , 196 , 65 , 65 , 60 , 130 , 95 , 110 , 7 , 14 , 0 } // Espeon Psychic
    },
    {
        { 1 , 197 , 95 , 65 , 110 , 60 , 130 , 65 , 1 , 17 , 0 } // Umbreon Dark
    },
    {
        { 1 , 198 , 60 , 85 , 42 , 85 , 42 , 91 , 1 , 17 , 3 } // Murkrow Dark Flying
    },
    {
        { 1 , 199 , 95 , 75 , 80 , 100 , 110 , 30 , 6 , 11 , 14 } // Slowking Water Psychic
    },
    {
        { 1 , 200 , 60 , 60 , 60 , 85 , 85 , 85 , 4 , 8 , 0 } // Misdreavus Ghost
    },
    {
        { 1 , 201 , 48 , 72 , 48 , 72 , 48 , 48 , 1 , 14 , 0 } // Unown Psychic
    },
    {
        { 1 , 202 , 190 , 33 , 58 , 33 , 58 , 33 , 2 , 14 , 0 } // Wobbuffet Psychic
    },
    {
        { 1 , 203 , 70 , 80 , 65 , 90 , 65 , 85 , 10 , 1 , 14 } // Girafarig Normal Psychic
    },
    {
        { 1 , 204 , 50 , 65 , 90 , 35 , 35 , 15 , 4 , 7 , 0 } // Pineco Bug
    },
    {
        { 1 , 205 , 75 , 90 , 140 , 60 , 60 , 40 , 7 , 7 , 9 } // Forretress Bug Steel
    },
    {
        { 1 , 206 , 100 , 70 , 70 , 65 , 65 , 45 , 10 , 1 , 0 } // Dunsparce Normal
    },
    {
        { 1 , 207 , 65 , 75 , 105 , 35 , 65 , 85 , 7 , 5 , 3 } // Gligar Ground Flying
    },
    {
        { 2 , 208 , 75 , 85 , 200 , 55 , 65 , 30 , 4 , 9 , 5 }, // Steelix Steel Ground
        { 2 , 208 , 75 , 125 , 230 , 55 , 95 , 30 , 4 , 9 , 5 } // Steelix Steel Ground
    },
    {
        { 1 , 209 , 60 , 80 , 50 , 40 , 40 , 30 , 6 , 18 , 0 } // Snubbull Fairy
    },
    {
        { 1 , 210 , 90 , 120 , 75 , 60 , 60 , 45 , 7 , 18 , 0 } // Granbull Fairy
    },
    {
        { 1 , 211 , 65 , 95 , 85 , 55 , 55 , 85 , 4 , 11 , 4 } // Qwilfish Water Poison
    },
    {
        { 2 , 212 , 70 , 130 , 100 , 55 , 80 , 65 , 8 , 7 , 9 }, // Scizor Bug Steel
        { 2 , 212 , 70 , 150 , 140 , 65 , 100 , 75 , 8 , 7 , 9 } // Scizor Bug Steel
    },
    {
        { 1 , 213 , 20 , 10 , 230 , 10 , 230 , 5 , 10 , 7 , 6 } // Shuckle Bug Rock
    },
    {
        { 2 , 214 , 80 , 125 , 75 , 40 , 95 , 85 , 2 , 7 , 2 }, // Heracross Bug Fighting
        { 2 , 214 , 80 , 185 , 115 , 40 , 105 , 75 , 2 , 7 , 2 } // Heracross Bug Fighting
    },
    {
        { 1 , 215 , 55 , 95 , 55 , 35 , 75 , 115 , 1 , 17 , 15 } // Sneasel Dark Ice
    },
    {
        { 1 , 216 , 60 , 80 , 50 , 50 , 50 , 40 , 3 , 1 , 0 } // Teddiursa Normal
    },
    {
        { 1 , 217 , 90 , 130 , 75 , 75 , 75 , 55 , 3 , 1 , 0 } // Ursaring Normal
    },
    {
        { 1 , 218 , 40 , 40 , 40 , 70 , 40 , 20 , 8 , 10 , 0 } // Slugma Fire
    },
    {
        { 1 , 219 , 60 , 50 , 120 , 90 , 80 , 30 , 8 , 10 , 6 } // Magcargo Fire Rock
    },
    {
        { 1 , 220 , 50 , 50 , 40 , 30 , 30 , 50 , 3 , 15 , 5 } // Swinub Ice Ground
    },
    {
        { 1 , 221 , 100 , 100 , 80 , 60 , 60 , 50 , 3 , 15 , 5 } // Piloswine Ice Ground
    },
    {
        { 1 , 222 , 65 , 55 , 95 , 65 , 95 , 35 , 6 , 11 , 6 } // Corsola Water Rock
    },
    {
        { 1 , 223 , 35 , 65 , 35 , 65 , 35 , 65 , 4 , 11 , 0 } // Remoraid Water
    },
    {
        { 1 , 224 , 75 , 105 , 75 , 105 , 75 , 45 , 8 , 11 , 0 } // Octillery Water
    },
    {
        { 1 , 225 , 45 , 55 , 45 , 65 , 45 , 75 , 8 , 15 , 3 } // Delibird Ice Flying
    },
    {
        { 1 , 226 , 85 , 40 , 70 , 80 , 140 , 70 , 7 , 11 , 3 } // Mantine Water Flying
    },
    {
        { 1 , 227 , 65 , 80 , 140 , 40 , 70 , 70 , 4 , 9 , 3 } // Skarmory Steel Flying
    },
    {
        { 1 , 228 , 45 , 60 , 30 , 80 , 50 , 65 , 1 , 17 , 10 } // Houndour Dark Fire
    },
    {
        { 2 , 229 , 75 , 90 , 50 , 110 , 80 , 95 , 1 , 17 , 10 }, // Houndoom Dark Fire
        { 2 , 229 , 75 , 90 , 90 , 140 , 90 , 115 , 1 , 17 , 10 } // Houndoom Dark Fire
    },
    {
        { 1 , 230 , 75 , 95 , 95 , 95 , 95 , 85 , 2 , 11 , 16 } // Kingdra Water Dragon
    },
    {
        { 1 , 231 , 90 , 60 , 60 , 40 , 40 , 40 , 2 , 5 , 0 } // Phanpy Ground
    },
    {
        { 1 , 232 , 90 , 120 , 120 , 60 , 60 , 50 , 4 , 5 , 0 } // Donphan Ground
    },
    {
        { 1 , 233 , 85 , 80 , 90 , 105 , 95 , 60 , 8 , 1 , 0 } // Porygon2 Normal
    },
    {
        { 1 , 234 , 73 , 95 , 62 , 85 , 65 , 85 , 3 , 1 , 0 } // Stantler Normal
    },
    {
        { 1 , 235 , 55 , 20 , 35 , 20 , 45 , 75 , 9 , 1 , 0 } // Smeargle Normal
    },
    {
        { 1 , 236 , 35 , 35 , 35 , 35 , 35 , 35 , 7 , 2 , 0 } // Tyrogue Fighting
    },
    {
        { 1 , 237 , 50 , 95 , 95 , 35 , 110 , 70 , 3 , 2 , 0 } // Hitmontop Fighting
    },
    {
        { 1 , 238 , 45 , 30 , 15 , 85 , 65 , 65 , 6 , 15 , 14 } // Smoochum Ice Psychic
    },
    {
        { 1 , 239 , 45 , 63 , 37 , 65 , 55 , 95 , 10 , 13 , 0 } // Elekid Electric
    },
    {
        { 1 , 240 , 45 , 75 , 37 , 70 , 55 , 83 , 8 , 10 , 0 } // Magby Fire
    },
    {
        { 1 , 241 , 95 , 80 , 105 , 40 , 70 , 100 , 6 , 1 , 0 } // Miltank Normal
    },
    {
        { 1 , 242 , 255 , 10 , 10 , 75 , 135 , 55 , 6 , 1 , 0 } // Blissey Normal
    },
    {
        { 1 , 243 , 90 , 85 , 75 , 115 , 100 , 115 , 10 , 13 , 0 } // Raikou Electric
    },
    {
        { 1 , 244 , 115 , 115 , 85 , 90 , 75 , 100 , 3 , 10 , 0 } // Entei Fire
    },
    {
        { 1 , 245 , 100 , 75 , 115 , 90 , 115 , 85 , 2 , 11 , 0 } // Suicune Water
    },
    {
        { 1 , 246 , 50 , 64 , 50 , 45 , 50 , 41 , 5 , 6 , 5 } // Larvitar Rock Ground
    },
    {
        { 1 , 247 , 70 , 84 , 70 , 65 , 70 , 51 , 4 , 6 , 5 } // Pupitar Rock Ground
    },
    {
        { 2 , 248 , 100 , 134 , 110 , 95 , 100 , 61 , 5 , 6 , 17 }, // Tyranitar Rock Dark
        { 2 , 248 , 100 , 164 , 150 , 95 , 120 , 71 , 5 , 6 , 17 } // Tyranitar Rock Dark
    },
    {
        { 1 , 249 , 106 , 90 , 130 , 90 , 154 , 110 , 9 , 14 , 3 } // Lugia Psychic Flying
    },
    {
        { 1 , 250 , 106 , 130 , 90 , 110 , 154 , 90 , 8 , 10 , 3 } // Ho-Oh Fire Flying
    },
    {
        { 1 , 251 , 100 , 100 , 100 , 100 , 100 , 100 , 5 , 14 , 12 } // Celebi Psychic Grass
    },
    {
        { 1 , 252 , 40 , 45 , 35 , 65 , 55 , 70 , 5 , 12 , 0 } // Treecko Grass
    },
    {
        { 1 , 253 , 50 , 65 , 45 , 85 , 65 , 95 , 5 , 12 , 0 } // Grovyle Grass
    },
    {
        { 2 , 254 , 70 , 85 , 65 , 105 , 85 , 120 , 5 , 12 , 0 }, // Sceptile Grass
        { 2 , 254 , 70 , 110 , 75 , 145 , 85 , 145 , 5 , 12 , 0 } // Sceptile Grass
    },
    {
        { 1 , 255 , 45 , 60 , 40 , 70 , 50 , 45 , 8 , 10 , 0 } // Torchic Fire
    },
    {
        { 1 , 256 , 60 , 85 , 60 , 85 , 60 , 55 , 8 , 10 , 2 } // Combusken Fire Fighting
    },
    {
        { 2 , 257 , 80 , 120 , 70 , 110 , 70 , 80 , 8 , 10 , 2 }, // Blaziken Fire Fighting
        { 2 , 257 , 80 , 160 , 80 , 130 , 80 , 100 , 8 , 10 , 2 } // Blaziken Fire Fighting
    },
    {
        { 1 , 258 , 50 , 70 , 50 , 50 , 50 , 40 , 2 , 11 , 0 } // Mudkip Water
    },
    {
        { 1 , 259 , 70 , 85 , 70 , 60 , 70 , 50 , 2 , 11 , 5 } // Marshtomp Water Ground
    },
    {
        { 2 , 260 , 100 , 110 , 90 , 85 , 90 , 60 , 2 , 11 , 5 }, // Swampert Water Ground
        { 2 , 260 , 100 , 150 , 110 , 95 , 110 , 70 , 2 , 11 , 5 } // Swampert Water Ground
    },
    {
        { 1 , 261 , 35 , 55 , 35 , 30 , 30 , 35 , 4 , 17 , 0 } // Poochyena Dark
    },
    {
        { 1 , 262 , 70 , 90 , 70 , 60 , 60 , 70 , 4 , 17 , 0 } // Mightyena Dark
    },
    {
        { 1 , 263 , 38 , 30 , 41 , 30 , 41 , 60 , 3 , 1 , 0 } // Zigzagoon Normal
    },
    {
        { 1 , 264 , 78 , 70 , 61 , 50 , 61 , 100 , 9 , 1 , 0 } // Linoone Normal
    },
    {
        { 1 , 265 , 45 , 45 , 35 , 20 , 30 , 20 , 8 , 7 , 0 } // Wurmple Bug
    },
    {
        { 1 , 266 , 50 , 35 , 55 , 25 , 25 , 15 , 9 , 7 , 0 } // Silcoon Bug
    },
    {
        { 1 , 267 , 60 , 70 , 50 , 100 , 50 , 65 , 10 , 7 , 3 } // Beautifly Bug Flying
    },
    {
        { 1 , 268 , 50 , 35 , 55 , 25 , 25 , 15 , 7 , 7 , 0 } // Cascoon Bug
    },
    {
        { 1 , 269 , 60 , 50 , 70 , 50 , 90 , 65 , 5 , 7 , 4 } // Dustox Bug Poison
    },
    {
        { 1 , 270 , 40 , 30 , 30 , 40 , 50 , 30 , 5 , 11 , 12 } // Lotad Water Grass
    },
    {
        { 1 , 271 , 60 , 50 , 50 , 60 , 70 , 50 , 5 , 11 , 12 } // Lombre Water Grass
    },
    {
        { 1 , 272 , 80 , 70 , 70 , 90 , 100 , 70 , 5 , 11 , 12 } // Ludicolo Water Grass
    },
    {
        { 1 , 273 , 40 , 40 , 50 , 30 , 30 , 30 , 3 , 12 , 0 } // Seedot Grass
    },
    {
        { 1 , 274 , 70 , 70 , 40 , 60 , 40 , 60 , 3 , 12 , 17 } // Nuzleaf Grass Dark
    },
    {
        { 1 , 275 , 90 , 100 , 60 , 90 , 60 , 80 , 3 , 12 , 17 } // Shiftry Grass Dark
    },
    {
        { 1 , 276 , 40 , 55 , 30 , 30 , 30 , 85 , 2 , 1 , 3 } // Taillow Normal Flying
    },
    {
        { 1 , 277 , 60 , 85 , 60 , 75 , 50 , 125 , 2 , 1 , 3 } // Swellow Normal Flying
    },
    {
        { 1 , 278 , 40 , 30 , 30 , 55 , 30 , 85 , 9 , 11 , 3 } // Wingull Water Flying
    },
    {
        { 1 , 279 , 60 , 50 , 100 , 95 , 70 , 65 , 10 , 11 , 3 } // Pelipper Water Flying
    },
    {
        { 1 , 280 , 28 , 25 , 25 , 45 , 35 , 40 , 9 , 14 , 18 } // Ralts Psychic Fairy
    },
    {
        { 1 , 281 , 38 , 35 , 35 , 65 , 55 , 50 , 9 , 14 , 18 } // Kirlia Psychic Fairy
    },
    {
        { 2 , 282 , 68 , 65 , 65 , 125 , 115 , 80 , 9 , 14 , 18 }, // Gardevoir Psychic Fairy
        { 2 , 282 , 68 , 85 , 65 , 165 , 135 , 100 , 9 , 14 , 18 } // Gardevoir Psychic Fairy
    },
    {
        { 1 , 283 , 40 , 30 , 32 , 50 , 52 , 65 , 2 , 7 , 11 } // Surskit Bug Water
    },
    {
        { 1 , 284 , 70 , 60 , 62 , 100 , 82 , 80 , 2 , 7 , 3 } // Masquerain Bug Flying
    },
    {
        { 1 , 285 , 60 , 40 , 60 , 40 , 60 , 35 , 3 , 12 , 0 } // Shroomish Grass
    },
    {
        { 1 , 286 , 60 , 130 , 80 , 60 , 60 , 70 , 5 , 12 , 2 } // Breloom Grass Fighting
    },
    {
        { 1 , 287 , 60 , 60 , 60 , 35 , 35 , 30 , 3 , 1 , 0 } // Slakoth Normal
    },
    {
        { 1 , 288 , 80 , 80 , 80 , 55 , 55 , 90 , 9 , 1 , 0 } // Vigoroth Normal
    },
    {
        { 1 , 289 , 150 , 160 , 100 , 95 , 65 , 100 , 3 , 1 , 0 } // Slaking Normal
    },
    {
        { 1 , 290 , 31 , 45 , 90 , 30 , 30 , 40 , 4 , 7 , 5 } // Nincada Bug Ground
    },
    {
        { 1 , 291 , 61 , 90 , 45 , 50 , 50 , 160 , 10 , 7 , 3 } // Ninjask Bug Flying
    },
    {
        { 1 , 292 , 1 , 90 , 45 , 30 , 30 , 40 , 3 , 7 , 8 } // Shedinja Bug Ghost
    },
    {
        { 1 , 293 , 64 , 51 , 23 , 51 , 23 , 28 , 6 , 1 , 0 } // Whismur Normal
    },
    {
        { 1 , 294 , 84 , 71 , 43 , 71 , 43 , 48 , 2 , 1 , 0 } // Loudred Normal
    },
    {
        { 1 , 295 , 104 , 91 , 63 , 91 , 73 , 68 , 2 , 1 , 0 } // Exploud Normal
    },
    {
        { 1 , 296 , 72 , 60 , 30 , 20 , 30 , 25 , 10 , 2 , 0 } // Makuhita Fighting
    },
    {
        { 1 , 297 , 144 , 120 , 60 , 40 , 60 , 50 , 3 , 2 , 0 } // Hariyama Fighting
    },
    {
        { 1 , 298 , 50 , 20 , 40 , 20 , 40 , 20 , 2 , 1 , 18 } // Azurill Normal Fairy
    },
    {
        { 1 , 299 , 30 , 45 , 135 , 45 , 90 , 30 , 4 , 6 , 0 } // Nosepass Rock
    },
    {
        { 1 , 300 , 50 , 45 , 45 , 35 , 35 , 50 , 6 , 1 , 0 } // Skitty Normal
    },
    {
        { 1 , 301 , 70 , 65 , 65 , 55 , 55 , 90 , 7 , 1 , 0 } // Delcatty Normal
    },
    {
        { 2 , 302 , 50 , 75 , 75 , 65 , 65 , 50 , 7 , 17 , 8 }, // Sableye Dark Ghost
        { 2 , 302 , 50 , 85 , 125 , 85 , 115 , 20 , 7 , 17 , 8 } // Sableye Dark Ghost
    },
    {
        { 2 , 303 , 50 , 85 , 85 , 55 , 55 , 50 , 1 , 9 , 18 }, // Mawile Steel Fairy
        { 2 , 303 , 50 , 105 , 125 , 55 , 95 , 50 , 1 , 9 , 18 } // Mawile Steel Fairy
    },
    {
        { 1 , 304 , 50 , 70 , 100 , 40 , 40 , 30 , 4 , 9 , 6 } // Aron Steel Rock
    },
    {
        { 1 , 305 , 60 , 90 , 140 , 50 , 50 , 40 , 4 , 9 , 6 } // Lairon Steel Rock
    },
    {
        { 2 , 306 , 70 , 110 , 180 , 60 , 60 , 50 , 4 , 9 , 6 }, // Aggron Steel Rock
        { 2 , 306 , 70 , 140 , 230 , 60 , 80 , 50 , 4 , 9 , 6 } // Aggron Steel Rock
    },
    {
        { 1 , 307 , 30 , 40 , 55 , 40 , 55 , 60 , 2 , 2 , 14 } // Meditite Fighting Psychic
    },
    {
        { 2 , 308 , 60 , 60 , 75 , 60 , 75 , 80 , 8 , 2 , 14 }, // Medicham Fighting Psychic
        { 2 , 308 , 60 , 100 , 85 , 80 , 85 , 100 , 8 , 2 , 14 } // Medicham Fighting Psychic
    },
    {
        { 1 , 309 , 40 , 45 , 40 , 65 , 40 , 65 , 5 , 13 , 0 } // Electrike Electric
    },
    {
        { 2 , 310 , 70 , 75 , 60 , 105 , 60 , 105 , 10 , 13 , 0 }, // Manectric Electric
        { 2 , 310 , 70 , 75 , 80 , 135 , 80 , 135 , 10 , 13 , 0 } // Manectric Electric
    },
    {
        { 1 , 311 , 60 , 50 , 40 , 85 , 75 , 95 , 10 , 13 , 0 } // Plusle Electric
    },
    {
        { 1 , 312 , 60 , 40 , 50 , 75 , 85 , 95 , 10 , 13 , 0 } // Minun Electric
    },
    {
        { 1 , 313 , 65 , 73 , 75 , 47 , 85 , 85 , 4 , 7 , 0 } // Volbeat Bug
    },
    {
        { 1 , 314 , 65 , 47 , 75 , 73 , 85 , 85 , 7 , 7 , 0 } // Illumise Bug
    },
    {
        { 1 , 315 , 50 , 60 , 45 , 100 , 80 , 65 , 5 , 12 , 4 } // Roselia Grass Poison
    },
    {
        { 1 , 316 , 70 , 43 , 53 , 43 , 53 , 40 , 5 , 4 , 0 } // Gulpin Poison
    },
    {
        { 1 , 317 , 100 , 73 , 83 , 73 , 83 , 55 , 7 , 4 , 0 } // Swalot Poison
    },
    {
        { 1 , 318 , 45 , 90 , 20 , 65 , 20 , 65 , 8 , 11 , 17 } // Carvanha Water Dark
    },
    {
        { 2 , 319 , 70 , 120 , 40 , 95 , 40 , 95 , 2 , 11 , 17 }, // Sharpedo Water Dark
        { 2 , 319 , 70 , 140 , 70 , 110 , 65 , 105 , 2 , 11 , 17 } // Sharpedo Water Dark
    },
    {
        { 1 , 320 , 130 , 70 , 35 , 70 , 35 , 60 , 2 , 11 , 0 } // Wailmer Water
    },
    {
        { 1 , 321 , 170 , 90 , 45 , 90 , 45 , 60 , 2 , 11 , 0 } // Wailord Water
    },
    {
        { 1 , 322 , 60 , 60 , 40 , 65 , 45 , 35 , 10 , 10 , 5 } // Numel Fire Ground
    },
    {
        { 2 , 323 , 70 , 100 , 70 , 105 , 75 , 40 , 8 , 10 , 5 }, // Camerupt Fire Ground
        { 2 , 323 , 70 , 120 , 100 , 145 , 105 , 20 , 8 , 10 , 5 } // Camerupt Fire Ground
    },
    {
        { 1 , 324 , 70 , 85 , 140 , 85 , 70 , 20 , 3 , 10 , 0 } // Torkoal Fire
    },
    {
        { 1 , 325 , 60 , 25 , 35 , 70 , 80 , 60 , 1 , 14 , 0 } // Spoink Psychic
    },
    {
        { 1 , 326 , 80 , 45 , 65 , 90 , 110 , 80 , 7 , 14 , 0 } // Grumpig Psychic
    },
    {
        { 1 , 327 , 60 , 60 , 60 , 60 , 60 , 60 , 3 , 1 , 0 } // Spinda Normal
    },
    {
        { 1 , 328 , 45 , 100 , 45 , 45 , 45 , 10 , 3 , 5 , 0 } // Trapinch Ground
    },
    {
        { 1 , 329 , 50 , 70 , 50 , 50 , 50 , 70 , 5 , 5 , 16 } // Vibrava Ground Dragon
    },
    {
        { 1 , 330 , 80 , 100 , 80 , 80 , 80 , 100 , 5 , 5 , 16 } // Flygon Ground Dragon
    },
    {
        { 1 , 331 , 50 , 85 , 40 , 85 , 40 , 35 , 5 , 12 , 0 } // Cacnea Grass
    },
    {
        { 1 , 332 , 70 , 115 , 60 , 115 , 60 , 55 , 5 , 12 , 17 } // Cacturne Grass Dark
    },
    {
        { 1 , 333 , 45 , 40 , 60 , 40 , 75 , 50 , 2 , 1 , 3 } // Swablu Normal Flying
    },
    {
        { 2 , 334 , 75 , 70 , 90 , 70 , 105 , 80 , 2 , 16 , 3 }, // Altaria Dragon Flying
        { 2 , 334 , 75 , 110 , 110 , 110 , 105 , 80 , 2 , 16 , 3 } // Altaria Dragon Flying
    },
    {
        { 1 , 335 , 73 , 115 , 60 , 60 , 60 , 90 , 9 , 1 , 0 } // Zangoose Normal
    },
    {
        { 1 , 336 , 73 , 100 , 60 , 100 , 60 , 65 , 1 , 4 , 0 } // Seviper Poison
    },
    {
        { 1 , 337 , 90 , 55 , 65 , 95 , 85 , 70 , 10 , 6 , 14 } // Lunatone Rock Psychic
    },
    {
        { 1 , 338 , 90 , 95 , 85 , 55 , 65 , 70 , 8 , 6 , 14 } // Solrock Rock Psychic
    },
    {
        { 1 , 339 , 50 , 48 , 43 , 46 , 41 , 60 , 4 , 11 , 5 } // Barboach Water Ground
    },
    {
        { 1 , 340 , 110 , 78 , 73 , 76 , 71 , 60 , 2 , 11 , 5 } // Whiscash Water Ground
    },
    {
        { 1 , 341 , 43 , 80 , 65 , 50 , 35 , 35 , 8 , 11 , 0 } // Corphish Water
    },
    {
        { 1 , 342 , 63 , 120 , 85 , 90 , 55 , 55 , 8 , 11 , 17 } // Crawdaunt Water Dark
    },
    {
        { 1 , 343 , 40 , 40 , 55 , 40 , 70 , 55 , 3 , 5 , 14 } // Baltoy Ground Psychic
    },
    {
        { 1 , 344 , 60 , 70 , 105 , 70 , 120 , 75 , 1 , 5 , 14 } // Claydol Ground Psychic
    },
    {
        { 1 , 345 , 66 , 41 , 77 , 61 , 87 , 23 , 7 , 6 , 12 } // Lileep Rock Grass
    },
    {
        { 1 , 346 , 86 , 81 , 97 , 81 , 107 , 43 , 5 , 6 , 12 } // Cradily Rock Grass
    },
    {
        { 1 , 347 , 45 , 95 , 50 , 40 , 50 , 75 , 4 , 6 , 7 } // Anorith Rock Bug
    },
    {
        { 1 , 348 , 75 , 125 , 100 , 70 , 80 , 45 , 4 , 6 , 7 } // Armaldo Rock Bug
    },
    {
        { 1 , 349 , 20 , 15 , 20 , 10 , 55 , 80 , 3 , 11 , 0 } // Feebas Water
    },
    {
        { 1 , 350 , 95 , 60 , 79 , 100 , 125 , 81 , 6 , 11 , 0 } // Milotic Water
    },
    {
        { 1 , 351 , 70 , 70 , 70 , 70 , 70 , 70 , 4 , 1 , 0 } // Castform Normal
    },
    {
        { 1 , 352 , 60 , 90 , 70 , 60 , 120 , 40 , 5 , 1 , 0 } // Kecleon Normal
    },
    {
        { 1 , 353 , 44 , 75 , 35 , 63 , 33 , 45 , 1 , 8 , 0 } // Shuppet Ghost
    },
    {
        { 2 , 354 , 64 , 115 , 65 , 83 , 63 , 65 , 1 , 8 , 0 }, // Banette Ghost
        { 2 , 354 , 64 , 165 , 75 , 93 , 83 , 75 , 1 , 8 , 0 } // Banette Ghost
    },
    {
        { 1 , 355 , 20 , 40 , 90 , 30 , 90 , 25 , 1 , 8 , 0 } // Duskull Ghost
    },
    {
        { 1 , 356 , 40 , 70 , 130 , 60 , 130 , 25 , 1 , 8 , 0 } // Dusclops Ghost
    },
    {
        { 1 , 357 , 99 , 68 , 83 , 72 , 87 , 51 , 5 , 12 , 3 } // Tropius Grass Flying
    },
    {
        { 1 , 358 , 75 , 50 , 80 , 95 , 90 , 65 , 2 , 14 , 0 } // Chimecho Psychic
    },
    {
        { 2 , 359 , 65 , 130 , 60 , 75 , 60 , 75 , 9 , 17 , 0 }, // Absol Dark
        { 2 , 359 , 65 , 150 , 60 , 115 , 60 , 115 , 9 , 17 , 0 } // Absol Dark
    },
    {
        { 1 , 360 , 95 , 23 , 48 , 23 , 48 , 23 , 2 , 14 , 0 } // Wynaut Psychic
    },
    {
        { 1 , 361 , 50 , 50 , 50 , 50 , 50 , 50 , 4 , 15 , 0 } // Snorunt Ice
    },
    {
        { 2 , 362 , 80 , 80 , 80 , 80 , 80 , 80 , 4 , 15 , 0 }, // Glalie Ice
        { 2 , 362 , 80 , 120 , 80 , 120 , 80 , 100 , 4 , 15 , 0 } // Glalie Ice
    },
    {
        { 1 , 363 , 70 , 40 , 50 , 55 , 50 , 25 , 2 , 15 , 11 } // Spheal Ice Water
    },
    {
        { 1 , 364 , 90 , 60 , 70 , 75 , 70 , 45 , 2 , 15 , 11 } // Sealeo Ice Water
    },
    {
        { 1 , 365 , 110 , 80 , 90 , 95 , 90 , 65 , 2 , 15 , 11 } // Walrein Ice Water
    },
    {
        { 1 , 366 , 35 , 64 , 85 , 74 , 55 , 32 , 2 , 11 , 0 } // Clamperl Water
    },
    {
        { 1 , 367 , 55 , 104 , 105 , 94 , 75 , 52 , 2 , 11 , 0 } // Huntail Water
    },
    {
        { 1 , 368 , 55 , 84 , 105 , 114 , 75 , 52 , 6 , 11 , 0 } // Gorebyss Water
    },
    {
        { 1 , 369 , 100 , 90 , 130 , 45 , 65 , 55 , 4 , 11 , 6 } // Relicanth Water Rock
    },
    {
        { 1 , 370 , 43 , 30 , 55 , 40 , 65 , 97 , 6 , 11 , 0 } // Luvdisc Water
    },
    {
        { 1 , 371 , 45 , 75 , 60 , 40 , 30 , 50 , 2 , 16 , 0 } // Bagon Dragon
    },
    {
        { 1 , 372 , 65 , 95 , 100 , 60 , 50 , 50 , 9 , 16 , 0 } // Shelgon Dragon
    },
    {
        { 2 , 373 , 95 , 135 , 80 , 110 , 80 , 100 , 2 , 16 , 3 }, // Salamence Dragon Flying
        { 2 , 373 , 95 , 145 , 130 , 120 , 90 , 120 , 2 , 16 , 3 } // Salamence Dragon Flying
    },
    {
        { 1 , 374 , 40 , 55 , 80 , 35 , 60 , 30 , 2 , 9 , 14 } // Beldum Steel Psychic
    },
    {
        { 1 , 375 , 60 , 75 , 100 , 55 , 80 , 50 , 2 , 9 , 14 } // Metang Steel Psychic
    },
    {
        { 2 , 376 , 80 , 135 , 130 , 95 , 90 , 70 , 2 , 9 , 14 }, // Metagross Steel Psychic
        { 2 , 376 , 80 , 145 , 150 , 105 , 110 , 110 , 2 , 9 , 14 } // Metagross Steel Psychic
    },
    {
        { 1 , 377 , 80 , 100 , 200 , 50 , 100 , 50 , 3 , 6 , 0 } // Regirock Rock
    },
    {
        { 1 , 378 , 80 , 50 , 100 , 100 , 200 , 50 , 2 , 15 , 0 } // Regice Ice
    },
    {
        { 1 , 379 , 80 , 75 , 150 , 75 , 150 , 50 , 4 , 9 , 0 } // Registeel Steel
    },
    {
        { 2 , 380 , 80 , 80 , 90 , 110 , 130 , 110 , 8 , 16 , 14 }, // Latias Dragon Psychic
        { 2 , 380 , 80 , 100 , 120 , 140 , 150 , 110 , 7 , 16 , 14 } // Latias Dragon Psychic
    },
    {
        { 2 , 381 , 80 , 90 , 80 , 130 , 110 , 110 , 2 , 16 , 14 }, // Latios Dragon Psychic
        { 2 , 381 , 80 , 130 , 100 , 160 , 120 , 110 , 7 , 16 , 14 } // Latios Dragon Psychic
    },
    {
        { 2 , 382 , 100 , 100 , 90 , 150 , 140 , 90 , 2 , 11 , 0 }, // Kyogre Water
        { 2 , 382 , 100 , 150 , 90 , 180 , 160 , 90 , 2 , 11 , 0 } // Kyogre Water
    },
    {
        { 2 , 383 , 100 , 150 , 140 , 100 , 90 , 90 , 8 , 5 , 0 }, // Groudon Ground
        { 2 , 383 , 100 , 180 , 160 , 150 , 90 , 90 , 8 , 5 , 0 } // Groudon Ground
    },
    {
        { 2 , 384 , 105 , 150 , 90 , 150 , 90 , 95 , 5 , 16 , 3 }, // Rayquaza Dragon Flying
        { 2 , 384 , 105 , 180 , 100 , 180 , 100 , 115 , 5 , 16 , 3 } // Rayquaza Dragon Flying
    },
    {
        { 1 , 385 , 100 , 100 , 100 , 100 , 100 , 100 , 10 , 9 , 14 } // Jirachi Steel Psychic
    },
    {
        { 4 , 386 , 50 , 150 , 50 , 150 , 50 , 150 , 8 , 14 , 0 }, // Deoxys Psychic
        { 4 , 386 , 50 , 180 , 20 , 180 , 20 , 150 , 8 , 14 , 0 }, // Deoxys Psychic
        { 4 , 386 , 50 , 70 , 160 , 70 , 160 , 90 , 8 , 14 , 0 }, // Deoxys Psychic
        { 4 , 386 , 50 , 95 , 90 , 95 , 90 , 180 , 8 , 14 , 0 } // Deoxys Psychic
    },
    {
        { 1 , 387 , 55 , 68 , 64 , 45 , 55 , 31 , 5 , 12 , 0 } // Turtwig Grass
    },
    {
        { 1 , 388 , 75 , 89 , 85 , 55 , 65 , 36 , 5 , 12 , 0 } // Grotle Grass
    },
    {
        { 1 , 389 , 95 , 109 , 105 , 75 , 85 , 56 , 5 , 12 , 5 } // Torterra Grass Ground
    },
    {
        { 1 , 390 , 44 , 58 , 44 , 58 , 44 , 61 , 3 , 10 , 0 } // Chimchar Fire
    },
    {
        { 1 , 391 , 64 , 78 , 52 , 78 , 52 , 81 , 3 , 10 , 2 } // Monferno Fire Fighting
    },
    {
        { 1 , 392 , 76 , 104 , 71 , 104 , 71 , 108 , 3 , 10 , 2 } // Infernape Fire Fighting
    },
    {
        { 1 , 393 , 53 , 51 , 53 , 61 , 56 , 40 , 2 , 11 , 0 } // Piplup Water
    },
    {
        { 1 , 394 , 64 , 66 , 68 , 81 , 76 , 50 , 2 , 11 , 0 } // Prinplup Water
    },
    {
        { 1 , 395 , 84 , 86 , 88 , 111 , 101 , 60 , 2 , 11 , 9 } // Empoleon Water Steel
    },
    {
        { 1 , 396 , 40 , 55 , 30 , 30 , 30 , 60 , 3 , 1 , 3 } // Starly Normal Flying
    },
    {
        { 1 , 397 , 55 , 75 , 50 , 40 , 40 , 80 , 3 , 1 , 3 } // Staravia Normal Flying
    },
    {
        { 1 , 398 , 85 , 120 , 70 , 50 , 60 , 100 , 3 , 1 , 3 } // Staraptor Normal Flying
    },
    {
        { 1 , 399 , 59 , 45 , 40 , 35 , 40 , 31 , 3 , 1 , 0 } // Bidoof Normal
    },
    {
        { 1 , 400 , 79 , 85 , 60 , 55 , 60 , 71 , 3 , 1 , 11 } // Bibarel Normal Water
    },
    {
        { 1 , 401 , 37 , 25 , 41 , 25 , 41 , 25 , 8 , 7 , 0 } // Kricketot Bug
    },
    {
        { 1 , 402 , 77 , 85 , 51 , 55 , 51 , 65 , 8 , 7 , 0 } // Kricketune Bug
    },
    {
        { 1 , 403 , 45 , 65 , 34 , 40 , 34 , 45 , 2 , 13 , 0 } // Shinx Electric
    },
    {
        { 1 , 404 , 60 , 85 , 49 , 60 , 49 , 60 , 2 , 13 , 0 } // Luxio Electric
    },
    {
        { 1 , 405 , 80 , 120 , 79 , 95 , 79 , 70 , 2 , 13 , 0 } // Luxray Electric
    },
    {
        { 1 , 406 , 40 , 30 , 35 , 50 , 70 , 55 , 5 , 12 , 4 } // Budew Grass Poison
    },
    {
        { 1 , 407 , 60 , 70 , 65 , 125 , 105 , 90 , 5 , 12 , 4 } // Roserade Grass Poison
    },
    {
        { 1 , 408 , 67 , 125 , 40 , 30 , 30 , 58 , 2 , 6 , 0 } // Cranidos Rock
    },
    {
        { 1 , 409 , 97 , 165 , 60 , 65 , 50 , 58 , 2 , 6 , 0 } // Rampardos Rock
    },
    {
        { 1 , 410 , 30 , 42 , 118 , 42 , 88 , 30 , 4 , 6 , 9 } // Shieldon Rock Steel
    },
    {
        { 1 , 411 , 60 , 52 , 168 , 47 , 138 , 30 , 4 , 6 , 9 } // Bastiodon Rock Steel
    },
    {
        { 1 , 412 , 40 , 29 , 45 , 29 , 45 , 36 , 5 , 7 , 0 } // Burmy Bug
    },
    {
        { 3 , 413 , 60 , 59 , 85 , 79 , 105 , 36 , 5 , 7 , 12 }, // Wormadam Bug Grass
        { 3 , 413 , 60 , 79 , 105 , 59 , 85 , 36 , 3 , 7 , 2 }, // Wormadam Bug Fighting
        { 3 , 413 , 60 , 69 , 95 , 69 , 95 , 36 , 8 , 7 , 9 } // Wormadam Bug Steel
    },
    {
        { 1 , 414 , 70 , 94 , 50 , 94 , 50 , 66 , 10 , 7 , 3 } // Mothim Bug Flying
    },
    {
        { 1 , 415 , 30 , 30 , 42 , 30 , 42 , 70 , 10 , 7 , 3 } // Combee Bug Flying
    },
    {
        { 1 , 416 , 70 , 80 , 102 , 80 , 102 , 40 , 10 , 7 , 3 } // Vespiquen Bug Flying
    },
    {
        { 1 , 417 , 60 , 45 , 70 , 45 , 90 , 95 , 9 , 13 , 0 } // Pachirisu Electric
    },
    {
        { 1 , 418 , 55 , 65 , 35 , 60 , 30 , 85 , 3 , 11 , 0 } // Buizel Water
    },
    {
        { 1 , 419 , 85 , 105 , 55 , 85 , 50 , 115 , 3 , 11 , 0 } // Floatzel Water
    },
    {
        { 1 , 420 , 45 , 35 , 45 , 62 , 53 , 35 , 6 , 12 , 0 } // Cherubi Grass
    },
    {
        { 1 , 421 , 70 , 60 , 70 , 87 , 78 , 85 , 7 , 12 , 0 } // Cherrim Grass
    },
    {
        { 1 , 422 , 76 , 48 , 48 , 57 , 62 , 34 , 7 , 11 , 0 } // Shellos Water
    },
    {
        { 1 , 423 , 111 , 83 , 68 , 92 , 82 , 39 , 7 , 11 , 5 } // Gastrodon Water Ground
    },
    {
        { 1 , 424 , 75 , 100 , 66 , 60 , 66 , 115 , 7 , 1 , 0 } // Ambipom Normal
    },
    {
        { 1 , 425 , 90 , 50 , 34 , 60 , 44 , 70 , 7 , 8 , 3 } // Drifloon Ghost Flying
    },
    {
        { 1 , 426 , 150 , 80 , 44 , 90 , 54 , 80 , 7 , 8 , 3 } // Drifblim Ghost Flying
    },
    {
        { 1 , 427 , 55 , 66 , 44 , 44 , 56 , 85 , 3 , 1 , 0 } // Buneary Normal
    },
    {
        { 2 , 428 , 65 , 76 , 84 , 54 , 96 , 105 , 3 , 1 , 0 }, // Lopunny Normal
        { 2 , 428 , 65 , 136 , 94 , 54 , 96 , 135 , 3 , 1 , 0 } // Lopunny Normal
    },
    {
        { 1 , 429 , 60 , 60 , 60 , 105 , 105 , 105 , 7 , 8 , 0 } // Mismagius Ghost
    },
    {
        { 1 , 430 , 100 , 125 , 52 , 105 , 52 , 71 , 1 , 17 , 3 } // Honchkrow Dark Flying
    },
    {
        { 1 , 431 , 49 , 55 , 42 , 42 , 37 , 85 , 4 , 1 , 0 } // Glameow Normal
    },
    {
        { 1 , 432 , 71 , 82 , 64 , 64 , 59 , 112 , 4 , 1 , 0 } // Purugly Normal
    },
    {
        { 1 , 433 , 45 , 30 , 50 , 65 , 50 , 45 , 10 , 14 , 0 } // Chingling Psychic
    },
    {
        { 1 , 434 , 63 , 63 , 47 , 41 , 41 , 74 , 7 , 4 , 17 } // Stunky Poison Dark
    },
    {
        { 1 , 435 , 103 , 93 , 67 , 71 , 61 , 84 , 7 , 4 , 17 } // Skuntank Poison Dark
    },
    {
        { 1 , 436 , 57 , 24 , 86 , 24 , 86 , 23 , 5 , 9 , 14 } // Bronzor Steel Psychic
    },
    {
        { 1 , 437 , 67 , 89 , 116 , 79 , 116 , 33 , 5 , 9 , 14 } // Bronzong Steel Psychic
    },
    {
        { 1 , 438 , 50 , 80 , 95 , 10 , 45 , 10 , 3 , 6 , 0 } // Bonsly Rock
    },
    {
        { 1 , 439 , 20 , 25 , 45 , 70 , 90 , 60 , 6 , 14 , 18 } // Mime Jr. Psychic Fairy
    },
    {
        { 1 , 440 , 100 , 5 , 5 , 15 , 65 , 30 , 6 , 1 , 0 } // Happiny Normal
    },
    {
        { 1 , 441 , 76 , 65 , 45 , 92 , 42 , 91 , 1 , 1 , 3 } // Chatot Normal Flying
    },
    {
        { 1 , 442 , 50 , 92 , 108 , 92 , 108 , 35 , 7 , 8 , 17 } // Spiritomb Ghost Dark
    },
    {
        { 1 , 443 , 58 , 70 , 45 , 40 , 45 , 42 , 2 , 16 , 5 } // Gible Dragon Ground
    },
    {
        { 1 , 444 , 68 , 90 , 65 , 50 , 55 , 82 , 2 , 16 , 5 } // Gabite Dragon Ground
    },
    {
        { 2 , 445 , 108 , 130 , 95 , 80 , 85 , 102 , 2 , 16 , 5 }, // Garchomp Dragon Ground
        { 2 , 445 , 108 , 170 , 115 , 120 , 95 , 92 , 2 , 16 , 5 } // Garchomp Dragon Ground
    },
    {
        { 1 , 446 , 135 , 85 , 40 , 40 , 85 , 5 , 1 , 1 , 0 } // Munchlax Normal
    },
    {
        { 1 , 447 , 40 , 70 , 40 , 35 , 40 , 60 , 2 , 2 , 0 } // Riolu Fighting
    },
    {
        { 2 , 448 , 70 , 110 , 70 , 115 , 70 , 90 , 2 , 2 , 9 }, // Lucario Fighting Steel
        { 2 , 448 , 70 , 145 , 88 , 140 , 70 , 112 , 2 , 2 , 9 } // Lucario Fighting Steel
    },
    {
        { 1 , 449 , 68 , 72 , 78 , 38 , 42 , 32 , 3 , 5 , 0 } // Hippopotas Ground
    },
    {
        { 1 , 450 , 108 , 112 , 118 , 68 , 72 , 47 , 3 , 5 , 0 } // Hippowdon Ground
    },
    {
        { 1 , 451 , 40 , 50 , 90 , 30 , 55 , 65 , 7 , 4 , 7 } // Skorupi Poison Bug
    },
    {
        { 1 , 452 , 70 , 90 , 110 , 60 , 75 , 95 , 7 , 4 , 17 } // Drapion Poison Dark
    },
    {
        { 1 , 453 , 48 , 61 , 40 , 61 , 40 , 50 , 2 , 4 , 2 } // Croagunk Poison Fighting
    },
    {
        { 1 , 454 , 83 , 106 , 65 , 86 , 65 , 85 , 2 , 4 , 2 } // Toxicroak Poison Fighting
    },
    {
        { 1 , 455 , 74 , 100 , 72 , 90 , 72 , 46 , 5 , 12 , 0 } // Carnivine Grass
    },
    {
        { 1 , 456 , 49 , 49 , 56 , 49 , 61 , 66 , 2 , 11 , 0 } // Finneon Water
    },
    {
        { 1 , 457 , 69 , 69 , 76 , 69 , 86 , 91 , 2 , 11 , 0 } // Lumineon Water
    },
    {
        { 1 , 458 , 45 , 20 , 50 , 60 , 120 , 50 , 2 , 11 , 3 } // Mantyke Water Flying
    },
    {
        { 1 , 459 , 60 , 62 , 50 , 62 , 60 , 40 , 9 , 12 , 15 } // Snover Grass Ice
    },
    {
        { 2 , 460 , 90 , 92 , 75 , 92 , 85 , 60 , 9 , 12 , 15 }, // Abomasnow Grass Ice
        { 2 , 460 , 90 , 132 , 105 , 132 , 105 , 30 , 9 , 12 , 15 } // Abomasnow Grass Ice
    },
    {
        { 1 , 461 , 70 , 120 , 65 , 45 , 85 , 125 , 1 , 17 , 15 } // Weavile Dark Ice
    },
    {
        { 1 , 462 , 70 , 70 , 115 , 130 , 90 , 60 , 4 , 13 , 9 } // Magnezone Electric Steel
    },
    {
        { 1 , 463 , 110 , 85 , 95 , 80 , 95 , 50 , 6 , 1 , 0 } // Lickilicky Normal
    },
    {
        { 1 , 464 , 115 , 140 , 130 , 55 , 55 , 40 , 4 , 5 , 6 } // Rhyperior Ground Rock
    },
    {
        { 1 , 465 , 100 , 100 , 125 , 110 , 50 , 50 , 2 , 12 , 0 } // Tangrowth Grass
    },
    {
        { 1 , 466 , 75 , 123 , 67 , 95 , 85 , 95 , 10 , 13 , 0 } // Electivire Electric
    },
    {
        { 1 , 467 , 75 , 95 , 67 , 125 , 95 , 83 , 8 , 10 , 0 } // Magmortar Fire
    },
    {
        { 1 , 468 , 85 , 50 , 95 , 120 , 115 , 80 , 9 , 18 , 3 } // Togekiss Fairy Flying
    },
    {
        { 1 , 469 , 86 , 76 , 86 , 116 , 56 , 95 , 5 , 7 , 3 } // Yanmega Bug Flying
    },
    {
        { 1 , 470 , 65 , 110 , 130 , 60 , 65 , 95 , 5 , 12 , 0 } // Leafeon Grass
    },
    {
        { 1 , 471 , 65 , 60 , 110 , 130 , 95 , 65 , 2 , 15 , 0 } // Glaceon Ice
    },
    {
        { 1 , 472 , 75 , 95 , 125 , 45 , 75 , 95 , 7 , 5 , 3 } // Gliscor Ground Flying
    },
    {
        { 1 , 473 , 110 , 130 , 80 , 70 , 60 , 80 , 3 , 15 , 5 } // Mamoswine Ice Ground
    },
    {
        { 1 , 474 , 85 , 80 , 70 , 135 , 75 , 90 , 8 , 1 , 0 } // Porygon-Z Normal
    },
    {
        { 2 , 475 , 68 , 125 , 65 , 65 , 115 , 80 , 9 , 14 , 2 }, // Gallade Psychic Fighting
        { 2 , 475 , 68 , 165 , 95 , 65 , 115 , 110 , 9 , 14 , 2 } // Gallade Psychic Fighting
    },
    {
        { 1 , 476 , 60 , 55 , 145 , 75 , 150 , 40 , 4 , 6 , 9 } // Probopass Rock Steel
    },
    {
        { 1 , 477 , 45 , 100 , 135 , 65 , 135 , 45 , 1 , 8 , 0 } // Dusknoir Ghost
    },
    {
        { 1 , 478 , 70 , 80 , 70 , 80 , 70 , 110 , 9 , 15 , 8 } // Froslass Ice Ghost
    },
    {
        { 6 , 479 , 50 , 50 , 77 , 95 , 77 , 91 , 8 , 13 , 8 }, // Rotom Electric Ghost
        { 6 , 479 , 50 , 65 , 107 , 105 , 107 , 86 , 8 , 13 , 10 }, // Rotom Electric Fire
        { 6 , 479 , 50 , 65 , 107 , 105 , 107 , 86 , 8 , 13 , 11 }, // Rotom Electric Water
        { 6 , 479 , 50 , 65 , 107 , 105 , 107 , 86 , 8 , 13 , 15 }, // Rotom Electric Ice
        { 6 , 479 , 50 , 65 , 107 , 105 , 107 , 86 , 8 , 13 , 3 }, // Rotom Electric Flying
        { 6 , 479 , 50 , 65 , 107 , 105 , 107 , 86 , 8 , 13 , 12 } // Rotom Electric Grass
    },
    {
        { 1 , 480 , 75 , 75 , 130 , 75 , 130 , 95 , 10 , 14 , 0 } // Uxie Psychic
    },
    {
        { 1 , 481 , 80 , 105 , 105 , 105 , 105 , 80 , 6 , 14 , 0 } // Mesprit Psychic
    },
    {
        { 1 , 482 , 75 , 125 , 70 , 125 , 70 , 115 , 2 , 14 , 0 } // Azelf Psychic
    },
    {
        { 1 , 483 , 100 , 120 , 120 , 150 , 100 , 90 , 9 , 9 , 16 } // Dialga Steel Dragon
    },
    {
        { 1 , 484 , 90 , 120 , 100 , 150 , 120 , 100 , 7 , 11 , 16 } // Palkia Water Dragon
    },
    {
        { 1 , 485 , 91 , 90 , 106 , 130 , 106 , 77 , 3 , 10 , 9 } // Heatran Fire Steel
    },
    {
        { 1 , 486 , 110 , 160 , 110 , 80 , 110 , 100 , 9 , 1 , 0 } // Regigigas Normal
    },
    {
        { 2 , 487 , 150 , 100 , 120 , 100 , 120 , 90 , 1 , 8 , 16 }, // Giratina Ghost Dragon
        { 2 , 487 , 150 , 120 , 100 , 120 , 100 , 90 , 1 , 8 , 16 } // Giratina Ghost Dragon
    },
    {
        { 1 , 488 , 120 , 70 , 120 , 75 , 130 , 85 , 10 , 14 , 0 } // Cresselia Psychic
    },
    {
        { 1 , 489 , 80 , 80 , 80 , 80 , 80 , 80 , 2 , 11 , 0 } // Phione Water
    },
    {
        { 1 , 490 , 100 , 100 , 100 , 100 , 100 , 100 , 2 , 11 , 0 } // Manaphy Water
    },
    {
        { 1 , 491 , 70 , 90 , 90 , 135 , 90 , 125 , 1 , 17 , 0 } // Darkrai Dark
    },
    {
        { 2 , 492 , 100 , 100 , 100 , 100 , 100 , 100 , 5 , 12 , 0 }, // Shaymin Grass
        { 2 , 492 , 100 , 103 , 75 , 120 , 75 , 127 , 5 , 12 , 3 } // Shaymin Grass Flying
    },
    {
        { 1 , 493 , 120 , 120 , 120 , 120 , 120 , 120 , 9 , 1 , 0 } // Arceus Normal
    },
    {
        { 1 , 494 , 100 , 100 , 100 , 100 , 100 , 100 , 10 , 14 , 10 } // Victini Psychic Fire
    },
    {
        { 1 , 495 , 45 , 45 , 55 , 45 , 55 , 63 , 5 , 12 , 0 } // Snivy Grass
    },
    {
        { 1 , 496 , 60 , 60 , 75 , 60 , 75 , 83 , 5 , 12 , 0 } // Servine Grass
    },
    {
        { 1 , 497 , 75 , 75 , 95 , 75 , 95 , 113 , 5 , 12 , 0 } // Serperior Grass
    },
    {
        { 1 , 498 , 65 , 63 , 45 , 45 , 45 , 45 , 8 , 10 , 0 } // Tepig Fire
    },
    {
        { 1 , 499 , 90 , 93 , 55 , 70 , 55 , 55 , 8 , 10 , 2 } // Pignite Fire Fighting
    },
    {
        { 1 , 500 , 110 , 123 , 65 , 100 , 65 , 65 , 8 , 10 , 2 } // Emboar Fire Fighting
    },
    {
        { 1 , 501 , 55 , 55 , 45 , 63 , 45 , 45 , 2 , 11 , 0 } // Oshawott Water
    },
    {
        { 1 , 502 , 75 , 75 , 60 , 83 , 60 , 60 , 2 , 11 , 0 } // Dewott Water
    },
    {
        { 1 , 503 , 95 , 100 , 85 , 108 , 70 , 70 , 2 , 11 , 0 } // Samurott Water
    },
    {
        { 1 , 504 , 45 , 55 , 39 , 35 , 39 , 42 , 3 , 1 , 0 } // Patrat Normal
    },
    {
        { 1 , 505 , 60 , 85 , 69 , 60 , 69 , 77 , 3 , 1 , 0 } // Watchog Normal
    },
    {
        { 1 , 506 , 45 , 60 , 45 , 25 , 45 , 55 , 3 , 1 , 0 } // Lillipup Normal
    },
    {
        { 1 , 507 , 65 , 80 , 65 , 35 , 65 , 60 , 4 , 1 , 0 } // Herdier Normal
    },
    {
        { 1 , 508 , 85 , 110 , 90 , 45 , 90 , 80 , 4 , 1 , 0 } // Stoutland Normal
    },
    {
        { 1 , 509 , 41 , 50 , 37 , 50 , 37 , 66 , 7 , 17 , 0 } // Purrloin Dark
    },
    {
        { 1 , 510 , 64 , 88 , 50 , 88 , 50 , 106 , 7 , 17 , 0 } // Liepard Dark
    },
    {
        { 1 , 511 , 50 , 53 , 48 , 53 , 48 , 64 , 5 , 12 , 0 } // Pansage Grass
    },
    {
        { 1 , 512 , 75 , 98 , 63 , 98 , 63 , 101 , 5 , 12 , 0 } // Simisage Grass
    },
    {
        { 1 , 513 , 50 , 53 , 48 , 53 , 48 , 64 , 8 , 10 , 0 } // Pansear Fire
    },
    {
        { 1 , 514 , 75 , 98 , 63 , 98 , 63 , 101 , 8 , 10 , 0 } // Simisear Fire
    },
    {
        { 1 , 515 , 50 , 53 , 48 , 53 , 48 , 64 , 2 , 11 , 0 } // Panpour Water
    },
    {
        { 1 , 516 , 75 , 98 , 63 , 98 , 63 , 101 , 2 , 11 , 0 } // Simipour Water
    },
    {
        { 1 , 517 , 76 , 25 , 45 , 67 , 55 , 24 , 6 , 14 , 0 } // Munna Psychic
    },
    {
        { 1 , 518 , 116 , 55 , 85 , 107 , 95 , 29 , 6 , 14 , 0 } // Musharna Psychic
    },
    {
        { 1 , 519 , 50 , 55 , 50 , 36 , 30 , 43 , 4 , 1 , 3 } // Pidove Normal Flying
    },
    {
        { 1 , 520 , 62 , 77 , 62 , 50 , 42 , 65 , 4 , 1 , 3 } // Tranquill Normal Flying
    },
    {
        { 1 , 521 , 80 , 115 , 80 , 65 , 55 , 93 , 4 , 1 , 3 } // Unfezant Normal Flying
    },
    {
        { 1 , 522 , 45 , 60 , 32 , 50 , 32 , 76 , 1 , 13 , 0 } // Blitzle Electric
    },
    {
        { 1 , 523 , 75 , 100 , 63 , 80 , 63 , 116 , 1 , 13 , 0 } // Zebstrika Electric
    },
    {
        { 1 , 524 , 55 , 75 , 85 , 25 , 25 , 15 , 2 , 6 , 0 } // Roggenrola Rock
    },
    {
        { 1 , 525 , 70 , 105 , 105 , 50 , 40 , 20 , 2 , 6 , 0 } // Boldore Rock
    },
    {
        { 1 , 526 , 85 , 135 , 130 , 60 , 80 , 25 , 2 , 6 , 0 } // Gigalith Rock
    },
    {
        { 1 , 527 , 65 , 45 , 43 , 55 , 43 , 72 , 2 , 14 , 3 } // Woobat Psychic Flying
    },
    {
        { 1 , 528 , 67 , 57 , 55 , 77 , 55 , 114 , 2 , 14 , 3 } // Swoobat Psychic Flying
    },
    {
        { 1 , 529 , 60 , 85 , 40 , 30 , 45 , 68 , 4 , 5 , 0 } // Drilbur Ground
    },
    {
        { 1 , 530 , 110 , 135 , 60 , 50 , 65 , 88 , 4 , 5 , 9 } // Excadrill Ground Steel
    },
    {
        { 2 , 531 , 103 , 60 , 86 , 60 , 86 , 50 , 6 , 1 , 0 }, // Audino Normal
        { 2 , 531 , 103 , 60 , 126 , 80 , 126 , 50 , 9 , 1 , 0 } // Audino Normal
    },
    {
        { 1 , 532 , 75 , 80 , 55 , 25 , 35 , 35 , 4 , 2 , 0 } // Timburr Fighting
    },
    {
        { 1 , 533 , 85 , 105 , 85 , 40 , 50 , 40 , 4 , 2 , 0 } // Gurdurr Fighting
    },
    {
        { 1 , 534 , 105 , 140 , 95 , 55 , 65 , 45 , 3 , 2 , 0 } // Conkeldurr Fighting
    },
    {
        { 1 , 535 , 50 , 50 , 40 , 50 , 40 , 64 , 2 , 11 , 0 } // Tympole Water
    },
    {
        { 1 , 536 , 75 , 65 , 55 , 65 , 55 , 69 , 2 , 11 , 5 } // Palpitoad Water Ground
    },
    {
        { 1 , 537 , 105 , 95 , 75 , 85 , 75 , 74 , 2 , 11 , 5 } // Seismitoad Water Ground
    },
    {
        { 1 , 538 , 120 , 100 , 85 , 30 , 85 , 45 , 8 , 2 , 0 } // Throh Fighting
    },
    {
        { 1 , 539 , 75 , 125 , 75 , 30 , 75 , 85 , 2 , 2 , 0 } // Sawk Fighting
    },
    {
        { 1 , 540 , 45 , 53 , 70 , 40 , 60 , 42 , 10 , 7 , 12 } // Sewaddle Bug Grass
    },
    {
        { 1 , 541 , 55 , 63 , 90 , 50 , 80 , 42 , 5 , 7 , 12 } // Swadloon Bug Grass
    },
    {
        { 1 , 542 , 75 , 103 , 80 , 70 , 80 , 92 , 10 , 7 , 12 } // Leavanny Bug Grass
    },
    {
        { 1 , 543 , 30 , 45 , 59 , 30 , 39 , 57 , 8 , 7 , 4 } // Venipede Bug Poison
    },
    {
        { 1 , 544 , 40 , 55 , 99 , 40 , 79 , 47 , 4 , 7 , 4 } // Whirlipede Bug Poison
    },
    {
        { 1 , 545 , 60 , 100 , 89 , 55 , 69 , 112 , 8 , 7 , 4 } // Scolipede Bug Poison
    },
    {
        { 1 , 546 , 40 , 27 , 60 , 37 , 50 , 66 , 5 , 12 , 18 } // Cottonee Grass Fairy
    },
    {
        { 1 , 547 , 60 , 67 , 85 , 77 , 75 , 116 , 5 , 12 , 18 } // Whimsicott Grass Fairy
    },
    {
        { 1 , 548 , 45 , 35 , 50 , 70 , 50 , 30 , 5 , 12 , 0 } // Petilil Grass
    },
    {
        { 1 , 549 , 70 , 60 , 75 , 110 , 75 , 90 , 5 , 12 , 0 } // Lilligant Grass
    },
    {
        { 1 , 550 , 70 , 92 , 65 , 80 , 55 , 98 , 5 , 11 , 0 } // Basculin Water
    },
    {
        { 1 , 551 , 50 , 72 , 35 , 35 , 35 , 65 , 3 , 5 , 17 } // Sandile Ground Dark
    },
    {
        { 1 , 552 , 60 , 82 , 45 , 45 , 45 , 74 , 3 , 5 , 17 } // Krokorok Ground Dark
    },
    {
        { 1 , 553 , 95 , 117 , 80 , 65 , 70 , 92 , 8 , 5 , 17 } // Krookodile Ground Dark
    },
    {
        { 1 , 554 , 70 , 90 , 45 , 15 , 45 , 50 , 8 , 10 , 0 } // Darumaka Fire
    },
    {
        { 2 , 555 , 105 , 140 , 55 , 30 , 55 , 95 , 8 , 10 , 0 }, // Darmanitan Fire
        { 2 , 555 , 105 , 30 , 105 , 140 , 105 , 55 , 2 , 10 , 14 } // Darmanitan Fire Psychic
    },
    {
        { 1 , 556 , 75 , 86 , 67 , 106 , 67 , 60 , 5 , 12 , 0 } // Maractus Grass
    },
    {
        { 1 , 557 , 50 , 65 , 85 , 35 , 35 , 55 , 8 , 7 , 6 } // Dwebble Bug Rock
    },
    {
        { 1 , 558 , 70 , 105 , 125 , 65 , 75 , 45 , 8 , 7 , 6 } // Crustle Bug Rock
    },
    {
        { 1 , 559 , 50 , 75 , 70 , 35 , 70 , 48 , 10 , 17 , 2 } // Scraggy Dark Fighting
    },
    {
        { 1 , 560 , 65 , 90 , 115 , 45 , 115 , 58 , 8 , 17 , 2 } // Scrafty Dark Fighting
    },
    {
        { 1 , 561 , 72 , 58 , 80 , 103 , 80 , 97 , 1 , 14 , 3 } // Sigilyph Psychic Flying
    },
    {
        { 1 , 562 , 38 , 30 , 85 , 55 , 65 , 30 , 1 , 8 , 0 } // Yamask Ghost
    },
    {
        { 1 , 563 , 58 , 50 , 145 , 95 , 105 , 30 , 10 , 8 , 0 } // Cofagrigus Ghost
    },
    {
        { 1 , 564 , 54 , 78 , 103 , 53 , 45 , 22 , 2 , 11 , 6 } // Tirtouga Water Rock
    },
    {
        { 1 , 565 , 74 , 108 , 133 , 83 , 65 , 32 , 2 , 11 , 6 } // Carracosta Water Rock
    },
    {
        { 1 , 566 , 55 , 112 , 45 , 74 , 45 , 70 , 10 , 6 , 3 } // Archen Rock Flying
    },
    {
        { 1 , 567 , 75 , 140 , 65 , 112 , 65 , 110 , 10 , 6 , 3 } // Archeops Rock Flying
    },
    {
        { 1 , 568 , 50 , 50 , 62 , 40 , 62 , 65 , 5 , 4 , 0 } // Trubbish Poison
    },
    {
        { 1 , 569 , 80 , 95 , 82 , 60 , 82 , 75 , 5 , 4 , 0 } // Garbodor Poison
    },
    {
        { 1 , 570 , 40 , 65 , 40 , 80 , 40 , 65 , 4 , 17 , 0 } // Zorua Dark
    },
    {
        { 1 , 571 , 60 , 105 , 60 , 120 , 60 , 105 , 4 , 17 , 0 } // Zoroark Dark
    },
    {
        { 1 , 572 , 55 , 50 , 40 , 40 , 40 , 75 , 4 , 1 , 0 } // Minccino Normal
    },
    {
        { 1 , 573 , 75 , 95 , 60 , 65 , 60 , 115 , 4 , 1 , 0 } // Cinccino Normal
    },
    {
        { 1 , 574 , 45 , 30 , 50 , 55 , 65 , 45 , 7 , 14 , 0 } // Gothita Psychic
    },
    {
        { 1 , 575 , 60 , 45 , 70 , 75 , 85 , 55 , 7 , 14 , 0 } // Gothorita Psychic
    },
    {
        { 1 , 576 , 70 , 55 , 95 , 95 , 110 , 65 , 7 , 14 , 0 } // Gothitelle Psychic
    },
    {
        { 1 , 577 , 45 , 30 , 40 , 105 , 50 , 20 , 5 , 14 , 0 } // Solosis Psychic
    },
    {
        { 1 , 578 , 65 , 40 , 50 , 125 , 60 , 30 , 5 , 14 , 0 } // Duosion Psychic
    },
    {
        { 1 , 579 , 110 , 65 , 75 , 125 , 85 , 30 , 5 , 14 , 0 } // Reuniclus Psychic
    },
    {
        { 1 , 580 , 62 , 44 , 50 , 44 , 50 , 55 , 2 , 11 , 3 } // Ducklett Water Flying
    },
    {
        { 1 , 581 , 75 , 87 , 63 , 87 , 63 , 98 , 9 , 11 , 3 } // Swanna Water Flying
    },
    {
        { 1 , 582 , 36 , 50 , 50 , 65 , 60 , 44 , 9 , 15 , 0 } // Vanillite Ice
    },
    {
        { 1 , 583 , 51 , 65 , 65 , 80 , 75 , 59 , 9 , 15 , 0 } // Vanillish Ice
    },
    {
        { 1 , 584 , 71 , 95 , 85 , 110 , 95 , 79 , 9 , 15 , 0 } // Vanilluxe Ice
    },
    {
        { 1 , 585 , 60 , 60 , 50 , 40 , 50 , 75 , 6 , 1 , 12 } // Deerling Normal Grass
    },
    {
        { 1 , 586 , 80 , 100 , 70 , 60 , 70 , 95 , 3 , 1 , 12 } // Sawsbuck Normal Grass
    },
    {
        { 1 , 587 , 55 , 75 , 60 , 75 , 60 , 103 , 9 , 13 , 3 } // Emolga Electric Flying
    },
    {
        { 1 , 588 , 50 , 75 , 45 , 40 , 45 , 60 , 2 , 7 , 0 } // Karrablast Bug
    },
    {
        { 1 , 589 , 70 , 135 , 105 , 60 , 105 , 20 , 4 , 7 , 9 } // Escavalier Bug Steel
    },
    {
        { 1 , 590 , 69 , 55 , 45 , 55 , 55 , 15 , 9 , 12 , 4 } // Foongus Grass Poison
    },
    {
        { 1 , 591 , 114 , 85 , 70 , 85 , 80 , 30 , 9 , 12 , 4 } // Amoonguss Grass Poison
    },
    {
        { 1 , 592 , 55 , 40 , 50 , 65 , 85 , 40 , 9 , 11 , 8 } // Frillish Water Ghost
    },
    {
        { 1 , 593 , 100 , 60 , 70 , 85 , 105 , 60 , 9 , 11 , 8 } // Jellicent Water Ghost
    },
    {
        { 1 , 594 , 165 , 75 , 80 , 40 , 45 , 65 , 6 , 11 , 0 } // Alomomola Water
    },
    {
        { 1 , 595 , 50 , 47 , 50 , 57 , 50 , 65 , 10 , 7 , 13 } // Joltik Bug Electric
    },
    {
        { 1 , 596 , 70 , 77 , 60 , 97 , 60 , 108 , 10 , 7 , 13 } // Galvantula Bug Electric
    },
    {
        { 1 , 597 , 44 , 50 , 91 , 24 , 86 , 10 , 4 , 12 , 9 } // Ferroseed Grass Steel
    },
    {
        { 1 , 598 , 74 , 94 , 131 , 54 , 116 , 20 , 4 , 12 , 9 } // Ferrothorn Grass Steel
    },
    {
        { 1 , 599 , 40 , 55 , 70 , 45 , 60 , 30 , 4 , 9 , 0 } // Klink Steel
    },
    {
        { 1 , 600 , 60 , 80 , 95 , 70 , 85 , 50 , 4 , 9 , 0 } // Klang Steel
    },
    {
        { 1 , 601 , 60 , 100 , 115 , 70 , 85 , 90 , 4 , 9 , 0 } // Klinklang Steel
    },
    {
        { 1 , 602 , 35 , 55 , 40 , 45 , 40 , 60 , 9 , 13 , 0 } // Tynamo Electric
    },
    {
        { 1 , 603 , 65 , 85 , 70 , 75 , 70 , 40 , 2 , 13 , 0 } // Eelektrik Electric
    },
    {
        { 1 , 604 , 85 , 115 , 80 , 105 , 80 , 50 , 2 , 13 , 0 } // Eelektross Electric
    },
    {
        { 1 , 605 , 55 , 55 , 55 , 85 , 55 , 30 , 2 , 14 , 0 } // Elgyem Psychic
    },
    {
        { 1 , 606 , 75 , 75 , 75 , 125 , 95 , 40 , 3 , 14 , 0 } // Beheeyem Psychic
    },
    {
        { 1 , 607 , 50 , 30 , 55 , 65 , 55 , 20 , 9 , 8 , 10 } // Litwick Ghost Fire
    },
    {
        { 1 , 608 , 60 , 40 , 60 , 95 , 60 , 55 , 1 , 8 , 10 } // Lampent Ghost Fire
    },
    {
        { 1 , 609 , 60 , 55 , 90 , 145 , 90 , 80 , 1 , 8 , 10 } // Chandelure Ghost Fire
    },
    {
        { 1 , 610 , 46 , 87 , 60 , 30 , 40 , 57 , 5 , 16 , 0 } // Axew Dragon
    },
    {
        { 1 , 611 , 66 , 117 , 70 , 40 , 50 , 67 , 5 , 16 , 0 } // Fraxure Dragon
    },
    {
        { 1 , 612 , 76 , 147 , 90 , 60 , 70 , 97 , 10 , 16 , 0 } // Haxorus Dragon
    },
    {
        { 1 , 613 , 55 , 70 , 40 , 60 , 40 , 40 , 9 , 15 , 0 } // Cubchoo Ice
    },
    {
        { 1 , 614 , 95 , 130 , 80 , 70 , 80 , 50 , 9 , 15 , 0 } // Beartic Ice
    },
    {
        { 1 , 615 , 80 , 50 , 50 , 95 , 135 , 105 , 2 , 15 , 0 } // Cryogonal Ice
    },
    {
        { 1 , 616 , 50 , 40 , 85 , 40 , 65 , 25 , 8 , 7 , 0 } // Shelmet Bug
    },
    {
        { 1 , 617 , 80 , 70 , 40 , 100 , 60 , 145 , 8 , 7 , 0 } // Accelgor Bug
    },
    {
        { 1 , 618 , 109 , 66 , 84 , 81 , 99 , 32 , 3 , 5 , 13 } // Stunfisk Ground Electric
    },
    {
        { 1 , 619 , 45 , 85 , 50 , 55 , 50 , 65 , 10 , 2 , 0 } // Mienfoo Fighting
    },
    {
        { 1 , 620 , 65 , 125 , 60 , 95 , 60 , 105 , 7 , 2 , 0 } // Mienshao Fighting
    },
    {
        { 1 , 621 , 77 , 120 , 90 , 60 , 90 , 48 , 8 , 16 , 0 } // Druddigon Dragon
    },
    {
        { 1 , 622 , 59 , 74 , 50 , 35 , 50 , 35 , 5 , 5 , 8 } // Golett Ground Ghost
    },
    {
        { 1 , 623 , 89 , 124 , 80 , 55 , 80 , 55 , 5 , 5 , 8 } // Golurk Ground Ghost
    },
    {
        { 1 , 624 , 45 , 85 , 70 , 40 , 40 , 60 , 8 , 17 , 9 } // Pawniard Dark Steel
    },
    {
        { 1 , 625 , 65 , 125 , 100 , 60 , 70 , 70 , 8 , 17 , 9 } // Bisharp Dark Steel
    },
    {
        { 1 , 626 , 95 , 110 , 95 , 40 , 95 , 55 , 3 , 1 , 0 } // Bouffalant Normal
    },
    {
        { 1 , 627 , 70 , 83 , 50 , 37 , 50 , 60 , 9 , 1 , 3 } // Rufflet Normal Flying
    },
    {
        { 1 , 628 , 100 , 123 , 75 , 57 , 75 , 80 , 8 , 1 , 3 } // Braviary Normal Flying
    },
    {
        { 1 , 629 , 70 , 55 , 75 , 45 , 65 , 60 , 3 , 17 , 3 } // Vullaby Dark Flying
    },
    {
        { 1 , 630 , 110 , 65 , 105 , 55 , 95 , 80 , 3 , 17 , 3 } // Mandibuzz Dark Flying
    },
    {
        { 1 , 631 , 85 , 97 , 66 , 105 , 66 , 65 , 8 , 10 , 0 } // Heatmor Fire
    },
    {
        { 1 , 632 , 58 , 109 , 112 , 48 , 48 , 109 , 4 , 7 , 9 } // Durant Bug Steel
    },
    {
        { 1 , 633 , 52 , 65 , 50 , 45 , 50 , 38 , 2 , 17 , 16 } // Deino Dark Dragon
    },
    {
        { 1 , 634 , 72 , 85 , 70 , 65 , 70 , 58 , 2 , 17 , 16 } // Zweilous Dark Dragon
    },
    {
        { 1 , 635 , 92 , 105 , 90 , 125 , 90 , 98 , 2 , 17 , 16 } // Hydreigon Dark Dragon
    },
    {
        { 1 , 636 , 55 , 85 , 55 , 50 , 55 , 60 , 9 , 7 , 10 } // Larvesta Bug Fire
    },
    {
        { 1 , 637 , 85 , 60 , 65 , 135 , 105 , 100 , 9 , 7 , 10 } // Volcarona Bug Fire
    },
    {
        { 1 , 638 , 91 , 90 , 129 , 90 , 72 , 108 , 2 , 9 , 2 } // Cobalion Steel Fighting
    },
    {
        { 1 , 639 , 91 , 129 , 90 , 72 , 90 , 108 , 4 , 6 , 2 } // Terrakion Rock Fighting
    },
    {
        { 1 , 640 , 91 , 90 , 72 , 90 , 129 , 108 , 5 , 12 , 2 } // Virizion Grass Fighting
    },
    {
        { 2 , 641 , 79 , 115 , 70 , 125 , 80 , 111 , 5 , 3 , 0 }, // Tornadus Flying
        { 2 , 641 , 79 , 100 , 80 , 110 , 90 , 121 , 5 , 3 , 0 } // Tornadus Flying
    },
    {
        { 2 , 642 , 79 , 115 , 70 , 125 , 80 , 111 , 2 , 13 , 3 }, // Thundurus Electric Flying
        { 2 , 642 , 79 , 105 , 70 , 145 , 80 , 101 , 2 , 13 , 3 } // Thundurus Electric Flying
    },
    {
        { 1 , 643 , 100 , 120 , 100 , 150 , 120 , 90 , 9 , 16 , 10 } // Reshiram Dragon Fire
    },
    {
        { 1 , 644 , 100 , 150 , 120 , 120 , 100 , 90 , 1 , 16 , 13 } // Zekrom Dragon Electric
    },
    {
        { 2 , 645 , 89 , 125 , 90 , 115 , 80 , 101 , 3 , 5 , 3 }, // Landorus Ground Flying
        { 2 , 645 , 89 , 145 , 90 , 105 , 80 , 91 , 3 , 5 , 3 } // Landorus Ground Flying
    },
    {
        { 3 , 646 , 125 , 130 , 90 , 130 , 90 , 95 , 4 , 16 , 15 }, // Kyurem Dragon Ice
        { 3 , 646 , 125 , 170 , 100 , 120 , 90 , 95 , 4 , 16 , 15 }, // Kyurem Dragon Ice
        { 3 , 646 , 125 , 120 , 90 , 170 , 100 , 95 , 4 , 16 , 15 } // Kyurem Dragon Ice
    },
    {
        { 1 , 647 , 91 , 72 , 90 , 129 , 90 , 108 , 10 , 11 , 2 } // Keldeo Water Fighting
    },
    {
        { 2 , 648 , 100 , 77 , 77 , 128 , 128 , 90 , 9 , 1 , 14 }, // Meloetta Normal Psychic
        { 2 , 648 , 100 , 128 , 90 , 77 , 77 , 128 , 9 , 1 , 2 } // Meloetta Normal Fighting
    },
    {
        { 1 , 649 , 71 , 120 , 95 , 120 , 95 , 99 , 7 , 7 , 9 } // Genesect Bug Steel
    },
    {
        { 1 , 650 , 56 , 61 , 65 , 48 , 45 , 38 , 5 , 12 , 0 } // Chespin Grass
    },
    {
        { 1 , 651 , 61 , 78 , 95 , 56 , 58 , 57 , 5 , 12 , 0 } // Quilladin Grass
    },
    {
        { 1 , 652 , 88 , 107 , 122 , 74 , 75 , 64 , 5 , 12 , 2 } // Chesnaught Grass Fighting
    },
    {
        { 1 , 653 , 40 , 45 , 40 , 62 , 60 , 60 , 8 , 10 , 0 } // Fennekin Fire
    },
    {
        { 1 , 654 , 59 , 59 , 58 , 90 , 70 , 73 , 8 , 10 , 0 } // Braixen Fire
    },
    {
        { 1 , 655 , 75 , 69 , 72 , 114 , 100 , 104 , 8 , 10 , 14 } // Delphox Fire Psychic
    },
    {
        { 1 , 656 , 41 , 56 , 40 , 62 , 44 , 71 , 2 , 11 , 0 } // Froakie Water
    },
    {
        { 1 , 657 , 54 , 63 , 52 , 83 , 56 , 97 , 2 , 11 , 0 } // Frogadier Water
    },
    {
        { 2 , 658 , 72 , 95 , 67 , 103 , 71 , 122 , 2 , 11 , 17 }, // Greninja Water Dark
        { 2 , 658 , 72 , 145 , 67 , 153 , 71 , 132 , 2 , 11 , 17 } // Greninja Water Dark
    },
    {
        { 1 , 659 , 38 , 36 , 38 , 32 , 36 , 57 , 3 , 1 , 0 } // Bunnelby Normal
    },
    {
        { 1 , 660 , 85 , 56 , 77 , 50 , 77 , 78 , 3 , 1 , 5 } // Diggersby Normal Ground
    },
    {
        { 1 , 661 , 45 , 50 , 43 , 40 , 38 , 62 , 8 , 1 , 3 } // Fletchling Normal Flying
    },
    {
        { 1 , 662 , 62 , 73 , 55 , 56 , 52 , 84 , 8 , 10 , 3 } // Fletchinder Fire Flying
    },
    {
        { 1 , 663 , 78 , 81 , 71 , 74 , 69 , 126 , 8 , 10 , 3 } // Talonflame Fire Flying
    },
    {
        { 1 , 664 , 38 , 35 , 40 , 27 , 25 , 35 , 1 , 7 , 0 } // Scatterbug Bug
    },
    {
        { 1 , 665 , 45 , 22 , 60 , 27 , 30 , 29 , 1 , 7 , 0 } // Spewpa Bug
    },
    {
        { 1 , 666 , 80 , 52 , 50 , 90 , 50 , 89 , 9 , 7 , 3 } // Vivillon Bug Flying
    },
    {
        { 1 , 667 , 62 , 50 , 58 , 73 , 54 , 72 , 3 , 10 , 1 } // Litleo Fire Normal
    },
    {
        { 1 , 668 , 86 , 68 , 72 , 109 , 66 , 106 , 3 , 10 , 1 } // Pyroar Fire Normal
    },
    {
        { 1 , 669 , 44 , 38 , 39 , 61 , 79 , 42 , 9 , 18 , 0 } // Flabébé Fairy
    },
    {
        { 1 , 670 , 54 , 45 , 47 , 75 , 98 , 52 , 9 , 18 , 0 } // Floette Fairy
    },
    {
        { 1 , 671 , 78 , 65 , 68 , 112 , 154 , 75 , 9 , 18 , 0 } // Florges Fairy
    },
    {
        { 1 , 672 , 66 , 65 , 48 , 62 , 57 , 52 , 3 , 12 , 0 } // Skiddo Grass
    },
    {
        { 1 , 673 , 123 , 100 , 62 , 97 , 81 , 68 , 3 , 12 , 0 } // Gogoat Grass
    },
    {
        { 1 , 674 , 67 , 82 , 62 , 46 , 48 , 43 , 9 , 2 , 0 } // Pancham Fighting
    },
    {
        { 1 , 675 , 95 , 124 , 78 , 69 , 71 , 58 , 9 , 2 , 17 } // Pangoro Fighting Dark
    },
    {
        { 1 , 676 , 75 , 80 , 60 , 65 , 90 , 102 , 9 , 1 , 0 } // Furfrou Normal
    },
    {
        { 1 , 677 , 62 , 48 , 54 , 63 , 60 , 68 , 4 , 14 , 0 } // Espurr Psychic
    },
    {
        { 1 , 678 , 74 , 48 , 76 , 83 , 81 , 104 , 2 , 14 , 0 } // Meowstic Psychic
    },
    {
        { 1 , 679 , 45 , 80 , 100 , 35 , 37 , 28 , 3 , 9 , 8 } // Honedge Steel Ghost
    },
    {
        { 1 , 680 , 59 , 110 , 150 , 45 , 49 , 35 , 3 , 9 , 8 } // Doublade Steel Ghost
    },
    {
        { 2 , 681 , 60 , 50 , 150 , 50 , 150 , 60 , 3 , 9 , 8 }, // Aegislash Steel Ghost
        { 2 , 681 , 60 , 150 , 50 , 150 , 50 , 60 , 3 , 9 , 8 } // Aegislash Steel Ghost
    },
    {
        { 1 , 682 , 78 , 52 , 60 , 63 , 65 , 23 , 6 , 18 , 0 } // Spritzee Fairy
    },
    {
        { 1 , 683 , 101 , 72 , 72 , 99 , 89 , 29 , 6 , 18 , 0 } // Aromatisse Fairy
    },
    {
        { 1 , 684 , 62 , 48 , 66 , 59 , 57 , 49 , 9 , 18 , 0 } // Swirlix Fairy
    },
    {
        { 1 , 685 , 82 , 80 , 86 , 85 , 75 , 72 , 9 , 18 , 0 } // Slurpuff Fairy
    },
    {
        { 1 , 686 , 53 , 54 , 53 , 37 , 46 , 45 , 2 , 17 , 14 } // Inkay Dark Psychic
    },
    {
        { 1 , 687 , 86 , 92 , 88 , 68 , 75 , 73 , 2 , 17 , 14 } // Malamar Dark Psychic
    },
    {
        { 1 , 688 , 42 , 52 , 67 , 39 , 56 , 50 , 3 , 6 , 11 } // Binacle Rock Water
    },
    {
        { 1 , 689 , 72 , 105 , 115 , 54 , 86 , 68 , 3 , 6 , 11 } // Barbaracle Rock Water
    },
    {
        { 1 , 690 , 50 , 60 , 60 , 60 , 60 , 30 , 3 , 4 , 11 } // Skrelp Poison Water
    },
    {
        { 1 , 691 , 65 , 75 , 90 , 97 , 123 , 44 , 3 , 4 , 16 } // Dragalge Poison Dragon
    },
    {
        { 1 , 692 , 50 , 53 , 62 , 58 , 63 , 44 , 2 , 11 , 0 } // Clauncher Water
    },
    {
        { 1 , 693 , 71 , 73 , 88 , 120 , 89 , 59 , 2 , 11 , 0 } // Clawitzer Water
    },
    {
        { 1 , 694 , 44 , 38 , 33 , 61 , 43 , 70 , 10 , 13 , 1 } // Helioptile Electric Normal
    },
    {
        { 1 , 695 , 62 , 55 , 52 , 109 , 94 , 109 , 10 , 13 , 1 } // Heliolisk Electric Normal
    },
    {
        { 1 , 696 , 58 , 89 , 77 , 45 , 45 , 48 , 3 , 6 , 16 } // Tyrunt Rock Dragon
    },
    {
        { 1 , 697 , 82 , 121 , 119 , 69 , 59 , 71 , 8 , 6 , 16 } // Tyrantrum Rock Dragon
    },
    {
        { 1 , 698 , 77 , 59 , 50 , 67 , 63 , 46 , 2 , 6 , 15 } // Amaura Rock Ice
    },
    {
        { 1 , 699 , 123 , 77 , 72 , 99 , 92 , 58 , 2 , 6 , 15 } // Aurorus Rock Ice
    },
    {
        { 1 , 700 , 95 , 65 , 65 , 110 , 130 , 60 , 6 , 18 , 0 } // Sylveon Fairy
    },
    {
        { 1 , 701 , 78 , 92 , 75 , 74 , 63 , 118 , 5 , 2 , 3 } // Hawlucha Fighting Flying
    },
    {
        { 1 , 702 , 67 , 58 , 57 , 81 , 67 , 101 , 10 , 13 , 18 } // Dedenne Electric Fairy
    },
    {
        { 1 , 703 , 50 , 50 , 150 , 50 , 150 , 50 , 4 , 6 , 18 } // Carbink Rock Fairy
    },
    {
        { 1 , 704 , 45 , 50 , 35 , 55 , 75 , 40 , 7 , 16 , 0 } // Goomy Dragon
    },
    {
        { 1 , 705 , 68 , 75 , 53 , 83 , 113 , 60 , 7 , 16 , 0 } // Sliggoo Dragon
    },
    {
        { 1 , 706 , 90 , 100 , 70 , 110 , 150 , 80 , 7 , 16 , 0 } // Goodra Dragon
    },
    {
        { 1 , 707 , 57 , 80 , 91 , 80 , 87 , 75 , 4 , 9 , 18 } // Klefki Steel Fairy
    },
    {
        { 1 , 708 , 43 , 70 , 48 , 50 , 60 , 38 , 3 , 8 , 12 } // Phantump Ghost Grass
    },
    {
        { 1 , 709 , 85 , 110 , 76 , 65 , 82 , 56 , 3 , 8 , 12 } // Trevenant Ghost Grass
    },
    {
        { 4 , 710 , 44 , 66 , 70 , 44 , 55 , 56 , 3 , 8 , 12 }, // Pumpkaboo Ghost Grass
        { 4 , 710 , 49 , 66 , 70 , 44 , 55 , 51 , 3 , 8 , 12 }, // Pumpkaboo Ghost Grass
        { 4 , 710 , 54 , 66 , 70 , 44 , 55 , 46 , 3 , 8 , 12 }, // Pumpkaboo Ghost Grass
        { 4 , 710 , 59 , 66 , 70 , 44 , 55 , 41 , 3 , 8 , 12 } // Pumpkaboo Ghost Grass
    },
    {
        { 4 , 711 , 55 , 85 , 122 , 58 , 75 , 99 , 3 , 8 , 12 }, // Gourgeist Ghost Grass
        { 4 , 711 , 65 , 90 , 122 , 58 , 75 , 84 , 3 , 8 , 12 }, // Gourgeist Ghost Grass
        { 4 , 711 , 75 , 95 , 122 , 58 , 75 , 69 , 3 , 8 , 12 }, // Gourgeist Ghost Grass
        { 4 , 711 , 85 , 100 , 122 , 58 , 75 , 54 , 3 , 8 , 12 } // Gourgeist Ghost Grass
    },
    {
        { 1 , 712 , 55 , 69 , 85 , 32 , 35 , 28 , 2 , 15 , 0 } // Bergmite Ice
    },
    {
        { 1 , 713 , 95 , 117 , 184 , 44 , 46 , 28 , 2 , 15 , 0 } // Avalugg Ice
    },
    {
        { 1 , 714 , 40 , 30 , 35 , 45 , 40 , 55 , 7 , 3 , 16 } // Noibat Flying Dragon
    },
    {
        { 1 , 715 , 85 , 70 , 80 , 97 , 80 , 123 , 7 , 3 , 16 } // Noivern Flying Dragon
    },
    {
        { 1 , 716 , 126 , 131 , 95 , 131 , 98 , 99 , 2 , 18 , 0 } // Xerneas Fairy
    },
    {
        { 1 , 717 , 126 , 131 , 95 , 131 , 98 , 99 , 8 , 17 , 3 } // Yveltal Dark Flying
    },
    {
        { 3 , 718 , 108 , 100 , 121 , 81 , 95 , 95 , 5 , 16 , 5 }, // Zygarde Dragon Ground
        { 3 , 718 , 54 , 100 , 71 , 61 , 85 , 115 , 1 , 16 , 5 }, // Zygarde Dragon Ground
        { 3 , 718 , 216 , 100 , 121 , 91 , 95 , 85 , 1 , 16 , 5 } // Zygarde Dragon Ground
    },
    {
        { 2 , 719 , 50 , 100 , 150 , 100 , 150 , 50 , 6 , 6 , 18 }, // Diancie Rock Fairy
        { 2 , 719 , 50 , 160 , 110 , 160 , 110 , 110 , 6 , 6 , 18 } // Diancie Rock Fairy
    },
    {
        { 2 , 720 , 80 , 110 , 60 , 150 , 130 , 70 , 7 , 14 , 8 }, // Hoopa Psychic Ghost
        { 2 , 720 , 80 , 160 , 60 , 170 , 130 , 80 , 7 , 14 , 17 } // Hoopa Psychic Dark
    },
    {
        { 1 , 721 , 80 , 110 , 120 , 130 , 90 , 70 , 3 , 10 , 11 } // Volcanion Fire Water
    },
    {
        { 1 , 722 , 68 , 55 , 55 , 50 , 50 , 42 , 3 , 12 , 3 } // Rowlet Grass Flying
    },
    {
        { 1 , 723 , 78 , 75 , 75 , 70 , 70 , 52 , 3 , 12 , 3 } // Dartrix Grass Flying
    },
    {
        { 1 , 724 , 78 , 107 , 75 , 100 , 100 , 70 , 3 , 12 , 8 } // Decidueye Grass Ghost
    },
    {
        { 1 , 725 , 45 , 65 , 40 , 60 , 40 , 70 , 8 , 10 , 0 } // Litten Fire
    },
    {
        { 1 , 726 , 65 , 85 , 50 , 80 , 50 , 90 , 8 , 10 , 0 } // Torracat Fire
    },
    {
        { 1 , 727 , 95 , 115 , 90 , 80 , 90 , 60 , 8 , 10 , 17 } // Incineroar Fire Dark
    },
    {
        { 1 , 728 , 50 , 54 , 54 , 66 , 56 , 40 , 2 , 11 , 0 } // Popplio Water
    },
    {
        { 1 , 729 , 60 , 69 , 69 , 91 , 81 , 50 , 2 , 11 , 0 } // Brionne Water
    },
    {
        { 1 , 730 , 80 , 74 , 74 , 126 , 116 , 60 , 2 , 11 , 18 } // Primarina Water Fairy
    },
    {
        { 1 , 731 , 35 , 75 , 30 , 30 , 30 , 65 , 1 , 1 , 3 } // Pikipek Normal Flying
    },
    {
        { 1 , 732 , 55 , 85 , 50 , 40 , 50 , 75 , 1 , 1 , 3 } // Trumbeak Normal Flying
    },
    {
        { 1 , 733 , 80 , 120 , 75 , 75 , 75 , 60 , 1 , 1 , 3 } // Toucannon Normal Flying
    },
    {
        { 1 , 734 , 48 , 70 , 30 , 30 , 30 , 45 , 3 , 1 , 0 } // Yungoos Normal
    },
    {
        { 1 , 735 , 88 , 110 , 60 , 55 , 60 , 45 , 3 , 1 , 0 } // Gumshoos Normal
    },
    {
        { 1 , 736 , 47 , 62 , 45 , 55 , 45 , 46 , 4 , 7 , 0 } // Grubbin Bug
    },
    {
        { 1 , 737 , 57 , 82 , 95 , 55 , 75 , 36 , 5 , 7 , 13 } // Charjabug Bug Electric
    },
    {
        { 1 , 738 , 77 , 70 , 90 , 145 , 75 , 43 , 2 , 7 , 13 } // Vikavolt Bug Electric
    },
    {
        { 1 , 739 , 47 , 82 , 57 , 42 , 47 , 63 , 7 , 2 , 0 } // Crabrawler Fighting
    },
    {
        { 1 , 740 , 97 , 132 , 77 , 62 , 67 , 43 , 9 , 2 , 15 } // Crabominable Fighting Ice
    },
    {
        { 4 , 741 , 75 , 70 , 70 , 98 , 70 , 93 , 9 , 13 , 3 }, // Oricorio Electric Flying
        { 4 , 741 , 75 , 70 , 70 , 98 , 70 , 93 , 7 , 10 , 3 }, // Oricorio Fire Flying
        { 4 , 741 , 75 , 70 , 70 , 98 , 70 , 93 , 5 , 14 , 3 }, // Oricorio Psychic Flying
        { 4 , 741 , 75 , 70 , 70 , 98 , 70 , 93 , 6 , 8 , 3 } // Oricorio Ghost Flying
    },
    {
        { 1 , 742 , 40 , 45 , 40 , 55 , 40 , 84 , 10 , 7 , 18 } // Cutiefly Bug Fairy
    },
    {
        { 1 , 743 , 60 , 55 , 60 , 95 , 70 , 124 , 10 , 7 , 18 } // Ribombee Bug Fairy
    },
    {
        { 1 , 744 , 45 , 65 , 40 , 30 , 40 , 60 , 3 , 6 , 0 } // Rockruff Rock
    },
    {
        { 2 , 745 , 75 , 115 , 65 , 55 , 65 , 112 , 3 , 6 , 0 }, // Lycanroc Rock
        { 2 , 745 , 85 , 115 , 75 , 55 , 75 , 82 , 8 , 6 , 0 } // Lycanroc Rock
    },
    {
        { 2 , 746 , 45 , 20 , 20 , 25 , 25 , 40 , 2 , 11 , 0 }, // Wishiwashi Water
        { 2 , 746 , 45 , 140 , 130 , 140 , 135 , 30 , 2 , 11 , 0 } // Wishiwashi Water
    },
    {
        { 1 , 747 , 50 , 53 , 62 , 43 , 52 , 45 , 2 , 4 , 11 } // Mareanie Poison Water
    },
    {
        { 1 , 748 , 50 , 63 , 152 , 53 , 142 , 35 , 2 , 4 , 11 } // Toxapex Poison Water
    },
    {
        { 1 , 749 , 70 , 100 , 70 , 45 , 55 , 45 , 3 , 5 , 0 } // Mudbray Ground
    },
    {
        { 1 , 750 , 100 , 125 , 100 , 55 , 85 , 35 , 3 , 5 , 0 } // Mudsdale Ground
    },
    {
        { 1 , 751 , 38 , 40 , 52 , 40 , 72 , 27 , 5 , 11 , 7 } // Dewpider Water Bug
    },
    {
        { 1 , 752 , 68 , 70 , 92 , 50 , 132 , 42 , 5 , 11 , 7 } // Araquanid Water Bug
    },
    {
        { 1 , 753 , 40 , 55 , 35 , 50 , 35 , 35 , 6 , 12 , 0 } // Fomantis Grass
    },
    {
        { 1 , 754 , 70 , 105 , 90 , 80 , 90 , 45 , 6 , 12 , 0 } // Lurantis Grass
    },
    {
        { 1 , 755 , 40 , 35 , 55 , 65 , 75 , 15 , 7 , 12 , 18 } // Morelull Grass Fairy
    },
    {
        { 1 , 756 , 60 , 45 , 80 , 90 , 100 , 30 , 7 , 12 , 18 } // Shiinotic Grass Fairy
    },
    {
        { 1 , 757 , 48 , 44 , 40 , 71 , 40 , 77 , 1 , 4 , 10 } // Salandit Poison Fire
    },
    {
        { 1 , 758 , 68 , 64 , 60 , 111 , 60 , 117 , 1 , 4 , 10 } // Salazzle Poison Fire
    },
    {
        { 1 , 759 , 70 , 75 , 50 , 45 , 50 , 50 , 6 , 1 , 2 } // Stufful Normal Fighting
    },
    {
        { 1 , 760 , 120 , 125 , 80 , 55 , 60 , 60 , 6 , 1 , 2 } // Bewear Normal Fighting
    },
    {
        { 1 , 761 , 42 , 30 , 38 , 30 , 38 , 32 , 7 , 12 , 0 } // Bounsweet Grass
    },
    {
        { 1 , 762 , 52 , 40 , 48 , 40 , 48 , 62 , 7 , 12 , 0 } // Steenee Grass
    },
    {
        { 1 , 763 , 72 , 120 , 98 , 50 , 98 , 72 , 7 , 12 , 0 } // Tsareena Grass
    },
    {
        { 1 , 764 , 51 , 52 , 90 , 82 , 110 , 100 , 5 , 18 , 0 } // Comfey Fairy
    },
    {
        { 1 , 765 , 90 , 60 , 80 , 90 , 110 , 60 , 9 , 1 , 14 } // Oranguru Normal Psychic
    },
    {
        { 1 , 766 , 100 , 120 , 90 , 40 , 60 , 80 , 9 , 2 , 0 } // Passimian Fighting
    },
    {
        { 1 , 767 , 25 , 35 , 40 , 20 , 30 , 80 , 4 , 7 , 11 } // Wimpod Bug Water
    },
    {
        { 1 , 768 , 75 , 125 , 140 , 60 , 90 , 40 , 4 , 7 , 11 } // Golisopod Bug Water
    },
    {
        { 1 , 769 , 55 , 55 , 80 , 70 , 45 , 15 , 3 , 8 , 5 } // Sandygast Ghost Ground
    },
    {
        { 1 , 770 , 85 , 75 , 110 , 100 , 75 , 35 , 3 , 8 , 5 } // Palossand Ghost Ground
    },
    {
        { 1 , 771 , 55 , 60 , 130 , 30 , 130 , 5 , 1 , 11 , 0 } // Pyukumuku Water
    },
    {
        { 1 , 772 , 95 , 95 , 95 , 95 , 95 , 59 , 4 , 1 , 0 } // Type: Null Normal
    },
    {
        { 1 , 773 , 95 , 95 , 95 , 95 , 95 , 95 , 4 , 1 , 0 } // Silvally Normal
    },
    {
        { 2 , 774 , 60 , 60 , 100 , 60 , 100 , 60 , 3 , 6 , 3 }, // Minior Rock Flying
        { 2 , 774 , 60 , 100 , 60 , 100 , 60 , 120 , 3 , 6 , 3 } // Minior Rock Flying
    },
    {
        { 1 , 775 , 65 , 115 , 65 , 75 , 95 , 65 , 2 , 1 , 0 } // Komala Normal
    },
    {
        { 1 , 776 , 60 , 78 , 135 , 91 , 85 , 36 , 8 , 10 , 16 } // Turtonator Fire Dragon
    },
    {
        { 1 , 777 , 65 , 98 , 63 , 40 , 73 , 96 , 4 , 13 , 9 } // Togedemaru Electric Steel
    },
    {
        { 1 , 778 , 55 , 90 , 80 , 50 , 105 , 96 , 10 , 8 , 18 } // Mimikyu Ghost Fairy
    },
    {
        { 1 , 779 , 68 , 105 , 70 , 70 , 70 , 92 , 6 , 11 , 14 } // Bruxish Water Psychic
    },
    {
        { 1 , 780 , 78 , 60 , 85 , 135 , 91 , 36 , 9 , 1 , 16 } // Drampa Normal Dragon
    },
    {
        { 1 , 781 , 70 , 131 , 100 , 86 , 90 , 40 , 5 , 8 , 12 } // Dhelmise Ghost Grass
    },
    {
        { 1 , 782 , 45 , 55 , 65 , 45 , 45 , 45 , 4 , 16 , 0 } // Jangmo-o Dragon
    },
    {
        { 1 , 783 , 55 , 75 , 90 , 65 , 70 , 65 , 4 , 16 , 2 } // Hakamo-o Dragon Fighting
    },
    {
        { 1 , 784 , 75 , 110 , 125 , 100 , 105 , 85 , 4 , 16 , 2 } // Kommo-o Dragon Fighting
    },
    {
        { 1 , 785 , 70 , 115 , 85 , 95 , 75 , 130 , 10 , 13 , 18 } // Tapu Koko Electric Fairy
    },
    {
        { 1 , 786 , 70 , 85 , 75 , 130 , 115 , 95 , 6 , 14 , 18 } // Tapu Lele Psychic Fairy
    },
    {
        { 1 , 787 , 70 , 130 , 115 , 85 , 95 , 75 , 8 , 12 , 18 } // Tapu Bulu Grass Fairy
    },
    {
        { 1 , 788 , 70 , 75 , 115 , 95 , 130 , 85 , 7 , 11 , 18 } // Tapu Fini Water Fairy
    },
    {
        { 1 , 789 , 43 , 29 , 31 , 29 , 31 , 37 , 2 , 14 , 0 } // Cosmog Psychic
    },
    {
        { 1 , 790 , 43 , 29 , 131 , 29 , 131 , 37 , 2 , 14 , 0 } // Cosmoem Psychic
    },
    {
        { 1 , 791 , 137 , 137 , 107 , 113 , 89 , 97 , 9 , 14 , 9 } // Solgaleo Psychic Steel
    },
    {
        { 1 , 792 , 137 , 113 , 89 , 137 , 107 , 97 , 7 , 14 , 8 } // Lunala Psychic Ghost
    },
    {
        { 1 , 793 , 109 , 53 , 47 , 127 , 131 , 103 , 9 , 6 , 4 } // Nihilego Rock Poison
    },
    {
        { 1 , 794 , 107 , 139 , 139 , 53 , 53 , 79 , 8 , 7 , 2 } // Buzzwole Bug Fighting
    },
    {
        { 1 , 795 , 71 , 137 , 37 , 137 , 37 , 151 , 9 , 7 , 2 } // Pheromosa Bug Fighting
    },
    {
        { 1 , 796 , 83 , 89 , 71 , 173 , 71 , 83 , 1 , 13 , 0 } // Xurkitree Electric
    },
    {
        { 1 , 797 , 97 , 101 , 103 , 107 , 101 , 61 , 5 , 9 , 3 } // Celesteela Steel Flying
    },
    {
        { 1 , 798 , 59 , 181 , 131 , 59 , 31 , 109 , 9 , 12 , 9 } // Kartana Grass Steel
    },
    {
        { 1 , 799 , 223 , 101 , 53 , 97 , 53 , 43 , 1 , 17 , 16 } // Guzzlord Dark Dragon
    },
    {
        { 1 , 800 , 97 , 107 , 101 , 127 , 89 , 79 , 1 , 14 , 0 } // Necrozma Psychic
    },
    {
        { 1 , 801 , 80 , 95 , 115 , 130 , 115 , 65 , 4 , 9 , 18 } // Magearna Steel Fairy
    },
    {
        { 1 , 802 , 90 , 125 , 80 , 90 , 90 , 125 , 4 , 2 , 8 } // Marshadow Fighting Ghost
    }
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
    "Fairy"        // 18
};

static const unsigned char TYPE_COLORS[][3] = {
    {168,168,120}, // 1
    {192,48,40}, // 2
    {168,144,240}, // 3
    {160,64,160}, // 4
    {224,192,104}, // 5
    {184,160,56}, // 6
    {168,184,32}, // 7
    {112,88,152}, // 8
    {184,184,208}, // 9
    {240,128,48}, // 10
    {104,144,240}, // 11
    {120,200,80}, // 12
    {248,208,48}, // 13
    {248,88,136}, // 14
    {152,216,216}, // 15
    {112,56,248}, // 16
    {112,88,72}, // 17
    {238,153,172} // 18
};

static const unsigned char TYPE_COLORS_DARK[][3] = {
    {109,109,78}, // 1
    {125,31,26}, // 2
    {109,94,156}, // 3
    {104,42,104}, // 4
    {146,125,68}, // 5
    {120,104,36}, // 6
    {109,120,21}, // 7
    {73,57,99}, // 8
    {120,120,135}, // 9
    {156,83,31}, // 10
    {68,94,156}, // 11
    {78,130,52}, // 12
    {161,135,31}, // 13
    {161,57,89}, // 14
    {99,141,141}, // 15
    {73,36,161}, // 16
    {73,57,47}, // 17
    {155,100,112} // 18
};

static const unsigned char PKM_COLORS[][6] = {
    {133,133,133, 44,44,44}, // 0 Black
    {104,144,240, 68,94,156}, // 1 Blue
    {204,153,102, 112,66,20}, // 2 Brown
    {209,209,224, 120,120,135}, // 3 Gray
    {100,211,100, 17,187,17}, // 4 Green
    {244,189,201, 238,153,172}, // 5 Pink
    {193,131,193, 160,64,160}, // 6 Purple
    {236,132,132, 226,66,66}, // 7 Red
    {255,255,255, 227,206,208}, // 8 White
    {255,255,153, 255,215,51} // 9 Yellow
};


// MOVE COLOR CODING
static const unsigned char MOVE_TYPE_RED[] = {
255, 168, 192, 168, 168, 168, 168, 240, 152, 248, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 120, 168, 192, 168, 192, 192, 224, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 160, 168, 168, 168, 112, 168, 168, 168, 168, 168, 168, 160, 240, 240, 152, 104, 104, 104, 152, 152, 248, 104, 152, 168, 168, 168, 192, 192, 192, 192, 168, 120, 120, 120, 168, 120, 120, 160, 120, 120, 120, 168, 112, 240, 248, 248, 248, 248, 184, 224, 224, 224, 160, 248, 248, 248, 248, 248, 168, 168, 248, 112, 168, 168, 168, 168, 168, 168, 168, 112, 104, 168, 248, 248, 152, 248, 168, 168, 168, 168, 168, 168, 112, 160, 160, 224, 240, 104, 104, 168, 168, 168, 168, 248, 248, 168, 192, 168, 248, 160, 168, 168, 168, 168, 168, 104, 168, 120, 168, 248, 168, 160, 104, 168, 168, 224, 248, 184, 168, 168, 168, 168, 168, 168, 168, 168, 168, 192, 112, 168, 168, 112, 240, 168, 112, 168, 168, 168, 120, 192, 112, 152, 168, 192, 168, 112, 238, 168, 160, 224, 104, 224, 248, 168, 112, 168, 152, 192, 224, 168, 112, 184, 120, 168, 238, 184, 168, 168, 168, 248, 168, 184, 168, 168, 168, 168, 168, 168, 168, 168, 168, 240, 224, 192, 168, 112, 168, 168, 112, 168, 168, 184, 184, 192, 168, 120, 238, 168, 192, 112, 104, 240, 112, 248, 168, 168, 184, 112, 248, 192, 104, 112, 168, 168, 168, 168, 168, 240, 152, 112, 112, 240, 112, 168, 192, 168, 168, 168, 248, 112, 168, 248, 248, 168, 168, 120, 192, 248, 168, 192, 192, 168, 112, 168, 240, 248, 248, 168, 112, 112, 168, 104, 192, 168, 168, 248, 248, 168, 168, 240, 224, 152, 120, 168, 168, 160, 168, 240, 104, 184, 112, 168, 120, 112, 168, 240, 168, 184, 168, 184, 120, 168, 248, 104, 168, 112, 248, 192, 224, 152, 104, 120, 168, 152, 184, 168, 168, 112, 120, 192, 168, 224, 160, 168, 248, 120, 104, 248, 120, 112, 184, 248, 104, 184, 248, 168, 248, 248, 192, 192, 184, 248, 104, 168, 168, 168, 168, 168, 184, 168, 192, 112, 112, 112, 112, 248, 168, 248, 168, 248, 160, 168, 168, 168, 248, 248, 112, 168, 120, 112, 160, 248, 104, 248, 240, 192, 192, 184, 160, 112, 112, 104, 120, 168, 168, 168, 112, 112, 184, 192, 192, 192, 120, 168, 224, 112, 168, 112, 184, 152, 152, 112, 248, 152, 240, 112, 224, 248, 248, 184, 184, 168, 168, 248, 112, 248, 240, 120, 120, 184, 160, 160, 184, 184, 184, 168, 184, 120, 168, 168, 168, 248, 120, 104, 168, 168, 168, 184, 168, 112, 112, 248, 168, 240, 112, 120, 112, 112, 112, 184, 248, 248, 248, 248, 160, 184, 168, 248, 248, 184, 192, 240, 160, 168, 184, 248, 248, 104, 240, 160, 192, 160, 112, 168, 168, 168, 168, 168, 168, 160, 248, 192, 248, 104, 168, 248, 112, 168, 184, 192, 240, 112, 168, 168, 168, 192, 168, 240, 104, 240, 120, 248, 168, 224, 152, 112, 168, 248, 248, 224, 112, 248, 120, 192, 104, 240, 120, 168, 120, 112, 248, 168, 168, 168, 184, 240, 168, 168, 192, 152, 248, 240, 240, 152, 152, 112, 152, 240, 240, 248, 192, 192, 160, 224, 168, 168, 112, 112, 168, 248, 248, 120, 120, 152, 238, 112, 112, 238, 238, 238, 120, 238, 248, 238, 238, 238, 168, 238, 184, 168, 168, 184, 104, 248, 104, 240, 120, 238, 248, 160, 168, 238, 248, 168, 248, 238, 168, 168, 238, 248, 168, 168, 192, 168, 224, 224, 224, 238, 104, 224, 168, 112, 168, 168, 192, 192, 168, 168, 160, 160, 224, 224, 184, 184, 168, 168, 112, 112, 184, 184, 240, 240, 104, 104, 120, 120, 248, 248, 248, 248, 152, 152, 112, 112, 112, 112, 238, 238, 248, 224, 168, 160, 112, 112, 104, 152, 238, 224, 120, 120, 120, 168, 160, 168, 184, 112, 168, 184, 248, 168, 240, 112, 240, 248, 184, 160, 168, 112, 120, 248, 168, 112, 112, 112, 152, 112, 112, 104, 238, 112, 248, 168, 168, 248, 240, 238, 248, 224, 112, 184, 104, 248, 112, 184, 112, 168, 248, 238, 168, 248
};
static const unsigned char MOVE_TYPE_GREEN[] = {
255, 168, 48, 168, 168, 168, 168, 128, 216, 208, 168, 168, 168, 168, 168, 168, 144, 144, 168, 144, 168, 168, 200, 168, 48, 168, 48, 48, 192, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 168, 64, 184, 184, 168, 88, 168, 168, 168, 168, 168, 168, 64, 128, 128, 216, 144, 144, 144, 216, 216, 88, 144, 216, 168, 144, 144, 48, 48, 48, 48, 168, 200, 200, 200, 168, 200, 200, 64, 200, 200, 200, 184, 56, 128, 208, 208, 208, 208, 160, 192, 192, 192, 64, 88, 88, 88, 88, 88, 168, 168, 88, 88, 168, 168, 168, 168, 168, 168, 168, 88, 144, 168, 88, 88, 216, 88, 168, 168, 168, 144, 168, 168, 88, 64, 64, 192, 128, 144, 144, 168, 168, 168, 168, 88, 88, 168, 48, 168, 88, 64, 168, 184, 168, 144, 168, 144, 168, 200, 168, 88, 168, 64, 144, 168, 168, 192, 88, 160, 168, 168, 168, 168, 168, 168, 168, 168, 168, 48, 88, 184, 168, 88, 128, 168, 88, 168, 168, 144, 200, 48, 88, 216, 168, 48, 168, 88, 153, 168, 64, 192, 144, 192, 208, 168, 88, 168, 216, 48, 192, 168, 56, 160, 200, 168, 153, 160, 168, 168, 168, 208, 184, 184, 168, 168, 168, 168, 168, 168, 168, 168, 168, 128, 192, 48, 184, 56, 168, 168, 88, 168, 168, 184, 184, 48, 168, 200, 153, 168, 48, 56, 144, 128, 88, 88, 168, 168, 160, 88, 88, 48, 144, 88, 168, 168, 168, 168, 168, 128, 216, 88, 88, 128, 88, 168, 48, 168, 168, 168, 208, 88, 168, 88, 88, 168, 168, 200, 48, 88, 168, 48, 48, 168, 88, 168, 128, 88, 88, 168, 88, 88, 168, 144, 48, 168, 184, 88, 88, 144, 168, 128, 192, 216, 200, 168, 168, 64, 168, 128, 144, 184, 88, 168, 200, 88, 144, 128, 168, 160, 184, 184, 200, 168, 88, 144, 184, 88, 88, 48, 192, 216, 144, 200, 144, 216, 184, 168, 168, 56, 200, 48, 144, 192, 64, 168, 208, 200, 144, 88, 200, 56, 160, 208, 144, 184, 88, 144, 88, 88, 48, 48, 184, 88, 144, 168, 168, 144, 144, 168, 184, 184, 48, 88, 88, 88, 88, 88, 168, 88, 168, 88, 64, 168, 168, 168, 88, 88, 88, 168, 200, 88, 64, 88, 144, 208, 128, 48, 48, 160, 64, 88, 88, 144, 200, 144, 184, 184, 56, 56, 160, 48, 48, 48, 200, 144, 192, 88, 168, 88, 184, 216, 216, 88, 208, 216, 128, 88, 192, 88, 88, 184, 184, 168, 144, 88, 56, 208, 128, 200, 200, 160, 64, 64, 184, 184, 160, 168, 160, 200, 144, 168, 184, 208, 200, 144, 184, 184, 184, 160, 168, 56, 56, 88, 168, 128, 88, 200, 88, 88, 88, 160, 88, 88, 88, 88, 64, 184, 184, 88, 88, 160, 48, 128, 64, 184, 184, 88, 208, 144, 128, 64, 48, 64, 88, 168, 168, 168, 168, 168, 168, 64, 88, 48, 88, 144, 168, 88, 88, 144, 184, 48, 128, 88, 144, 168, 168, 48, 168, 128, 144, 128, 200, 208, 184, 192, 216, 56, 168, 208, 208, 192, 56, 88, 200, 48, 144, 128, 200, 184, 200, 88, 88, 168, 144, 168, 184, 128, 168, 168, 48, 216, 208, 128, 128, 216, 216, 88, 216, 128, 128, 208, 48, 48, 64, 192, 184, 184, 88, 88, 168, 208, 208, 200, 200, 216, 153, 88, 88, 153, 153, 153, 200, 153, 208, 153, 153, 153, 168, 153, 184, 168, 168, 160, 144, 88, 144, 128, 200, 153, 208, 64, 184, 153, 208, 168, 208, 153, 168, 168, 153, 208, 168, 184, 48, 144, 192, 192, 192, 153, 144, 192, 144, 88, 168, 168, 48, 48, 144, 144, 64, 64, 192, 192, 160, 160, 184, 184, 88, 88, 184, 184, 128, 128, 144, 144, 200, 200, 208, 208, 88, 88, 216, 216, 56, 56, 88, 88, 153, 153, 208, 192, 184, 64, 88, 88, 144, 216, 153, 192, 200, 200, 200, 168, 64, 168, 184, 88, 184, 184, 88, 184, 128, 88, 128, 88, 184, 64, 168, 56, 200, 88, 144, 56, 56, 88, 216, 88, 88, 144, 153, 88, 208, 168, 168, 88, 128, 153, 88, 192, 88, 160, 144, 88, 88, 184, 88, 168, 208, 153, 168, 208
};
static const unsigned char MOVE_TYPE_BLUE[] = {
255, 120, 40, 120, 120, 120, 120, 48, 216, 48, 120, 120, 120, 120, 120, 120, 240, 240, 120, 240, 120, 120, 80, 120, 40, 120, 40, 40, 104, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 120, 160, 32, 32, 120, 72, 120, 120, 120, 120, 120, 120, 160, 48, 48, 216, 240, 240, 240, 216, 216, 136, 240, 216, 120, 240, 240, 40, 40, 40, 40, 120, 80, 80, 80, 120, 80, 80, 160, 80, 80, 80, 32, 248, 48, 48, 48, 48, 48, 56, 104, 104, 104, 160, 136, 136, 136, 136, 136, 120, 120, 136, 152, 120, 120, 120, 120, 120, 120, 120, 152, 240, 120, 136, 136, 216, 136, 120, 120, 120, 240, 120, 120, 152, 160, 160, 104, 48, 240, 240, 120, 120, 120, 120, 136, 136, 120, 40, 120, 136, 160, 120, 32, 120, 240, 120, 240, 120, 80, 120, 136, 120, 160, 240, 120, 120, 104, 136, 56, 120, 120, 120, 120, 120, 120, 120, 120, 120, 40, 72, 32, 120, 152, 48, 120, 152, 120, 120, 240, 80, 40, 152, 216, 120, 40, 120, 72, 172, 120, 160, 104, 240, 104, 48, 120, 152, 120, 216, 40, 104, 120, 248, 56, 80, 120, 172, 56, 120, 120, 120, 48, 32, 208, 120, 120, 120, 120, 120, 120, 120, 120, 120, 48, 104, 40, 32, 248, 120, 120, 72, 120, 120, 208, 208, 40, 120, 80, 172, 120, 40, 248, 240, 48, 72, 136, 120, 120, 56, 152, 136, 40, 240, 72, 120, 120, 120, 120, 120, 48, 216, 72, 72, 48, 72, 120, 40, 120, 120, 120, 48, 72, 120, 136, 136, 120, 120, 80, 40, 136, 120, 40, 40, 120, 72, 120, 48, 136, 136, 120, 152, 72, 120, 240, 40, 120, 32, 136, 136, 240, 120, 48, 104, 216, 80, 120, 120, 160, 120, 48, 240, 208, 152, 120, 80, 72, 240, 48, 120, 56, 32, 208, 80, 120, 136, 240, 32, 152, 136, 40, 104, 216, 240, 80, 240, 216, 208, 120, 120, 248, 80, 40, 240, 104, 160, 120, 48, 80, 240, 136, 80, 248, 56, 48, 240, 208, 136, 240, 136, 136, 40, 40, 208, 136, 240, 120, 120, 240, 240, 120, 208, 32, 40, 72, 72, 72, 72, 136, 120, 136, 120, 136, 160, 120, 120, 120, 136, 136, 72, 120, 80, 72, 160, 136, 240, 48, 48, 40, 40, 56, 160, 72, 72, 240, 80, 240, 32, 32, 248, 248, 56, 40, 40, 40, 80, 240, 104, 72, 120, 72, 208, 216, 216, 152, 48, 216, 48, 152, 104, 136, 136, 208, 208, 120, 240, 136, 248, 48, 48, 80, 80, 56, 160, 160, 208, 208, 56, 120, 56, 80, 240, 120, 32, 48, 80, 240, 32, 32, 32, 56, 120, 248, 248, 136, 120, 48, 72, 80, 152, 152, 72, 56, 136, 136, 136, 136, 160, 208, 32, 136, 136, 56, 40, 48, 160, 32, 208, 136, 48, 240, 48, 160, 40, 160, 72, 120, 120, 120, 120, 120, 120, 160, 136, 40, 136, 240, 120, 136, 152, 240, 208, 40, 48, 72, 240, 120, 120, 40, 120, 48, 240, 48, 80, 48, 32, 104, 216, 248, 120, 48, 48, 104, 248, 136, 80, 40, 240, 48, 80, 32, 80, 72, 136, 120, 240, 120, 208, 48, 120, 120, 40, 216, 48, 48, 48, 216, 216, 72, 216, 48, 48, 48, 40, 40, 160, 104, 32, 32, 152, 152, 120, 48, 48, 80, 80, 216, 172, 72, 72, 172, 172, 172, 80, 172, 48, 172, 172, 172, 120, 172, 208, 120, 120, 56, 240, 136, 240, 48, 80, 172, 48, 160, 32, 172, 48, 120, 48, 172, 120, 120, 172, 48, 120, 32, 40, 240, 104, 104, 104, 172, 240, 104, 240, 72, 120, 120, 40, 40, 240, 240, 160, 160, 104, 104, 56, 56, 32, 32, 152, 152, 208, 208, 48, 48, 240, 240, 80, 80, 48, 48, 136, 136, 216, 216, 248, 248, 72, 72, 172, 172, 48, 104, 32, 160, 152, 72, 240, 216, 172, 104, 80, 80, 80, 120, 160, 120, 208, 72, 32, 208, 136, 32, 48, 72, 48, 136, 208, 160, 120, 248, 80, 136, 240, 248, 248, 72, 216, 152, 72, 240, 172, 152, 48, 120, 120, 136, 48, 172, 136, 104, 152, 56, 240, 136, 152, 208, 152, 120, 48, 172, 120, 48
};


static const short MOVE_DAMAGE[] = {
-1, 40, 50, 15, 18, 80, 40, 75, 75, 75, 40, 55, -1, 80, -1, 50, 40, 60, -1, 90, 15, 80, 45, 65, 30, 120, 100, 60, -1, 70, 65, 15, -1, 40, 85, 15, 90, 120, 120, -1, 15, 25, 25, -1, 60, -1, -1, -1, -1, -1, -1, 40, 40, 90, -1, 40, 110, 90, 90, 110, 65, 65, 65, 150, 35, 80, 80, -1, -1, -1, 80, 20, 40, -1, -1, 55, 120, -1, -1, -1, 120, -1, -1, 35, 40, 90, -1, 110, 50, 100, -1, 80, -1, 50, 90, -1, -1, -1, 40, 20, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 200, 100, 30, 30, 65, 65, 110, 80, 35, 60, 130, 20, 10, -1, -1, -1, 130, -1, 100, -1, 15, 80, -1, 140, -1, 40, 70, -1, -1, -1, -1, -1, 100, 250, 18, 50, -1, 75, 80, -1, -1, 80, -1, 70, -1, 50, -1, 10, 60, -1, -1, -1, 60, 50, -1, -1, -1, 100, -1, -1, -1, 40, -1, 40, -1, 60, -1, -1, 90, 20, 65, -1, 120, -1, -1, -1, 55, -1, 25, -1, 120, -1, 75, -1, -1, 30, 40, -1, -1, 65, 40, 70, -1, -1, -1, -1, -1, -1, -1, -1, -1, 100, -1, 100, 120, 60, -1, -1, 40, 20, -1, 100, 50, 70, -1, -1, -1, 60, 100, 40, -1, -1, 80, -1, -1, 80, 60, 80, 120, 40, 35, -1, 40, 90, -1, -1, -1, 95, -1, -1, -1, -1, -1, 70, 150, 70, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 120, -1, -1, 60, 75, -1, 65, -1, 150, -1, -1, -1, -1, -1, 70, 80, 15, -1, -1, 70, 70, -1, -1, 85, -1, 30, 60, -1, 90, 50, 75, 150, 150, 90, 30, 50, -1, -1, 60, 130, -1, 60, 60, -1, -1, -1, -1, 150, 75, 60, 80, 85, 35, -1, 90, 25, 60, 25, -1, -1, -1, 80, 150, -1, 85, 55, 50, 60, 120, 60, -1, -1, 90, -1, 25, 60, 60, 140, 140, -1, -1, -1, 70, 100, -1, -1, 65, -1, 30, 60, -1, -1, -1, 70, 120, 50, 60, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 140, -1, 70, -1, -1, -1, -1, 120, 60, 80, -1, 80, 80, 70, 90, 80, 75, 80, 90, 85, 100, 80, 75, 40, 120, 90, 120, 90, -1, 150, -1, 40, 60, 40, 70, 65, 65, 65, 40, 65, 70, 80, 65, 80, 90, -1, -1, 130, 80, 80, 130, 120, 150, 70, 120, 80, 60, 100, -1, -1, -1, 65, 100, 60, 50, 120, 40, 90, -1, -1, 150, 35, 150, 100, -1, -1, 120, -1, 120, 60, 120, -1, -1, -1, -1, -1, 80, 65, -1, -1, -1, -1, 50, 60, 70, 95, -1, -1, 120, -1, -1, 50, -1, 65, 40, 95, -1, -1, -1, 60, 40, 70, 50, 20, -1, -1, 80, -1, -1, 65, 60, -1, 60, 60, -1, 55, -1, 70, -1, -1, 100, 80, 80, 80, 70, 50, 60, 60, 60, -1, 55, 90, 80, 40, 60, 75, 90, 75, -1, 65, 65, -1, 85, 100, 25, 110, 120, 50, 100, 120, 75, 85, 65, 130, 130, 80, 140, 140, 55, 85, 180, 100, 100, 100, -1, 120, -1, -1, 50, 90, -1, -1, -1, 65, -1, 90, 70, 40, -1, -1, 50, -1, -1, -1, -1, -1, 90, 40, 95, 140, -1, -1, -1, -1, 100, 110, 80, 15, 75, -1, -1, -1, -1, -1, -1, -1, -1, -1, 80, -1, -1, -1, 20, 40, 20, 40, 80, 90, 90, 90, 140, 110, 120, 120, 100, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 210, -1, 90, -1, 80, 85, 90, 100, -1, 95, -1, 125, 40, -1, -1, -1, -1, 80, 90, 80, -1, 80, 80, 20, 130, -1, 70, -1, 90, 100, 70, -1, 100, 110, 90, 60, -1, 180, 180, 195, -1, 195, 175, 210, -1, 185, 150, 130, 85, 75, 85, 40, 85, 160, 90, 100, 100, -1, 80, -1, 90, 195
};

// MOVE ACCURACY
static const short MOVE_ACC[] = {
-1, 100, 100, 85, 85, 85, 100, 100, 100, 100, 100, 100, -1, 100, -1, 95, 100, 100, -1, 95, 85, 75, 100, 100, 100, 75, 95, 85, 100, 100, 100, 85, -1, 100, 100, 90, 85, 100, 100, 100, 100, 100, 95, 100, 100, 100, -1, 55, 55, 90, 100, 100, 100, 100, -1, 100, 80, 100, 100, 70, 100, 100, 100, 90, 100, 100, 80, 100, 100, 100, 100, 100, 100, 90, -1, 95, 100, 75, 75, 75, 100, 95, 100, 85, 100, 100, 90, 70, 90, 100, -1, 100, 90, 100, 100, 60, -1, -1, 100, 100, -1, 100, -1, 85, -1, -1, -1, -1, 100, 100, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 100, 75, 100, 70, 100, 85, 85, 100, 85, 999, 100, 100, 100, -1, 80, -1, 90, 100, 100, 90, 85, 100, 75, 90, -1, 100, 100, 100, 100, 80, -1, -1, 90, 100, 80, 90, -1, 90, 90, -1, -1, 100, 90, 100, -1, 100, -1, 90, 100, -1, -1, 100, 100, 100, -1, 100, -1, 95, 100, 100, 100, 100, -1, 100, 100, 999, 75, -1, 100, 100, 85, -1, 50, -1, -1, -1, 95, -1, 90, -1, 100, -1, 100, -1, 100, 90, 100, 85, -1, 100, 95, 90, -1, 100, -1, -1, 100, 90, 100, -1, -1, 95, 100, 50, 85, 100, -1, 100, 100, 100, -1, 75, 95, 999, -1, -1, -1, 100, 80, 100, -1, -1, 100, 100, -1, 100, 100, 100, 100, 100, 85, 100, 100, 100, -1, 100, -1, 90, -1, 100, 100, 85, 100, 100, 100, 100, -1, -1, -1, 100, -1, 100, -1, -1, -1, -1, 100, -1, -1, 100, 100, -1, 100, 100, 100, -1, -1, -1, -1, -1, 100, 100, 100, -1, -1, 100, 100, 100, 100, 90, -1, 90, 100, -1, 100, 100, 95, 90, 90, 90, 100, 100, -1, 100, 95, 90, -1, 95, 100, 85, 55, 100, -1, 100, 100, 999, 100, 90, 85, -1, 85, 100, 999, 100, -1, -1, -1, 100, 90, -1, 85, 95, 100, 100, 100, 999, -1, -1, 100, -1, 90, 999, 100, 100, 90, -1, -1, -1, 100, 90, 100, -1, 100, 100, 100, 100, -1, -1, 100, 100, 100, 100, 100, 100, 100, 90, 999, -1, 100, -1, 100, -1, -1, -1, -1, -1, 100, 100, 100, 100, -1, -1, -1, -1, 100, 100, 999, -1, 100, 100, 100, 90, 100, 95, 100, 100, 100, 75, 100, 100, 100, 70, 100, 100, 100, 100, 90, -1, 100, 100, 100, 100, 95, 95, 95, 100, 85, 100, 90, 85, 100, 85, -1, -1, 90, 100, 100, 90, 85, 90, 100, 80, 100, 999, 80, 100, -1, 100, 100, 100, 100, 90, 100, 100, 100, -1, -1, 80, 90, 90, 95, -1, 100, 75, 50, 85, 100, 100, -1, -1, -1, -1, -1, 100, 100, -1, -1, -1, -1, 100, 100, 100, 100, -1, 100, 100, 100, 100, 100, -1, 100, 100, 100, 100, 100, -1, 100, 100, 100, -1, 100, -1, -1, 100, -1, -1, 100, 100, -1, 90, 100, 100, 100, -1, 100, 100, -1, 50, 100, 100, 100, 100, 100, 100, 90, 90, -1, 95, 100, 95, 90, 100, 100, 100, 95, 100, 90, 100, -1, 95, 100, 85, 70, 100, 85, 100, 100, 100, 100, 95, 85, 85, 100, 90, 90, 95, 90, 95, 100, 100, 95, -1, 90, -1, -1, 100, 100, 100, 100, -1, 100, 100, 100, 100, 999, 100, -1, 100, -1, -1, -1, -1, -1, 90, 100, 100, 100, -1, -1, -1, -1, 95, 95, 999, 100, 100, -1, -1, 100, 100, 100, -1, -1, -1, -1, 100, -1, -1, 100, 100, 100, 100, 100, 100, 100, 100, 100, 90, 85, 85, 100, 999, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 100, -1, 100, 100, 100, 90, -1, 95, 100, 100, 100, -1, 100, -1, -1, 100, 100, 100, -1, 100, 100, 100, 100, -1, -1, -1, 100, 100, 100, -1, 100, 100, 100, 100, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 100, 90, 100, 100, 100, 100, 100, 100, 100, 100, 100, -1, 100, 90, 100, -1
};

// MOVE PP
static const char MOVE_PP[] = {
-1, 35, 25, 10, 15, 20, 20, 15, 15, 15, 35, 30, 5, 10, 20, 30, 35, 35, 20, 15, 20, 20, 25, 20, 30, 5, 10, 15, 15, 15, 25, 20, 5, 35, 15, 20, 20, 10, 15, 30, 35, 20, 20, 30, 25, 40, 20, 15, 20, 20, 20, 30, 25, 15, 30, 25, 5, 15, 10, 5, 20, 20, 20, 5, 35, 20, 20, 20, 20, 20, 15, 25, 15, 10, 40, 25, 10, 35, 30, 15, 10, 40, 10, 15, 30, 15, 20, 10, 15, 10, 5, 10, 10, 25, 10, 20, 40, 30, 30, 20, 20, 15, 10, 40, 15, 10, 30, 10, 20, 10, 40, 40, 20, 30, 30, 20, 30, 10, 10, 20, 5, 10, 30, 20, 20, 20, 5, 15, 10, 20, 10, 15, 35, 20, 15, 10, 10, 30, 15, 40, 20, 10, 10, 5, 10, 30, 10, 15, 20, 15, 40, 20, 10, 5, 15, 10, 10, 10, 15, 30, 30, 10, 10, 20, 10, -1, 1, 10, 25, 10, 5, 15, 25, 15, 10, 15, 30, 5, 40, 15, 10, 25, 10, 30, 10, 20, 10, 10, 10, 10, 10, 20, 5, 40, 5, 5, 15, 5, 10, 5, 10, 10, 10, 10, 20, 20, 40, 15, 10, 20, 20, 25, 5, 15, 10, 5, 20, 15, 20, 25, 20, 5, 30, 5, 10, 20, 40, 5, 20, 40, 20, 15, 35, 10, 5, 5, 5, 15, 5, 20, 5, 5, 15, 20, 10, 5, 5, 15, 10, 15, 15, 30, 10, 10, 20, 10, 10, 10, 10, 15, 15, 15, 10, 20, 20, 10, 20, 20, 20, 20, 20, 10, 15, 10, 20, 20, 5, 15, 10, 10, 15, 10, 20, 5, 5, 10, 10, 20, 5, 10, 20, 10, 20, 20, 20, 5, 5, 15, 20, 10, 15, 20, 15, 10, 10, 15, 10, 5, 5, 10, 15, 10, 5, 20, 25, 5, 40, 15, 5, 40, 15, 20, 20, 5, 15, 20, 20, 15, 15, 5, 10, 30, 20, 30, 15, 5, 40, 15, 5, 20, 5, 15, 25, 25, 15, 20, 15, 20, 15, 20, 10, 20, 20, 5, 5, 10, 5, 40, 10, 10, 5, 10, 10, 15, 10, 20, 30, 30, 10, 20, 5, 10, 10, 15, 10, 10, 5, 15, 5, 10, 10, 30, 20, 20, 10, 10, 5, 5, 10, 5, 20, 10, 20, 10, 15, 10, 20, 20, 20, 15, 15, 10, 15, 20, 15, 10, 10, 10, 20, 10, 30, 5, 10, 15, 10, 15, 5, 20, 30, 10, 30, 15, 15, 15, 15, 30, 10, 20, 15, 10, 10, 20, 15, 5, 5, 15, 15, 5, 10, 5, 20, 5, 15, 20, 5, 20, 20, 20, 20, 10, 20, 10, 15, 20, 15, 10, 10, 5, 10, 5, 5, 10, 5, 5, 10, 5, 5, 5, 15, 10, 10, 10, 10, 10, 10, 15, 20, 15, 10, 15, 10, 15, 10, 20, 10, 15, 10, 20, 20, 20, 20, 20, 15, 15, 15, 15, 15, 15, 20, 15, 10, 15, 15, 15, 15, 10, 10, 10, 10, 10, 15, 15, 15, 15, 5, 5, 15, 5, 10, 10, 10, 20, 20, 20, 10, 10, 30, 15, 15, 10, 15, 25, 10, 20, 10, 10, 10, 20, 10, 10, 10, 10, 10, 15, 15, 5, 5, 10, 10, 10, 5, 5, 10, 5, 5, 15, 10, 5, 5, 5, 10, 10, 10, 10, 20, 25, 10, 20, 30, 25, 20, 20, 15, 20, 15, 20, 20, 10, 10, 10, 10, 10, 20, 10, 30, 15, 10, 10, 10, 20, 20, 5, 5, 5, 20, 10, 10, 20, 15, 20, 20, 10, 20, 30, 10, 10, 40, 40, 30, 20, 40, 20, 10, 10, 10, 10, 10, 5, 10, 10, 5, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 40, 15, 20, 30, 20, 15, 15, 20, 10, 15, 15, 10, 5, 10, 10, 20, 15, 10, 15, 15, 15, 5, 15, 20, 20, 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 10, 10, 10, 20, 10, 10, 10, 5, 5, 20, 10, 10, 10, 1
};

// CATCH RATE PER POKEMON
static const unsigned char CATCH_RATE[] = { 45,45,45,45,45,45,45,45,45,255,120,45,255,120,45,255,120,45,255,127,255,90,255,90,190,75,255,90,235,120,45,235,120,45,150,25,190,75,170,50,255,90,255,120,45,190,75,190,75,255,50,255,90,190,75,190,75,190,75,255,120,45,200,100,50,180,90,45,255,120,45,190,60,255,120,45,190,60,190,75,190,60,45,190,45,190,75,190,75,190,60,190,90,45,45,190,75,225,60,190,60,90,45,190,75,45,45,45,190,60,120,60,30,45,45,225,75,225,60,225,60,45,45,45,45,45,45,45,255,45,45,35,45,45,45,45,45,45,45,45,45,45,25,3,3,3,45,45,45,3,45,45,45,45,45,45,45,45,45,45,255,90,255,90,255,90,255,90,90,190,75,190,150,170,190,75,190,75,235,120,45,45,190,75,65,45,255,120,45,45,235,120,75,255,90,45,45,30,70,45,225,45,60,190,75,190,60,25,190,75,45,25,190,45,60,120,60,190,75,225,75,60,190,75,45,25,25,120,45,45,120,60,45,45,45,75,45,45,45,45,45,30,3,3,3,45,45,45,3,3,45,45,45,45,45,45,45,45,45,45,255,127,255,90,255,120,45,120,45,255,120,45,255,120,45,200,45,190,45,235,120,45,200,75,255,90,255,120,45,255,120,45,190,120,45,180,200,150,255,255,60,45,45,180,90,45,180,90,120,45,200,200,150,150,150,225,75,225,60,125,60,255,150,90,255,60,255,255,120,45,190,60,255,45,90,90,45,45,190,75,205,155,255,90,45,45,45,45,255,60,45,200,225,45,190,90,200,45,30,125,190,75,255,120,45,255,60,60,25,225,45,45,45,3,3,3,3,3,3,3,3,3,3,45,3,3,45,45,45,45,45,45,45,45,45,255,120,45,255,127,255,45,235,120,45,255,75,45,45,45,45,120,45,45,120,45,200,190,75,190,75,190,75,45,125,60,190,60,45,30,190,75,120,225,60,255,90,255,145,130,30,100,45,45,45,50,75,45,140,60,120,45,140,75,200,190,75,25,120,60,45,30,30,30,30,30,30,30,30,45,45,30,50,30,45,60,45,75,45,3,3,3,3,3,3,3,3,3,30,3,3,45,3,3,45,45,45,45,45,45,45,45,45,255,255,255,120,45,255,90,190,75,190,75,190,75,190,75,255,120,45,190,75,255,120,45,190,45,120,60,255,180,90,45,255,120,45,45,45,255,120,45,255,120,45,190,75,190,75,25,180,90,45,120,60,255,190,75,180,90,45,190,90,45,45,45,45,190,60,75,45,255,60,200,100,50,200,100,50,190,45,255,120,45,190,75,200,200,75,190,75,190,60,75,190,75,255,90,130,60,30,190,60,30,255,90,190,90,45,75,60,45,120,60,25,200,75,75,180,45,45,190,90,120,45,45,190,60,190,60,90,90,45,45,45,45,15,3,3,3,3,3,3,3,3,3,3,3,3,45,45,45,45,45,45,45,45,45,255,127,255,120,45,255,120,45,220,65,225,120,45,200,45,220,65,160,190,75,180,90,45,200,140,200,140,190,80,120,45,225,55,225,55,190,75,45,45,45,45,45,100,180,60,45,45,45,75,120,60,120,60,190,55,190,45,45,45,3,3,3,3,45,45,45,45,45,45,45,45,45,255,120,45,255,127,255,120,45,225,60,45,190,75,190,90,60,190,75,190,60,200,100,190,75,190,75,120,45,140,70,235,120,45,60,45,45,90,45,140,60,60,3,3,30,45,70,180,45,80,70,25,45,45,45,3,3,3,3,45,45,45,45,45,25,255,30,25,255,15,3,3,3
};
