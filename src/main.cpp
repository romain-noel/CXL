// C++ program to Execute  
/*
   Program Name: CXL (Command eXecutor Library)
   Version: 0.0.a
   Date: 1/02/2021
   Description:
   Input: XML file or commands in terminal mode
   Output:
   Example:
   Authors:
      Romain NOËL (romain.noel@univ-eiffel.fr)
   License:
      BSD 2-Clause License
      It implies    
*/
  
// Import modules.
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "hello.h"

// Define the NameSpaces.
using namespace std;
using namespace rapidxml;

// main program begins 
int main(void) 
{ 
   // Beginning of the main part of the program.
   cout << "CXL++: Main (Start)" << endl;

   // Initialize Variables.
   int errorCode=0;

   // call a function in another file.
   myPrintHelloMake(); 

   // Try the main part
   int numMaxTry=2;
   int numTry=1;
   label1:
   try
   {
      rapidxml::file<> xmlFile("params_CXL.xml");
      rapidxml::xml_document<> doc;
      doc.parse<0>(xmlFile.data());

      cout << "Parsing my beer journal..." << endl;
      // Iterate over the InputCommands packs.
      for (xml_node<> * inputPack_node = doc.first_node(); inputPack_node != NULL; inputPack_node = inputPack_node->next_sibling())
      {
         // Get name and type of the inputPack node.
         string namePackNode= inputPack_node->name();
         rapidxml::xml_attribute<>* attr = inputPack_node->first_attribute("type", false);
         string typePackNode;
         if(attr == nullptr) {
            typePackNode= "Default Type";
         } else {
            typePackNode= attr->value();
         }

         // Check if name and type of inputPack node are corret.
         cout << "Parsing namePackNode:" << namePackNode << endl;
         if ( cmpcaseinsens(namePackNode, "inputcommands") !=true )
         {
            cout << "The node named:"<< namePackNode<< " is unknown. Please check the spelling. Node skipped !" << endl;
            continue;
         };
         if ( cmpcaseinsens(typePackNode, "CXL") !=true )
         {
            if (cmpcaseinsens(typePackNode, "Default Type") )
            {
               cout << "The node named:"<< namePackNode<< " has type "<<typePackNode<<". 'CXL' type is prefered, but it is continue ! " << endl;
            } else {
               cout << "The node named:"<< namePackNode<< " has type "<<typePackNode<<". Unknown type ! Node skipped ! " << endl;
               continue;
            }
            
         };

         for (xml_node<> * inputCommand_node = inputPack_node->first_node(); inputCommand_node != NULL; inputCommand_node = inputCommand_node->next_sibling())
         {
            // Get name and type of the inputPack node.
            string nameCommandNode= inputCommand_node->name();
            // Check if name and type of inputPack node are corret.
            cout << "Parsing nameCommandNode:" << nameCommandNode << endl;
         }
         
      }
      std::cout << "Parsing the input file is done." << endl;
   }
   catch (const std::runtime_error& e)
   {
      std::cerr << "Runtime error: " << e.what() << std::endl;
      if (numTry < numMaxTry)
      {
         numTry += 1;
         goto label1;
      }
      errorCode= 10;
   }
   catch (const rapidxml::parse_error& e)
   {
      std::cerr << "Parse error: " << e.what() << std::endl;
      errorCode= 11;
   }
   catch (const std::exception& e)
   {
      std::cerr << "Exception: " << e.what() << std::endl;
      errorCode= 12;
   }
   catch (...)
   {
      std::cerr << "An unknown error occurred in the main loop !" << std::endl;
      errorCode= 13;
   }

   // End of the main.
   cout << "CXL++: Main (End): "<< errorCode << endl;   
   return(errorCode); 
} 

// MEMO
/*
   toto
*/

// EoF