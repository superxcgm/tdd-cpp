//
// Created by Yujia Li on 2020/5/4.
//

#ifndef TDD_CPP_PLACEDESCRIPTIONSERVICE_H
#define TDD_CPP_PLACEDESCRIPTIONSERVICE_H


#include "Http.h"

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


#endif //TDD_CPP_PLACEDESCRIPTIONSERVICE_H
