<div align="center">
 <h1>2-Condition-Aimbot</h1>
 <img src="https://img.shields.io/badge/Live%20Status-UNDETECTED-green" />

A hardware aimbot for games using kmbox net

[**English**](.README.md)  |  [**Tiếng Việt**](./2CA/include/README.vi.md)   |   [**中国人**](.README.md)    |    [**한국인**](.README.md)   |    [**日本語**](.README.md)  

</div>

This fork of SunOne Aimbot focuses on implementing the Kmbox Net mouse method for improved performance and precision.

> **⚠️ WARNING:** TensorRT version 10 does not support the Pascal architecture (10 series graphics cards). Use only with GPUs of at least the 20 series.

## Quick Start Guide

### Pre-built Binary
1. **Download CUDA**
   - Install [CUDA 12.8](https://developer.nvidia.com/cuda-12-8-0-download-archive)

2. **Download Latest Release**
   - Get the latest release from [here](https://mega.nz/folder/BSsFXKiC#tnvF41b7kN-Y8IqWlKTfLQ) (Updated 06.04.2025)

3. **Setup**
   - Extract the Aimbot contents
   - Edit your Kmbox net ip, port, uuid in the config.ini
   - Run `ai.exe` and wait for the standard `.onnx` model export (approximately 5 minutes)
   - To use a different model, place your `.onnx` file in the `models` folder and select it in the AI tab. (You can train a model yourself for better compatible with your specific needs)
  
4. **Controls**
   - **Right Mouse Button:** Aim at detected target
   - **F2:** Exit program
   - **F3:** Pause aiming
   - **F4:** Reload config
   - **Home:** Open overlay

## Kmbox Net Configuration
The Kmbox Net mouse method provides several advantages:
- Very hard to get detected by Anticheats
- Pure human interface for better compatible
- Hardware level curve control (known as Trace)

## Model Export Guide
To export PyTorch models from Python with dynamic shapes:
```bash
pip install ultralytics -U
yolo export model=your_model.pt format=onnx dynamic=true simplify=true
```
For .onnx to .engine conversion, use the export tab in the overlay.

<h3 align="left">Support:</h3>

USDT - TRX (TRON TRC-20): TChDBfpKwHPX7CLnqvtQGG7jr9jvaB5KWq

BTC - BTC network: 1MnnTJBfdYEpeLgCFYf4NiMLg1UGRvijsz

<p><a href="https://www.buymeacoffee.com/ozymotvz"> <img align="left" src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" height="50" width="210" alt="ozymotvz" /></a><a href="https://ko-fi.com/ozymotv"> <img align="left" src="https://cdn.ko-fi.com/cdn/kofi3.png?v=3" height="50" width="210" alt="ozymotv" /></a></p><br><br>



## References
- [Config Documentation](https://github.com/SunOner/sunone_aimbot_docs/blob/main/config/config_cpp.md)
- [Original Project](https://github.com/SunOner/sunone_aimbot_cpp)
