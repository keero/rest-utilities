cmake_minimum_required(VERSION 3.3)
project(rest_utilities)

include_directories("${PROJECT_SOURCE_DIR}/include/")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/lib/")

set(URLTEMPLATE_SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/ready4air/urltemplate/UrlTemplate.h
        )

set(HYPERMEDIA_SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/ready4air/dto/hypermedia/Form.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/hypermedia/Link.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/hypermedia/Crud.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/abstract/JsonDeserializable.h
        )


set(READY4AIR_DTO_SOURCE_FILES
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Bundle.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Button.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Image.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/WmvFile.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/SmoothManifest.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Cast.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Catalogue.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Content.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/MenuItem.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Section.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Teaser.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/LiveSection.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Promotion.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Device.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/DeviceAuthData.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Display.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/DRM.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Entitlement.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Episode.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/MediaProduct.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Error.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/ErrorForm.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/FileBase.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/FreePage.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/GenericPage.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Genre.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Help.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/HlsManifest.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Language.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/LanguageList.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/List.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/ListMedia.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Literal.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Channel.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/EpgInfo.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Event.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Mp4File.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Subtitle.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/PurchaseItem.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Reviews.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Movie.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Page.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Play.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Manifests.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Manifest.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/ProtectionData.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/PlaySubtitle.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/File.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/QuoteImage.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/QuoteImages.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/UserRating.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/CriticsQuote.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Season.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/SeasonProduct.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Series.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/User.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/UserList.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/UserListItem.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Bookmark.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/UserFavouriteLists.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/Purchase.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/PaymentData.h
        ${PROJECT_SOURCE_DIR}/ready4air/dto/PurchaseInfo.h
        )

add_executable(HypermediaTester
        ${PROJECT_SOURCE_DIR}/ready4air/tests/HypermediaTester.cpp
        ${HYPERMEDIA_SOURCE_FILES}
        ${URLTEMPLATE_SOURCE_FILES})

add_executable(UrlTemplateTester
        ${PROJECT_SOURCE_DIR}/ready4air/tests/UrlTemplateTester.cpp
        ${URLTEMPLATE_SOURCE_FILES})

add_executable(Ready4AirTester
        ${PROJECT_SOURCE_DIR}/ready4air/tests/Ready4AirTester.cpp
        ${READY4AIR_DTO_SOURCE_FILES}
        ${HYPERMEDIA_SOURCE_FILES}
        ${URLTEMPLATE_SOURCE_FILES})

