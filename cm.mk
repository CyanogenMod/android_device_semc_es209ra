## Specify phone tech before including full_phone
$(call inherit-product, vendor/cm/config/gsm.mk)

# Release name
PRODUCT_RELEASE_NAME := X10i

TARGET_BOOTANIMATION_NAME := vertical-480x854

# Inherit some common CM stuff.
$(call inherit-product, vendor/cm/config/common_full_phone.mk)

# Inherit device configuration
$(call inherit-product, device/semc/es209ra/device_es209ra.mk)

## Device identifier. This must come after all inclusions
PRODUCT_DEVICE := es209ra
PRODUCT_NAME := cm_es209ra
PRODUCT_BRAND := SEMC
PRODUCT_MODEL := Xperia X10

#Set build fingerprint / ID / Product Name ect.
PRODUCT_BUILD_PROP_OVERRIDES += PRODUCT_NAME=X10i BUILD_ID=ITL41F BUILD_DISPLAY_ID=ITL41F BUILD_FINGERPRINT="google/yakju/maguro:4.0.1/ITL41F/228551:user/release-keys" PRIVATE_BUILD_DESC="yakju-user 4.0.1 ITL41F 228551 release-keys"
