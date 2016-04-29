/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/array.h"

/** \brief  To indicate that all position in the array are empty,
 *          this function put the flag (isEmpty) in TRUE in all
 *          position of the array
 * \param pEmployee employee* Pointer to array of employees
 * \param length int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(employee* pEmployee, int length)
{
    int retorno = -1;
    int i;
    if(pEmployee != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            pEmployee[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}


/** \brief add in a existing list of employees the values recived as parameters
 *
 * \param pEmployee employee*
 * \param length int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int addEmployee(employee* pEmployee, int length, int id, char name[],char lastName[],float salary,int sector)
{
    int i;
    int retorno = -1;
    if(pEmployee != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            if(pEmployee[i].isEmpty == 1)
            {
                pEmployee[i].id = id;
                strcpy(pEmployee[i].name, name);
                strcpy(pEmployee[i].lastName, lastName);
                pEmployee[i].salary = salary;
                pEmployee[i].sector = sector;
                pEmployee[i].isEmpty = 0;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}


/** \brief find a Employee by Id
 *
 * \param pEmployee employee*
 * \param length int
 * \param id int
 * \return employee* Return a (Employee pointer) if ok or (NULL pointer) if [Invalid length or NULL pointer recived or employeed not found]
 *
 */
employee* findEmployeeById(employee* pEmployee, int length,int id)
{
    int i;
    employee* retorno = NULL;
    if(pEmployee != NULL && length > 0)
    {
        for(i=0;i<length;i++)
        {
            if(pEmployee[i].id == id && pEmployee[i].isEmpty == 0)
            {
                retorno = &pEmployee[i];
                break;
            }
        }
    }
    return retorno;

}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param pEmployee employee*
 * \param length int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int removeEmployee(employee* pEmployee, int length, int id)
{
    int retorno = -1;
    employee*  auxEmployee = NULL ;
    auxEmployee = findEmployeeById(pEmployee,length, id);

    if(auxEmployee != NULL)
    {
        auxEmployee->isEmpty = 1;
        retorno = 0;
    }

    return retorno;
}



/** \brief Sort the elements in the array of employees by Name, the argument order indicate UP or DOWN order
 *
 * \param pEmployee employee*
 * \param length int
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployeeByName(employee* pEmployee, int length, int order)
{
    int i,j;
    int retorno = -1;
    employee auxEmployee;

    if(pEmployee != NULL && length > 0)
    {
        for(i=0;i<length-1;i++)
        {
            for(j=i+1;j<length;j++)
            {
                if(strcmp(pEmployee[i].name, pEmployee[j].name)> 0 && order == 1)
                {
                    auxEmployee =pEmployee[i];
                    pEmployee[i] = pEmployee[j];
                    pEmployee[j] = auxEmployee;
                }
                else if((strcmp(pEmployee[i].name, pEmployee[j].name)< 0 && order == 0))
                {
                    auxEmployee =pEmployee[i];
                    pEmployee[i] = pEmployee[j];
                    pEmployee[j] = auxEmployee;
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}



/** \brief
 *
 * \param pEmployee employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(employee* pEmployee, int length)
{
    int i;
    printf("\n  Id   -       Name       -     Last Name    - Salary  - Sector");
    for(i=0; i< length; i++)
    {
        if(!pEmployee[i].isEmpty)
            printf("\n%6i - %-16s - %-16s - %4.2f - %6d",pEmployee[i].id, pEmployee[i].name, pEmployee[i].lastName, pEmployee[i].salary, pEmployee[i].sector );
    }
    return 0;
}






