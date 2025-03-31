﻿#ifndef DUPLICATION_API_CAPTURE_H
#define DUPLICATION_API_CAPTURE_H

#include <d3d11.h>
#include <dxgi1_2.h>
#include <opencv2/opencv.hpp>
#include <opencv2/cudawarping.hpp>
#include <cuda.h>
#include <cuda_runtime.h>
#include <cuda_d3d11_interop.h>
#include <memory>

#include "capture.h"

class DDAManager;

class DuplicationAPIScreenCapture : public IScreenCapture
{
public:
    DuplicationAPIScreenCapture(int desiredWidth, int desiredHeight);
    ~DuplicationAPIScreenCapture();

    cv::cuda::GpuMat GetNextFrameGpu() override;

    cv::Mat GetNextFrameCpu() override;

private:
    std::unique_ptr<DDAManager> m_ddaManager;

    ID3D11Device* d3dDevice = nullptr;
    ID3D11DeviceContext* d3dContext = nullptr;
    IDXGIOutputDuplication* deskDupl = nullptr;
    IDXGIOutput1* output1 = nullptr;

    ID3D11Texture2D* sharedTexture = nullptr;
    cudaGraphicsResource* cudaResource = nullptr;
    cudaStream_t         cudaStream = nullptr;

    ID3D11Texture2D* stagingTextureCPU = nullptr;

    int screenWidth = 0;
    int screenHeight = 0;
    int regionWidth = 0;
    int regionHeight = 0;

    bool createSharedTextureGPU();
    bool createStagingTextureCPU();
};

#endif // DUPLICATION_API_CAPTURE_H
