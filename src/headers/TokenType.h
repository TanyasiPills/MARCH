#pragma once

enum TokenType{
    //Variables
    intType,        //0
    inTType,        //1
    stringType,     //2
    nameType,       //3
    valueType,      //4

    //Math
    assingType,     //5
    additionType,   //6
    subtractioType, //7

    //file
    functionType,
    commandType,
    lineType,       //8
    EOFType         //9
};