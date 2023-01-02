#pragma once


#include "partio.h"
#include <vector>
#include <vector_types.h>
#include "../LBDefinitions.hpp"



//#########################################################################
// Function: writePartio
//
// Dump out a bgeo file that contains particles' X, V, m.
//#########################################################################

void inline writePartio(const std::string& particleFile,
    const std::vector<float3>& particles, const size_t particleNum)
{
    // AttributeName<T> mass = Particles<T, dim>::mass_name();
    // AttributeName<Vector<T, dim>> x_name = Particles<T, dim>::X_name();
    // AttributeName<Vector<T, dim>> v_name = Particles<T, dim>::V_name();
    
    Partio::ParticlesDataMutable* parts = Partio::create();
    Partio::ParticleAttribute posH, vH, mH;
    // mH = parts->addAttribute("m", Partio::VECTOR, 1);
    posH = parts->addAttribute("position", Partio::VECTOR, 3);
    // vH = parts->addAttribute("v", Partio::VECTOR, 3);
    // auto iter = particles.iter(mass, x_name, v_name);
    // auto iter = particles.iter(x_name);
    for (int i = 0; i < particleNum; i++)
    {
        int idx = parts->addParticle();
        // float* m = parts->dataWrite<float>(mH, idx);
        float* p = parts->dataWrite<float>(posH, idx);

        p[0] = particles[i].x;
        p[1] = particles[i].y;
        p[2] = particles[i].z;
        // float* v = parts->dataWrite<float>(vH, idx);

        // T mass = iter.template get<0>();
        // m[0] = mass;

        //Vector<T, dim> X = iter.template get<0>();
        // Vector<T, dim> V = iter.template get<2>();

        // 这一段暂时不用了，因为目前只有3维
        /*for (int k = 0; k < 3; k++)
            p[k] = (T)0;*/
        // for (int k = 0; k < 3; k++)
        //    v[k] = (T)0;

        /*for (int k = 0; k < 3; k++)
            p[k] = X(k);*/
        
        // for (int k = 0; k < dim; k++)
        //    v[k] = V(k);
    }

    Partio::write(particleFile.c_str(), *parts);
    parts->release();

}

void inline writePartioFluid(const std::string& particleFile,
    const std::vector<float3>& particles, const std::vector<int> parFlags, const size_t particleNum)
{
    // AttributeName<T> mass = Particles<T, dim>::mass_name();
    // AttributeName<Vector<T, dim>> x_name = Particles<T, dim>::X_name();
    // AttributeName<Vector<T, dim>> v_name = Particles<T, dim>::V_name();

    Partio::ParticlesDataMutable* parts = Partio::create();
    Partio::ParticleAttribute posH, vH, mH;
    // mH = parts->addAttribute("m", Partio::VECTOR, 1);
    posH = parts->addAttribute("position", Partio::VECTOR, 3);
    // vH = parts->addAttribute("v", Partio::VECTOR, 3);
    // auto iter = particles.iter(mass, x_name, v_name);
    // auto iter = particles.iter(x_name);
    for (int i = 0; i < particleNum; i++)
    {
        if (parFlags[i] == TYPEFLUID)
        {
            int idx = parts->addParticle();
            // float* m = parts->dataWrite<float>(mH, idx);
            float* p = parts->dataWrite<float>(posH, idx);

            p[0] = particles[i].x;
            p[1] = particles[i].y;
            p[2] = particles[i].z;
            // float* v = parts->dataWrite<float>(vH, idx);

            // T mass = iter.template get<0>();
            // m[0] = mass;

            //Vector<T, dim> X = iter.template get<0>();
            // Vector<T, dim> V = iter.template get<2>();

            // 这一段暂时不用了，因为目前只有3维
            /*for (int k = 0; k < 3; k++)
                p[k] = (T)0;*/
                // for (int k = 0; k < 3; k++)
                //    v[k] = (T)0;

                /*for (int k = 0; k < 3; k++)
                    p[k] = X(k);*/

                    // for (int k = 0; k < dim; k++)
                    //    v[k] = V(k);
        }
        
    }

    Partio::write(particleFile.c_str(), *parts);
    parts->release();

}

