#!/bin/bash
#PBS -M m.neira10@uniandes.edu.co
#PBS -m abe
#PBS -N mneira10_testSubmission
#PBS -j oe


module load gcc/4.9.4
module load anaconda/python3
cd /hpcfs/home/fisi4028/m.neira10/MauricioNeira_Ejercicio25
ls
make
