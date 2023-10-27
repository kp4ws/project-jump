# **PROJECT JUMP**

## B team : **Gravity Grippers**


### Contact Info: hengstler2005@gmail.com


---

## Product Overview.



1.  **Purpose Of The Product:**



    The main purpose of the product is to create an easy but fun, working single player game that can be enjoyed by a wide range of people.



2.  **Target Audience:**


 


    The target audience is a wide range of people, since the game has core features that can be enjoyed by younger audiences while also including more challenging additional features for people who are older.


 


3.  **Theme:**


 


    The game is a 2d vertical procedurally generated platformer with 3d artstyle for most elements, giving it a unique look. It also includes various mechanics which enhance gameplay, such as health and abilities, with a fully functional shop. The core gameplay is unlocking new abilities and items by buying them through the shop.


 


4.  **Goals:**


 


- Improve procedural generation by making a level based system which deletes levels when loading a new one


- Set up a shop for the user to buy from with a UI and items/power ups


- Implement two to 4 abilties for the player to use


- Add custom blocks and further change how the map generates


- Add basic traps.


- Set up a function HUD with key elements.


 


## Flow of the game.


 


The game starts with the player on the ground, the lowest level, and the player jumps from platform to platform to go as high as possible. The game has a fall damage mechanic which removes the players health when they fall for longer than a certain amount of time, based on how long they fall, which acts as the main death mechanic. When the player dies, the game is over and the player gets sent back to the bottom. Every run the player earns coins based on height traversed, which can be used in the shop to buy abilities and extra health, before starting the next run.


 


## Game Features.


 


1.  **HUD.**


 


    The player will have a Heads Up Display on their screen, which shows their score/ or currency and their health. It will also include their abilities. The HUD will also change when interacting with the shop, and when raytracing an interactable object. The HUD is layerable and other layers will be added when needed.


 


## Game Levels.


 


1.  **Main Tower.**


 
    This is the main tower of the game, which the player is trying to climb up. The platforms within this tower will be implemented using an algorithm so that they do not follow a pattern, but are randomly generated in place. The platforms should be generated at heights allowing the player to make a short jump and full jump and still land on two levels of platforms. So the first platform level is at half height of jump, and the second level should be at just under full height of the jump. The random platform generator should ensure that there are some challenges in jumps while also making sure that all jumps are possible. The player jumps up from one platform to another, as they are jumping higher, the player is gaining score and currency to spend in the shop to buy game changing abilities to boost their high score. The image that we have for the level generation is to implement an onInteract feature that will detect when the player is overlapping with a certain object resembling a door and then our level spawning function will be called continuously, building another level every time a new barrier is reached. This can be done with a three level system that keeps the player in the middle the entire time, such that when the player reaches the middle of the third tower, the first tower is deleted and a new one is spawned on top, so that the climbing appears seamless. Constraints that may need to be factored into the level generation is the sky limit and overall textures causing heavy usage of resources.
If the sky limit is being reached the level generation could include a feature that moves everything including the player down the Z axis when generating a new level in order to create the illusion of going up a level each time but it can keep the player up near the sky limit without running into sky limit issues.


