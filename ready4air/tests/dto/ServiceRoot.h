//
// Created by Martin Kero on 13/01/16.
//

#include <iostream>
#include <sstream>
#include <fstream>

#include "../../dto/Device.h"

#ifndef READY4AIR_TESTS_DTO_SERVICEROOT_H
#define READY4AIR_TESTS_DTO_SERVICEROOT_H

namespace ready4air
{
    namespace tests
    {
        class ServiceRoot
        {
        public:
            static BOOL_T RunTest(const STRING_T &jsonFilePath, dto::Device &device)
            {
                std::ostringstream ss;
                std::ifstream fs(jsonFilePath);

                if (fs.is_open())
                {
                    STRING_T content;
                    while (fs >> content)
                    {
                        ss << content;
                    }
                    STRING_T json = ss.str();

                    dto::ParseErrors parseErrors;

                    if (!device.InitFromJsonString(json, parseErrors))
                    {
                        std::cout << "Unable to parse ServiceRoot response." << std::endl;
                        if (parseErrors)
                        {
                            VECTOR_T<dto::ParseErrors::ParseErrorItem> items = parseErrors.GetParseErrors();
                            for (size_t i = 0; i < items.size(); i += 1)
                            {
                                dto::ParseErrors::ParseErrorItem item = items[i];
                                std::cout << "    " << item.Code << " : " << item.Message << std::endl;
                            }
                        }
                        return false;
                    }

                    std::cout << "Successfully parsed ServiceRoot response." << std::endl;
                    return true;
                }
                return false;
            }
        };
    }
}

#endif //READY4AIR_TESTS_DTO_SERVICEROOT_H
