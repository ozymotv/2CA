# SunOne Aimbot C++ (Kmbox Net Fork)

[![C++](https://img.shields.io/badge/C%2B%2B-17-blue)](https://github.com/ozymotv/2CA)
[![License MIT](https://badgen.net/github/license/SunOner/sunone_aimbot_cpp)](https://github.com/SunOner/sunone_aimbot_cpp/blob/main/LICENSE)

This fork of SunOne Aimbot focuses on implementing the Kmbox Net mouse method for improved performance and precision.

> **⚠️ WARNING:** TensorRT version 10 does not support the Pascal architecture (10 series graphics cards). Use only with GPUs of at least the 20 series.

## Quick Start Guide

### Pre-built Binary
1. **Download CUDA**
   - Install [CUDA 12.8](https://developer.nvidia.com/cuda-12-8-0-download-archive)

2. **Download Latest Release**
   - Get the latest release from [here](link) v3.2 (Updated 31.03.2025)

3. **Setup**
   - Extract the Aimbot contents
   - Edit your Kmbox net ip, port, uuid in the config.ini
   - Run `ai.exe` and wait for the standard `.onnx` model export (approximately 5 minutes)
   - To use a different model, place your `.onnx` file in the `models` folder and select it in the AI tab
  
4. **Controls**
   - **Right Mouse Button:** Aim at detected target
   - **F2:** Exit program
   - **F3:** Pause aiming
   - **F4:** Reload config
   - **Home:** Open overlay

## Kmbox Net Configuration
The Kmbox Net mouse method provides several advantages:
- Improved precision for target tracking
- Lower detection latency
- Enhanced movement smoothing

To enable Kmbox Net:
1. Open the overlay (Home key)
2. Navigate to the Mouse tab
3. Select "Kmbox Net" from the dropdown menu
4. Configure connection settings as needed

## Model Export Guide
To export PyTorch models from Python with dynamic shapes:
```bash
pip install ultralytics -U
yolo export model=your_model.pt format=onnx dynamic=true simplify=true
```
For .onnx to .engine conversion, use the export tab in the overlay.


## References
- [Config Documentation](https://github.com/SunOner/sunone_aimbot_docs/blob/main/config/config_cpp.md)
- [Original Project](https://github.com/SunOner/sunone_aimbot_cpp)
