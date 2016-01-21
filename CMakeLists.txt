cmake_minimum_required(VERSION 3.3)
project(rest_utilities)

include_directories("include/")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "lib/")

set(URLTEMPLATE_SOURCE_FILES
        ready4air/common/Either.h
        ready4air/common/Maybe.h
        ready4air/urltemplate/UrlTemplate.h
        )

set(HYPERMEDIA_SOURCE_FILES
        ready4air/dto/hypermedia/Form.h
        ready4air/dto/hypermedia/Link.h
        ready4air/dto/hypermedia/Crud.h
        ready4air/dto/abstract/JsonDeserializable.h
        )


set(READY4AIR_DTO_SOURCE_FILES
        ready4air/dto/Bundle.h
        ready4air/dto/Button.h
        ready4air/dto/Image.h
        ready4air/dto/WmvFile.h
        ready4air/dto/SmoothManifest.h
        ready4air/dto/Cast.h
        ready4air/dto/Catalogue.h
        ready4air/dto/Content.h
        ready4air/dto/MenuItem.h
        ready4air/dto/Section.h
        ready4air/dto/Teaser.h
        ready4air/dto/LiveSection.h
        ready4air/dto/Promotion.h
        ready4air/dto/Device.h
        ready4air/dto/DeviceAuthData.h
        ready4air/dto/Display.h
        ready4air/dto/DRM.h
        ready4air/dto/Entitlement.h
        ready4air/dto/Episode.h
        ready4air/dto/MediaProduct.h
        ready4air/dto/Error.h
        ready4air/dto/ErrorForm.h
        ready4air/dto/FileBase.h
        ready4air/dto/FreePage.h
        ready4air/dto/GenericPage.h
        ready4air/dto/Genre.h
        ready4air/dto/Help.h
        ready4air/dto/HlsManifest.h
        ready4air/dto/Language.h
        ready4air/dto/LanguageList.h
        ready4air/dto/List.h
        ready4air/dto/ListMedia.h
        ready4air/dto/Literal.h
        ready4air/dto/Channel.h
        ready4air/dto/EpgInfo.h
        ready4air/dto/Event.h
        ready4air/dto/Mp4File.h
        ready4air/dto/Subtitle.h
        ready4air/dto/PurchaseItem.h
        ready4air/dto/Reviews.h
        ready4air/dto/Movie.h
        ready4air/dto/Page.h
        ready4air/dto/Play.h
        ready4air/dto/Manifests.h
        ready4air/dto/Manifest.h
        ready4air/dto/ProtectionData.h
        ready4air/dto/PlaySubtitle.h
        ready4air/dto/File.h
        ready4air/dto/QuoteImage.h
        ready4air/dto/QuoteImages.h
        ready4air/dto/UserRating.h
        ready4air/dto/CriticsQuote.h
        ready4air/dto/Season.h
        ready4air/dto/SeasonProduct.h
        ready4air/dto/Series.h
        ready4air/dto/User.h
        ready4air/dto/UserList.h
        ready4air/dto/UserListItem.h
        ready4air/dto/Bookmark.h
        ready4air/dto/UserFavouriteLists.h
        ready4air/dto/Purchase.h
        ready4air/dto/PaymentData.h
        ready4air/dto/PurchaseInfo.h
        ready4air/dto/Product.h)

set(SERVICES_SOURCE_FILES
        ready4air/services/Root.h
        ready4air/external/RequestData.h
        ready4air/external/ResponseData.h
        ready4air/services/DevicesService.h
        ready4air/services/PagesService.h
        ready4air/services/HelpsService.h
        ready4air/services/LiteralsService.h
        ready4air/services/RequestService.h
        ready4air/external/IHttpClient.h
        ready4air/external/IEvent.h
        ready4air/services/Error.h
        ready4air/services/exceptions/BadHttpClientType.h
        ready4air/services/exceptions/BadEventType.h
        ready4air/services/UsersService.h
        ready4air/services/PaginationService.h
        ready4air/services/exceptions/BadPaginatedType.h
        ready4air/services/MediasService.h
        ready4air/services/MoviesService.h
        ready4air/services/SeriesService.h
        ready4air/services/BundlesService.h)

set(MAYBE_TESTS_SOURCE_FILES
        ready4air/tests/MaybeTester.cpp
        ready4air/common/Maybe.h)

add_executable(MaybeTester ${MAYBE_TESTS_SOURCE_FILES})

set(URLTEMPLATE_TESTS_SOURCE_FILES
        ready4air/tests/UrlTemplateTester.cpp
        ${URLTEMPLATE_SOURCE_FILES})

add_executable(UrlTemplateTester ${URLTEMPLATE_TESTS_SOURCE_FILES})

set(HYPERMEDIA_TESTS_SOURCE_FILES
        ready4air/tests/HypermediaTester.cpp
        ${HYPERMEDIA_SOURCE_FILES}
        ${URLTEMPLATE_SOURCE_FILES})

add_executable(HypermediaTester ${HYPERMEDIA_TESTS_SOURCE_FILES})

set(READY4AIR_DTO_TESTS_SOURCE_FILES
        ready4air/tests/dto/DTO.cpp
        ready4air/tests/dto/ServiceRoot.h
        ${READY4AIR_DTO_SOURCE_FILES}
        ${HYPERMEDIA_SOURCE_FILES}
        ${URLTEMPLATE_SOURCE_FILES})

add_executable(Ready4AirDTOTester ${READY4AIR_DTO_TESTS_SOURCE_FILES})

set(READY4AIR_SERVICES_TESTS_SOURCE_FILES
        ready4air/tests/services/Root.cpp
        ready4air/tests/services/HttpClient.h
        ready4air/tests/services/AuthDeviceEvent.h
        ${SERVICES_SOURCE_FILES}
        ${READY4AIR_DTO_SOURCE_FILES}
        ${HYPERMEDIA_SOURCE_FILES}
        ${URLTEMPLATE_SOURCE_FILES})

add_executable(Ready4AirServicesTester ${READY4AIR_SERVICES_TESTS_SOURCE_FILES})

set(READY4AIR_TESTS_SOURCE_FILES
        ready4air/tests/Ready4AirTester.cpp
        ${READY4AIR_DTO_SOURCE_FILES}
        ${HYPERMEDIA_SOURCE_FILES}
        ${URLTEMPLATE_SOURCE_FILES})

add_executable(Ready4AirTester ${READY4AIR_TESTS_SOURCE_FILES})
