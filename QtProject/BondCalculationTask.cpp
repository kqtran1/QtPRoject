#include "BondCalculationTask.h"
#include "services/BondPricerService.h"
#include "utils.h"

#include <iostream>
#include <iomanip>

BondCalculationTask::BondCalculationTask(const BondDataList & bondDataList, const std::string& name): 
        Task(name),
        data(bondDataList) {
}

BondCalculationTask::~BondCalculationTask() {
}

void BondCalculationTask::runTask() {

}

