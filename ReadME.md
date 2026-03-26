# MuJoCo Unreal Engine Plugin

This plugin allows you to load MuJoCo XML files directly into Unreal Engine 5.6.1 on Linux.
It currently uses MuJoCo 3.3.0.

## Goal

Fully integrate MuJoCo into Unreal Engine by separating responsibilities:
use MuJoCo for physically accurate simulation, and Unreal Engine for real‑time, photorealistic rendering.

## Demo

![Simulation Demo](Assets/MuJoCo-Unreal-Demo.gif)

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

