#include "inference_module.hpp"

namespace inference
{
class InferenceModule::Impl
{
   public:
    Impl() {}

    bool InitModel(const std::string& model_path, const bool use_gpu)
    {
        // 初始化模型的实现
        // ...
        return true;  // 模型初始化成功
    }

    bool RunInfer(const InferenceRequest& req, InferenceResponse& rsp)
    {
        // 运行推理的实现
        // ...
        return true;  // 推理成功
    }
};

InferenceModule::InferenceModule() : _impl(std::make_unique<Impl>()) {}
InferenceModule::~InferenceModule() = default;

bool InferenceModule::InitModel(const std::string& model_path, const bool use_gpu)
{
    return _impl->InitModel(model_path, use_gpu);
}

bool InferenceModule::RunInfer(const InferenceRequest& req, InferenceResponse& rsp)
{
    return _impl->RunInfer(req, rsp);
}
}  // namespace inference