![Main-Tower](https://i.imgur.com/wVVFvJa.png)


 
 


2.  **Shop.**


    This is present at the start of the tower, and the player can go here to buy abilities and items. Players enter it by going through a door on the base level of the tower, which loads the Shop scene/level. This scene/level will look somewhat like a tavern or bar, with the DaveWessel intractable pawn behind a counter. Power Ups and Items will be purchased through the DaveWessel intractable pawn using a shop UI and currency.


    **DaveWessel** - Dave is an interactable pawn. Through his OnInteract function, a UI for the shop will pop up and you will hear dave wessel voice lines such as “Heaps of fun”. This function is called when the player is ray tracing Dave and clicks on Interact. When one of the objects on the UI is clicked and the player has enough currency, the player receives the item and loses that amount of currency.
 


## Key Items.


 


1.  **Main Player.**
 
 This is the player of the game. It is a 2d sprite with basic animations and a charge jump mechanic. The movement is all done using blueprints, and the larger functions such as interact handling are handled in C++. The player has a jump strength for the max his jump can charge to, health, maxHealth, and currency for purchasing upgrades at the shop. The player will also have an inventory where it will store consumable items, and powerups/abilities


**Jump Mechanic:**

The Jump Mechanic is implemented in blueprints and utilises the jumpStrength variable. It checks that the player is able to jump by checking if they are connected to solid ground, then it checks if it is in a place where it can jump. It launches the player based on how long the button SPACE is held down to a max of jumpStrength, another variable called airControl changes how much the player can move in the air.


**Interact Mechanic:**

The interact mechanic has two main functions being CheckInteract(), and Interact.
Checkinteract is called every tick, and allows the player to call Interact if it detects a valid object on its raytrace.


**CheckInteract** - This is called every tick, it creates a raytrace that hits an object directly behind the player. If the object hit has the Interactable tag, then it allows the player to call the interact function by using the interact button. It also adds the interact UI that shows the player that they can interact right now.


**Interact** - When the player hits the interact button and there is a valid object ratraced, then it accesses the interactables function OnInteract and calls it. 


**Powerups/Abilities and Inventory:** The inventory will either be a map, or an array of items. We will have consumables such as potions to increase health, and power ups such as the jetpack. These will all be purchased through the DaveWessel shop using currency.


**Variables:**
Health - Will be changed from falling, health potions, and possibly enemies. Will never go under one or over maxHealth
maxHealth - Starts at 100, changes based on upgrades
Currency - Will be gained from increasing Y value of player, and possibly collecting items from chests and destroying enemies. The currency will be used at the shop where you can purchase upgrades and items. This shop will be accessed through the interactable DaveWessel object, costs will be determined later.
Powerups/Inventory:
jumpStrength - Chosen by developer, used in Jump Mechanic
airControl - Chosen by developer, used in Jump Mechanic

2.  **JetPack.**


This is one of the abilities purchasable in the game. It runs on limited fuel which can be refilled with pickups present in the map, and allows the player to fly up, or negate fall damage if they miss a jump. 


The jetpack only works once you buy it from the shop, and can be activated while the player is in mid-air by holding down space, or tapping it for short boosts.


**Variables:**
Hovering?:Boolean value to store status of player, if the player is in air or not.
Fuel - Chosen by developer, decremented each time jetpack is used.
Thrust - Chosen by developer, used to boost player upwards
 
3.  **Basic Spike Trap.**


This is just a spike trap on some platforms which damage the player when they touch it. Using a function that detects collision, the game will be able to tell when the player sprite touches the spike sprite. This will subtract a set amount of damage from the players overall health while they still have health remaining.


## Priority Levels.

1.  **Core**.


The core features are the procedural generation, the HUD, and a crude shop with one ability, and an option to buy extra health/health potions, the player health and death mechanic and currency to spend in the shop. The purpose of our game is so that the user is rewarded when they reach higher and higher up the tower, accumulating currency that they can spend after they die when they respawn at the base level of the tower and head to the shop. The game will store your current score value and convert it to currency upon reset.

2.  **Secondary.**

The secondary features include a well designed shop, with more abilities, better procedural generation (obstacles in the way or to stand on), more refined textures for the tower and background, music for the game, particle effects, basic traps and different platform types.

3.  **Nice to have features.**

More abilities, multiple levels, more platform types, bosses, more traps would be nice to have in the game, as they would improve gameplay a lot.


Potential abilities: Dash, Grappling hook, portal
Levels: “boss level”, low gravity level, dark room level
Platform Types: slippery, sticky, bouncy, fake
Bosses: Either an actual entity that chases you and hurts you or just a level with increased traps and projectiles.
Traps: Fake platforms, spikes, ray tracing projectile, Barriers that you bounce off of.
Shop: Dave Wessel gets angry at you if you try to buy something without enough money

## Non-Functional Requirements.

1.  **Performance Requirements.**
Firstly, The program must be able to run smoothly on all modern PC operating systems

    Secondly, if time permits the program must be able to run smoothly on all 
In both cases, the system needs to be able run the game executable file built from Unreal Engine 5.

2.  **Software Quality Requirements**.
The quality requirements for our software are listed below:
Ensure production ready code has been thoroughly tested and running without bugs

    Testing will be performed manually through play tests of the game after implementing a function

    Software will adhere to standard coding and programming procedures to help reduce    spaghetti code, memory leaks, and any other errors or exceptions.  
     Programmers of the software are expected to complete their task to the best of their ability to maintain top notch quality standards.
 
3.  **Safety and Security Requirements.**
Our project is a small game without no online play and doesn’t need any security requirements. There are not many safety requirements either, other than ensuring the game is within the specs of modern operating systems so that it can be safely run on the user’s machine.
