# MuJoCo Unreal Engine Plugin

This plugin integrates MuJoCo physics engine with Unreal Engine, allowing you to load MuJoCo XML files directly into Unreal Engine and run advanced physics simulations.

## Features

- Load MuJoCo XML files into Unreal Engine
- Run MuJoCo simulations and display results in real-time
- Support for procedural mesh generation for non-primitive MuJoCo shapes
- Import object colors from MuJoCo models
- Multiple simultaneous simulation instances support

## Demo

![Simulation Demo](https://cdn.loom.com/sessions/thumbnails/ec26c892b5014a03afb7d016b2d4b4d5-88ba2fce00140e4d-full-play.gif)

![Simulation Demo 2](https://cdn.loom.com/sessions/thumbnails/c750fc543f3548208ad88d14b0447251-beb5032d0c1cdf27-full-play.gif)

![Simulation Demo 3](https://cdn.loom.com/sessions/thumbnails/81d84c9a8565465199aae22d4d5e627c-47d9ea28f3266022-full-play.gif)
## Installation

1. Clone this repository to your Unreal Engine project's `Plugins` folder
2. Rebuild your project
3. Enable the MuJoCo plugin in your project settings

## Usage

### Basic Setup

1. Place a `MuJoCoSimulation` actor in your level
2. Set the XML file path in the actor's properties
3. Start play mode to see the simulation

### Controls

- **Z key**: Hold to run simulation, release to pause
- **R key**: Reset simulation to initial state
- **C key**: Test MuJoCo actuators control (sets Actuator 0 to a small value, useful for testing models like car.xml)

## Current Limitations

- Texture support is not yet implemented (only colors are imported)
- It is still rough and not optimized for performance

