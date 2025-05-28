# Soundtrack system

## Overview

This Soundtrack plugin was built to control all aspects of the music in War of Being. Supporting multiple situations such as dynamic combat escalation, adding or removing audio layers in real time based on the players state, and real time analysis of audio files (metasound) with event triggers for individual audio cues such as drum Bass kick and snares, vocal changes etc. for driving gameplay events directly from audio, in real time.


## OST template

All OST files follow a set Stem setup, where the final track is divided into a logically compressed list of individual audio stems (drums, guitar, bass, vocal etc.) and playback is synchronised inside the Metasound template. Each layer has its audio gain exposed to blueprint and can be dynamically controlled from anywhere that has access to the soundtrack subsystem.

![image](https://github.com/user-attachments/assets/3ac33335-f385-473c-b792-da0cac7d22ec)

Inhering from the template, setup of new music tracks is as simple as overriding the stem files
![image](https://github.com/user-attachments/assets/b2188dd8-8120-4092-ada5-e34e1f481156)

Playing tracks is as simple as calling the SetSoundtrackByConfig function in the Soundtrack Subsystem, passing the appropriate file and volume data

![image](https://github.com/user-attachments/assets/32e9ed18-03c7-41f9-9fb7-d3f219a25944)


## Audio driven gameplay
OST template analyses audio and triggers events based on filter thresholds. Any actor can bind to these events via the subsystem, allowing for endless creativity in synchronising gameplay to audio events in real time. 

![image](https://github.com/user-attachments/assets/9cf05374-e30b-4e33-9271-b5c4d5fd6b10)

### Example implementation of audio driven gameplay
[//TODO: Upload Video Example](https://youtu.be/gR4k6nj9cVM)

## State driven dynamic audio
Soundtrack Plugin can be set to "Combat Mode" that listens for any events from NPC's state changes to switch between preset volume and track data based on the highest tracked NPC state (Patrol, Alert, Attack). Track and volume data can be set from blueprint level and can support any combination of templates and volumes as per requirement.

![image](https://github.com/user-attachments/assets/e5089381-aba4-4d05-9a92-d53d01d3480e)

NPC's can report their state from their internal AI logic using the subsystems Notify nodes
![image](https://github.com/user-attachments/assets/5e914c97-decf-479e-b46f-f7b513a67817)


