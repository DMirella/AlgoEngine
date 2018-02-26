#include "sortalgorithm.h"
#include <QDebug>
#include <qalgorithms.h>

SortAlgorithm::SortAlgorithm()
{

}

void SortAlgorithm::setSettings(SortAlgorithmSettings settings)
{
    this->settings = settings;
}

void SortAlgorithm::mainAlgorithm()
{
    QList<int> res = settings.input.array->getData().array;
    qSort(res);
    if(settings.mode == SortMode::Decrease){
        int n = res.size();
        for(int i = 0; i < n / 2; i++){
            res.swap(i, n - i - 1);
        }
    }
    Data ans;
    ans.array = res;
    settings.output.array->setData(ans);
}
