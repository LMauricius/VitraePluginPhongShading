#pragma once

#include "VitraePluginPhongShading/Standard/Params.hpp"
#include "VitraePluginPhongShading/Standard/Textures.hpp"

#include "Vitrae/Assets/Texture.hpp"
#include "Vitrae/Collections/ComponentRoot.hpp"
#include "Vitrae/Collections/MethodCollection.hpp"
#include "Vitrae/Pipelines/Compositing/AdaptTasks.hpp"
#include "Vitrae/Pipelines/Compositing/ClearRender.hpp"
#include "Vitrae/Pipelines/Compositing/SceneRender.hpp"

#include "dynasma/standalone.hpp"

namespace VitraePluginPhongShading
{
    inline void setupAssimpPhongConvert(Vitrae::ComponentRoot &root)
    {
        root.addAiMaterialParamAliases(
            aiShadingMode_Phong,
            {{"shade", "phong_shade"}});

        root.addAiMaterialTextureInfo({
            StandardTexture::diffuse,
            aiTextureType_DIFFUSE,
            {1.0f, 1.0f, 1.0f, 1.0f},
        });
        root.addAiMaterialTextureInfo({
            StandardTexture::normal,
            aiTextureType_NORMALS,
            {0.0f, 0.0f, 1.0f, 1.0f},
        });
        root.addAiMaterialTextureInfo({
            StandardTexture::specular,
            aiTextureType_SPECULAR,
            {0.0f, 0.0f, 0.0f, 1.0f},
        });
        root.addAiMaterialTextureInfo({
            StandardTexture::emissive,
            aiTextureType_EMISSIVE,
            {0.0f, 0.0f, 0.0f, 0.0f},
        });

        root.addAiMaterialPropertyInfo(
            {StandardParam::color_diffuse.name,
             [](const aiMaterial &extMat) -> std::optional<Vitrae::Variant> {
                 aiColor4D color;
                 if (extMat.Get(AI_MATKEY_COLOR_DIFFUSE, color) == AI_SUCCESS) {
                     return Vitrae::Variant(glm::vec4(color.r, color.g, color.b, color.a));
                 } else {
                     return Vitrae::Variant(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
                 }
             }});
        root.addAiMaterialPropertyInfo(
            {StandardParam::color_specular.name,
             [](const aiMaterial &extMat) -> std::optional<Vitrae::Variant> {
                 aiColor4D color;
                 if (extMat.Get(AI_MATKEY_COLOR_SPECULAR, color) == AI_SUCCESS) {
                     return Vitrae::Variant(glm::vec4(color.r, color.g, color.b, color.a));
                 } else {
                     return Vitrae::Variant(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
                 }
             }});
        root.addAiMaterialPropertyInfo(
            {StandardParam::color_emissive.name,
             [](const aiMaterial &extMat) -> std::optional<Vitrae::Variant> {
                 aiColor4D color;
                 if (extMat.Get(AI_MATKEY_COLOR_EMISSIVE, color) == AI_SUCCESS) {
                     return Vitrae::Variant(glm::vec4(color.r, color.g, color.b, color.a));
                 } else {
                     return Vitrae::Variant(glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
                 }
             }});
        root.addAiMaterialPropertyInfo({StandardParam::color_shininess.name,
                                        [](const aiMaterial &extMat) -> std::optional<Vitrae::Variant> {
                                            float shininess;
                                            if (extMat.Get(AI_MATKEY_SHININESS, shininess) ==
                                                AI_SUCCESS) {
                                                return Vitrae::Variant(glm::vec4(shininess));
                                            } else {
                                                return Vitrae::Variant(glm::vec4(1.0));
                                            }
                                        }});
    }
}