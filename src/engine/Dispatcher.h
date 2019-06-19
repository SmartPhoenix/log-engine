/* Created by BridgeTroll
 * https://bridgetroll.de
 * https://steamcommunity.com/id/Bridge_Troll/
 *
 * Dispatcher.h
 *
 *  Created on: 13.05.2019
 *      Author: bt
 */
#ifndef DISPATCHER_H
#define DISPATCHER_H

#include <list>
#include <Config.h>

#include "../lib/json.hpp"
#include "../util/logger/Logger.h"
#include "IEngineAdapter.h"
#include "model/EngineInput.h"

namespace engine
{

    class Dispatcher
    {
    private:
        EngineInput engineInput;
        util::Logger *logger;
        nlohmann::json configuration;

        std::list<IEngineAdapter *> executionList;

        void validate(const std::string &payload);

        void initEngines();

        void run();

        void terminate();

    public:
        explicit Dispatcher(EngineInput eIN);

        enum ENGINE_FUNCTION
        {
            SEARCH = 0,
            SEARCH_AND_CATEGORIZE = 1,
            RETURN_RAW = 2,
            CLIENT_UPTIME = 3,
            INTERNAL_OPTIMIZE_ME = 4,
            PATTERN_ABUSER = 5
        };
    };
}
#endif /* DISPATCHER_H */
