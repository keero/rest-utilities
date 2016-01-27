#include <iostream>
#include <sstream>
#include <fstream>

#include "../../dto/hypermedia/Form.h"

#ifndef READY4AIR_TESTS_DTO_FORM_H
#define READY4AIR_TESTS_DTO_FORM_H

namespace ready4air
{
    namespace tests
    {
        class FormTest
        {
        public:
            static bool RunTest(const std::string &jsonFilePath, dto::Form &form)
            {
                std::ostringstream ss;
                std::ifstream fs(jsonFilePath);

                if (fs.is_open())
                {
                    std::string content;
                    while (fs >> content)
                    {
                        ss << content;
                    }
                    std::string json = ss.str();

                    dto::ParseErrors parseErrors;

                    if (!form.InitFromJsonString(json, parseErrors))
                    {
                        std::cout << "Unable to parse Form." << std::endl;
                        if (parseErrors)
                        {
                            std::vector<dto::ParseErrors::ParseErrorItem> items = parseErrors.GetParseErrors();
                            for (size_t i = 0; i < items.size(); i += 1)
                            {
                                dto::ParseErrors::ParseErrorItem item = items[i];
                                std::cout << "    " << item.Code << " : " << item.Message << std::endl;
                            }
                        }
                        return false;
                    }

                    std::cout << "Successfully parsed Form." << std::endl;
                    return true;
                }
                return false;
            }
        };
    }
}

#endif //READY4AIR_TESTS_DTO_FORM_H
