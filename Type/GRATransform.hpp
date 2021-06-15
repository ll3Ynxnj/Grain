#ifndef GRAIN_GRATRANSFORM_HPP
#define GRAIN_GRATRANSFORM_HPP

template <typename T> struct GRATransform
{
  GRAVec3<T> translation, rotation, scale;
  GRATransform(const GRAVec3<T> &aTranslation, const GRAVec3<T> &aRotation,
               const GRAVec3<T> &aScale) :
    translation(aTranslation), rotation(aRotation), scale(aScale) {};
};

#endif // GRAIN_GRATRANSFORM_HPP
