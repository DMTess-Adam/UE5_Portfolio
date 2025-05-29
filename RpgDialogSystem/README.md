
#RPG Dialog System

## Overview 
A robust RPG dialog system that leverages Level Sequences to build dialog conversations with NPCs. With support for ambiguous Inventory and quest systems as well as internal state tracking for an NPC, opening up unlimited possibilities for dialog options per NPC. This system is entirely self contained, leveraging interfaces for implementing into broader systems.

[Demo](https://youtu.be/_dfELBeyVXk)



### Advanced Dialog start selection
Mark certain dialog sequences as "intro" dialogs that are played on initial interaction, with advanced conditions and priorities for filtering to the appropriate sequence.  For example, First time interactions should play the first time sequence, subsequent interactions should start with the "returning" dialog.
![image](https://github.com/user-attachments/assets/d5e4492b-fb16-4be1-97a8-cfecceb8198d)


### Custom Qualifying Conditions
Create unique conditions for a dialog per-NPC.  Adding refined control over dialog options based on the NPC's state.  E.g, insulting an NPC can result in making them angry, disabling certain dialog options going forward.
![image](https://github.com/user-attachments/assets/42500626-a66a-4fdf-9d3a-d930047c4019)


### Conditional player response options
Limit dialog responses based on internal conditions such as items in inventory, acquired quests or internal NPC states.
![image](https://github.com/user-attachments/assets/9caab925-1f4f-4a1a-bfb6-1c277ed2e537)



### Trigger state events
Trigger inventory and quest events when specific dialog choices are made or sequences are played. Or trigger a completely custom script when the sequence ends for more advanced events.
![image](https://github.com/user-attachments/assets/9d3f567b-42a1-4fef-8aa8-8fe9f6e96cb2)

![image](https://github.com/user-attachments/assets/4cf1ec58-59aa-4d50-ae8e-8e7154d51a67)


### Clean and easy implementation
Handles spawning level sequences only when needed, removing unnecessary clutter from the world. 

### Reusable and scalable Dialog Chains
Entire sequence chains are defined in Data Assets, allowing multiple NPC's to reference the same chain where necessary. This is useful for representations of the same character in different levels, or generic dialog with lesser NPC's. Control entire chains from a single data point for easy management and scaling.
![image](https://github.com/user-attachments/assets/9d76d2c3-9ea6-4475-9a33-26146b86bde8)

