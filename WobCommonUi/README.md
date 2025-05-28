# War of Being Common UI Expansion


## Overview
This plugin expands on Epic Games' CommonUI Framework, allows for easy switching between game states without removing widgets/stacks when they should stay visible beneath the active widget. For example, The players HUD should stay visible but out of focus when the pause menu is active, and should pass focus back appropriately when the pause menu is removed.


### Registering layers
Layers are registered with the subsystem, assigning a layer priority and custom GameplayTag label for human readability.  Higher priority layers always receive focus if they have any active widgets in their associated stack. When a widget is deactivated, the subsystem traverses the priority list until it reaches the highest priority stack with an active widget, handing over focus to that widget as appropriate. 
![image](https://github.com/user-attachments/assets/10c06d0d-7694-4e6e-894e-83793978093a)


### Pushing to a layer
Adding a widget to the UI is done simply by pushing to a registered layer. Creating and managing the widget is handled by the subsystem. No other setup is required.
![image](https://github.com/user-attachments/assets/ad5866ff-cfe3-40da-ad9b-7e21b1cdf533)
