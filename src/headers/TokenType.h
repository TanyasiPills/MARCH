#pragma once

enum TokenType{
    //Variables
    intType,        //0
    inTType,        //1
    stringType,     //2
    nameType,       //3
    numberType,     //4
    charType,       //5
    textType,       //6

    //Math
    assingType,     //7
    additionType,   //8
    subtractioType, //9

    //file
    functionType,   //10
    commandType,    //11
    lineType,       //12
    EOFType         //13
};