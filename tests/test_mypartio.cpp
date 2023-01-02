#include "Partio.h"
using namespace Partio;

std::vector<ParticleAttribute>
getAttrs(const ParticlesData& particles)
{
    std::vector<ParticleAttribute> attrs(particles.numAttributes());
    for(int i=0;i<particles.numAttributes();i++){
        particles.attributeInfo(i,attrs[i]);
    }
    return attrs;
}

int main()
{
    // 读取文件
    const Partio::ParticlesData* data=Partio::read("ice-cream.bhclassic");
    // 计算粒子数目
    std::cout<<"Number of particles "<<data->numParticles()<<std::endl;

    print(data);
    
    std::vector<ParticleAttribute> attrs = getAttrs(*data);
    ParticlesData::const_iterator it=data->begin(),end=data->end();
    std::vector<ParticleAccessor> accessors;
    for(size_t k=0;k<attrs.size();k++) accessors.push_back(ParticleAccessor(attrs[k]));
    for(size_t k=0;k<attrs.size();k++) it.addAccessor(accessors[k]);

    for(int i=0;i<10 && it != end;i++, it++){
        std::cout<<i<<": ";
        for(unsigned int k=0;k<attrs.size();k++)
        {
            std::cout<<attrs[k].name<<"=";
            if (attrs[k].count > 1) std::cout<<"(";

                for(int c=0;c<attrs[k].count;c++) 
                {
                    if (c) std::cout << ",";
                    std::cout<<accessors[k].raw<int>(it)[c]<<",";
                }
            if (attrs[k].count > 1) std::cout<<")";
            std::cout<<"\t";
        }
        std::cout<<std::endl;
    }
}