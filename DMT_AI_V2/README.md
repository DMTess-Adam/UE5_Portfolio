# DMTesseracT core AI Module (V2) 

## Overview 
Version 2 of the encompassing AI module, built for War of Being and designed with the intention of being migratable for future projects. AI V2 covers the general needs of AI systems in conventional gaming. Capitalising on the engine's Perception component, the module uses perception stimulus events to drive NPC states and build and maintain lists of targets for each NPC with support for separating enemies and friendlies. A conventional AI Scripting system is exposed to blueprint to allow designers to easily create a variety of different behaviors based off the core perception events. 


## AI Behavior component
The Behavior component tracks perception component events,passing them down to custom behavior scripts for processing the data from the triggered stimulus. This component acts as a bridge between the AI scripting system and any Actor with a perception component, allowing the plugin to stay decoupled from project specific code and requires very little customisation. Behavior components are responsible for spawning and managing the reference to the AI Script assigned to the actor.
![image](https://github.com/user-attachments/assets/f9b595ca-c6fd-4f2a-8569-5e3821177aee)

## Custom AI Scripts
AI Scripts inherit from a base script that manages a specific 3 state rule: Patrol/Idle, Alert and Attack. By default, Idle states are active when all stimuli are expired, Alert states are triggered when non-sight stimulus are relevant and Attack states are triggered when Sight stimulus are relevant.  A table of all perceived actors are maintained by the AI script, filtered into separate Enemy, Neutral and Friendly maps for custom behavior to advance on. 
![image](https://github.com/user-attachments/assets/a7e979b4-e893-40d1-a82b-443b08f79ba6)


## Built-in Patrol node system
Pathing nodes can be chained together and NPC's can assign them as their patrol routes. Visual helpers in Editor view help designers understand the patrol route, with automatic Spline adjustments, conforming the visuals to the terrain for clean visualisation.

![image](https://github.com/user-attachments/assets/104e927b-c73b-41b6-ad4f-094476c002fc)

#### Patrol node On Actor Arrival scripts 
Individual nodes support triggering custom scripts when a patrol actor reaches the node. Custom scripts follow a similar structure to Behavior Tree Tasks, with a single overrrideable Execute event exposed for custom blueprint logic.
![image](https://github.com/user-attachments/assets/f4efb1d4-2e0e-4fb9-9bb1-ab91c1ddde1c)


