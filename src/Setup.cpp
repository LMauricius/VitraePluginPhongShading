#include "VitraePluginPhongShading/Setup.hpp"

#include "VitraePluginPhongShading/converters/aiPBSConvert.hpp"
#include "VitraePluginPhongShading/converters/aiPhongConvert.hpp"
#include "VitraePluginPhongShading/tasks/shadingPBS.hpp"
#include "VitraePluginPhongShading/tasks/shadingPhong.hpp"

namespace VitraePluginPhongShading
{

void setup(Vitrae::ComponentRoot &root)
{
    setupAssimpPhongConvert(root);
    setupAssimpPBSConvert(root);
    setupShadingPhong(root);
    setupShadingPBS(root);
}

} // namespace VitraePluginPhongShading