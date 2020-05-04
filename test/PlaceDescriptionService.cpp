//
// Created by Yujia Li on 2020/5/4.
//
#include "Http.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class HttpStub : public Http {
public:
    MOCK_METHOD0(initialize, void());
    MOCK_CONST_METHOD1(get, std::string(const std::string&));
};

class APlaceDescriptionService : public testing::Test {
public:
    static const std::string ValidLatitude;
    static const std::string ValidLongitude;
};

const std::string APlaceDescriptionService::ValidLatitude = "111";
const std::string APlaceDescriptionService::ValidLongitude = "222";

class PlaceDescriptionService {
public:
    explicit PlaceDescriptionService(Http *http) : http(http) {}

    std::string summaryDescription(const std::string &latitude, const std::string &longitude) const {
        std::string server{"http://open.mapquestapi.com/"};
        std::string document{"nominatim/v1/reverse"};;
        std::string url = server + document + "?" +
                          KeyValue("format", "json") + "&" +
                          KeyValue("lat", latitude) + "&" +
                          KeyValue("lon", longitude);
        http->initialize();
        auto response = http->get(url);

//        AddressExtractor extractor;
//        auto address = extractor.addressFrom(response);
//        return address.summaryDescription();
        return "";
    }

private:
    Http *http;

    std::string KeyValue(const std::string &key, const std::string &value) const {
        return key + "=" + value;
    }
};

TEST_F(APlaceDescriptionService, MakesHttpResquestToObtainAddress) {
    HttpStub httpStub;
    std::string urlStart{
            "http://open.mapquestapi.com/nominatim/v1/reverse?format=json&"
    };
    auto expectURL = urlStart +
                     "lat=" + APlaceDescriptionService::ValidLatitude + "&" +
                     "lon=" + APlaceDescriptionService::ValidLongitude;
    EXPECT_CALL(httpStub, initialize());
    EXPECT_CALL(httpStub, get(expectURL));
    PlaceDescriptionService service{&httpStub};

    service.summaryDescription(ValidLatitude, ValidLongitude);
}

TEST_F(APlaceDescriptionService, DISABLED_FormatsRetrievedAddressIntoSummaryDescription) {
    HttpStub httpStub;
    EXPECT_CALL(httpStub, get(testing::_))
            .WillOnce(testing::Return(
                    R"({
  "address": {
    "road": "Drury Ln",
    "city": "Fountain",
    "state": "CO",
    "country": "US"
  }
})"));
    PlaceDescriptionService service(&httpStub);
    auto description = service.summaryDescription(ValidLatitude, ValidLongitude);
    ASSERT_THAT(description, testing::Eq("Drury Ln, Fountain, CO, US"));
}