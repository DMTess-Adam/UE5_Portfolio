# War of Being GAS System


## Overview
Encompassing implementation of Epics Gameplay Ability System Framework specifically targeting the War of Being gameplay mechanics. Covering all abilities for both player and NPC, attributes and additional systems that fit within the framework, including quest systems and player inventory.


## Complete Inventory system
Inventory system with support for maximum slots, dynamically stackable items and two separate inventory types for distinct types of currency; an integer based currency, and a float based currency. 
 - Integer currency are a simple currency that stacks up to INT_MAX size.
 - values float based currency follows a percentile approach that grants a single unit of currency on reaching 1.0. Allowing for fractional collection of currencies to generate a single viable currency token.
Inventory can support any number of each currency types, allowing multiple currencies to be tracked and collected simultaneously.
Inventory items follow a simple ID based convention, allowing for Data Tables or external databases to store and manage item data.
