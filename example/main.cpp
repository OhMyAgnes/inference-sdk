#include "inference_module.hpp"

int main(int argc, char* argv[])
{
    // init
    inference::InferenceModule sdk;
    auto res = sdk.InitModel("path to model file", false);  // defult using cpu
    if (res)
    {
        std::cout << "init ok" << std::endl;
    }
    else
    {
        std::cout << "init failed" << std::endl;
    }

    // inference
    inference::InferenceRequest req{cv::Mat(), 0.0};
    inference::InferenceResponse rsp{cv::Mat(), 0.0};
    res = sdk.RunInfer(req, rsp);

    if (res)
    {
        std::cout << "infer ok" << std::endl;
    }
    else
    {
        std::cout << "infer failed" << std::endl;
    }

    return 0;
}