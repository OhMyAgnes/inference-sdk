#ifndef _INFERENCE_MODULE_H_
#define _INFERENCE_MODULE_H_

#ifdef _MSC_VER
#ifdef DLL_EXPORT
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif
#else
#define DLL_API
#endif

#include <memory>
#include <string>

#include "opencv2/opencv.hpp"

namespace inference
{

struct InferenceRequest
{
    cv::Mat image;
    float threshold;
};

struct InferenceResponse
{
    cv::Mat draw;
    float score;
};

class DLL_API InferenceModule
{
   public:
    InferenceModule();
    ~InferenceModule();
    bool InitModel(const std::string& model_path, const bool use_gpu);
    bool RunInfer(const InferenceRequest& req, InferenceResponse& rsp);

   private:
    class Impl;
    std::unique_ptr<Impl> _impl;
};
}  // namespace inference
#endif