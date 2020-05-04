//
// Created by Yujia Li on 2020/5/4.
//
#include <PlaceDescriptionService.h>
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

TEST_F(APlaceDescriptionService, MakesHttpResquestToObtainAddress) {
    testing::InSequence forceExpectationOrder;
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