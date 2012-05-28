#include "BondCalculationTask.h"
#include "services/BondPricerService.h"
#include "utils.h"

#include <iostream>
#include <iomanip>

using namespace QuantLib;

BondCalculationTask::BondCalculationTask(const BondDataList & bondDataList, const std::string& name): 
        Task(name),
        data(bondDataList) {
}

BondCalculationTask::~BondCalculationTask() {
}

void BondCalculationTask::runTask() {

}

