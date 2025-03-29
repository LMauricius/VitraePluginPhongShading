#pragma once

#include "Vitrae/Data/LevelOfDetail.hpp"
#include "Vitrae/Data/Typedefs.hpp"
#include "Vitrae/Params/ParamSpec.hpp"
#include "Vitrae/Params/Standard.hpp"
#include "dynasma/pointer.hpp"

namespace VitraePluginPhongShading
{
    /**
     * Namespace containing commonly used ParamSpecs, identifiable by their string names
     */
    namespace StandardParam
    {
        using namespace Vitrae::StandardParam;

        // clang-format off

        /// @subsection Textures
        inline const Vitrae::ParamSpec color_diffuse   = {"color_diffuse",   Vitrae::TYPE_INFO<glm::vec4>};
        inline const Vitrae::ParamSpec color_normal    = {"color_normal",    Vitrae::TYPE_INFO<glm::vec4>};
        inline const Vitrae::ParamSpec color_specular  = {"color_specular",  Vitrae::TYPE_INFO<glm::vec4>};
        inline const Vitrae::ParamSpec color_shininess = {"color_shininess", Vitrae::TYPE_INFO<glm::vec4>};
        inline const Vitrae::ParamSpec color_emissive  = {"color_emissive",  Vitrae::TYPE_INFO<glm::vec4>};

        inline const Vitrae::ParamSpec color_base       = {"color_base",       Vitrae::TYPE_INFO<glm::vec4>};
        inline const Vitrae::ParamSpec color_metalness  = {"color_metalness",  Vitrae::TYPE_INFO<glm::vec4>};
        inline const Vitrae::ParamSpec color_smoothness = {"color_smoothness", Vitrae::TYPE_INFO<glm::vec4>};

        // clang-format on

    } // namespace StandardParam
} // namespace Vitrae