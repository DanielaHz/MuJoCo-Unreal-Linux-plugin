# MuJoCo Unreal Engine 5 Plugin

A UE5 plugin that brings MuJoCo physics simulation into Unreal Engine 5.6.1 on Linux (Fedora 43), built on top of oneclicklabs/MuJoCo-Unreal-Engine-Plugin (originally Windows-only, UE5 early versions) and ported to Linux with MuJoCo 3.3.0.

## Current state

Load and simulate MuJoCo XML scenes directly inside UE5, with MuJoCo driving the physics and Unreal handling real-time photorealistic rendering.

## Goal
Replace the XML-first authoring workflow with a native UE experience — users compose scenes using Static Meshes and UE components, and the plugin generates the MJCF internally. Unreal owns the rendering and authoring. MuJoCo owns the physics. The XML becomes an implementation detail the user never touches.

## Target use cases
Robotics simulation, reinforcement learning environments, digital twins, and any application that requires both physically accurate simulation and photorealistic real-time rendering.

## MuJoCo Architecture 
```
MuJoCo
├── XML (Scene)
│   └── MJCF compiler → mjModel (static)
│
└── API (Physics)
├── mjModel  (input - what was loaded)
├── mjData   (output - live state per step)
└── mj_step() (the integrator)
```
## Demo (XML File rendering)

![Simulation Demo](Assets/MuJoCo-Unreal-Demo.gif)

## Recommended IDE
Rider is so far the best IDE to work with UE projects!! I higly recommend it.

## Installation

1. Clone this repository to your Unreal Engine project's `Plugins` folder
2. Rebuild your project
3. Enable the MuJoCo plugin in your project settings

## Usage

### Basic Setup to load XML scenes

1. Place a `MuJoCoSimulation` actor in your level
2. Set the XML file path in the actor's properties
3. Start play mode to see the simulation

### Controls to run Sim

- **Z key**: Hold to run simulation, release to pause
- **R key**: Reset simulation to initial state
- **C key**: Test MuJoCo actuators control (sets Actuator 0 to a small value, useful for testing models like car.xml)