void inline writePartioEscape(const std::string& particleFile,
    const std::vector<float3>& particles, const std::vector<int> parFlags, const size_t particleNum)
{
    // AttributeName<T> mass = Particles<T, dim>::mass_name();
    // AttributeName<Vector<T, dim>> x_name = Particles<T, dim>::X_name();
    // AttributeName<Vector<T, dim>> v_name = Particles<T, dim>::V_name();

    Partio::ParticlesDataMutable* parts = Partio::create();
    Partio::ParticleAttribute posH, vH, mH;
    // mH = parts->addAttribute("m", Partio::VECTOR, 1);
    posH = parts->addAttribute("position", Partio::VECTOR, 3);
    // vH = parts->addAttribute("v", Partio::VECTOR, 3);
    // auto iter = particles.iter(mass, x_name, v_name);
    // auto iter = particles.iter(x_name);
    for (int i = 0; i < particleNum; i++)
    {
        if (parFlags[i] == TYPEESCAPE)
        {
            int idx = parts->addParticle();
            // float* m = parts->dataWrite<float>(mH, idx);
            float* p = parts->dataWrite<float>(posH, idx);

            p[0] = particles[i].x;
            p[1] = particles[i].y;
            p[2] = particles[i].z;
            // float* v = parts->dataWrite<float>(vH, idx);

            // T mass = iter.template get<0>();
            // m[0] = mass;

            //Vector<T, dim> X = iter.template get<0>();
            // Vector<T, dim> V = iter.template get<2>();

            // 这一段暂时不用了，因为目前只有3维
            /*for (int k = 0; k < 3; k++)
                p[k] = (T)0;*/
                // for (int k = 0; k < 3; k++)
                //    v[k] = (T)0;

                /*for (int k = 0; k < 3; k++)
                    p[k] = X(k);*/

                    // for (int k = 0; k < dim; k++)
                    //    v[k] = V(k);
        }
        
    }

    Partio::write(particleFile.c_str(), *parts);
    parts->release();

}

void inline writePartioSolid(const std::string& particleFile,
    const std::vector<float3>& particles, const std::vector<int> parFlags, const size_t particleNum)
{
    // AttributeName<T> mass = Particles<T, dim>::mass_name();
    // AttributeName<Vector<T, dim>> x_name = Particles<T, dim>::X_name();
    // AttributeName<Vector<T, dim>> v_name = Particles<T, dim>::V_name();

    Partio::ParticlesDataMutable* parts = Partio::create();
    Partio::ParticleAttribute posH, vH, mH;
    // mH = parts->addAttribute("m", Partio::VECTOR, 1);
    posH = parts->addAttribute("position", Partio::VECTOR, 3);
    // vH = parts->addAttribute("v", Partio::VECTOR, 3);
    // auto iter = particles.iter(mass, x_name, v_name);
    // auto iter = particles.iter(x_name);
    for (int i = 0; i < particleNum; i++)
    {
        if (parFlags[i] == TYPESOLID)
        {
            int idx = parts->addParticle();
            // float* m = parts->dataWrite<float>(mH, idx);
            float* p = parts->dataWrite<float>(posH, idx);

            p[0] = particles[i].x;
            p[1] = particles[i].y;
            p[2] = particles[i].z;
            // float* v = parts->dataWrite<float>(vH, idx);

            // T mass = iter.template get<0>();
            // m[0] = mass;

            //Vector<T, dim> X = iter.template get<0>();
            // Vector<T, dim> V = iter.template get<2>();

            // 这一段暂时不用了，因为目前只有3维
            /*for (int k = 0; k < 3; k++)
                p[k] = (T)0;*/
                // for (int k = 0; k < 3; k++)
                //    v[k] = (T)0;

                /*for (int k = 0; k < 3; k++)
                    p[k] = X(k);*/

                    // for (int k = 0; k < dim; k++)
                    //    v[k] = V(k);
        }
    }

    Partio::write(particleFile.c_str(), *parts);
    parts->release();

}

void inline writePartioGrid(const std::string& particleFile, const std::vector<float3>& gridPos,
    const std::vector<flag_t>& flagField, const size_t cellNum)
{
    // AttributeName<T> mass = Particles<T, dim>::mass_name();
    // AttributeName<Vector<T, dim>> x_name = Particles<T, dim>::X_name();
    // AttributeName<Vector<T, dim>> v_name = Particles<T, dim>::V_name();

    Partio::ParticlesDataMutable* parts = Partio::create();
    Partio::ParticleAttribute posH, vH, mH;
    //mH = parts->addAttribute("m", Partio::VECTOR, 1);
    posH = parts->addAttribute("position", Partio::VECTOR, 3);
    // vH = parts->addAttribute("v", Partio::VECTOR, 3);
    // auto iter = particles.iter(mass, x_name, v_name);
    // auto iter = particles.iter(x_name);
    for (int i = 0; i < cellNum; i++)
    {
        if (flagField[i] == flag_t::FLUID || flagField[i] == flag_t::INTERFACE)
        {
            int idx = parts->addParticle();
            float* p = parts->dataWrite<float>(posH, idx);
            p[0] = gridPos[i].x;
            p[1] = gridPos[i].y;
            p[2] = gridPos[i].z;
        }
        //float* m = parts->dataWrite<float>(mH, idx);

        
        // float* v = parts->dataWrite<float>(vH, idx);

        // T mass = iter.template get<0>();
        //m[0] = mass[i];

        //Vector<T, dim> X = iter.template get<0>();
        // Vector<T, dim> V = iter.template get<2>();

        // 这一段暂时不用了，因为目前只有3维
        /*for (int k = 0; k < 3; k++)
            p[k] = (T)0;*/
            // for (int k = 0; k < 3; k++)
            //    v[k] = (T)0;

            /*for (int k = 0; k < 3; k++)
                p[k] = X(k);*/

                // for (int k = 0; k < dim; k++)
                //    v[k] = V(k);
    }

    Partio::write(particleFile.c_str(), *parts);
    parts->release();

}