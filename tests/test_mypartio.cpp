#include "Partio.h"
using namespace Partio;

int main()
{
    // 读取文件
    const Partio::ParticlesData* data=Partio::read("ice-cream.bhclassic");
    // 计算粒子数目
    std::cout<<"Number of particles "<<data->numParticles()<<std::endl;

    print(data);
    
}