# Rev_Hell
- Developed by BlackoutDev

A DLL file created in C++ that allows you to get a reverse shell after hijacking a DLL process. This is a great way to have persistence on a machine if you are doing a red team survey or a pen test.

## [How to setup]

To setup you will need to have Visual Studio set up on your system from here you can now begin the process of setting up Rev_Hell.

  - Firstly, create a Dynamic Link Libray solution in Visual Studio. This can be found under the C++ section of VIsual Studio
  - Name your project and solution and once created copy and paste the code from the download rev_shell.cpp file you downloaded
  - Now you need to do some port forwarding. The easiest way to do this is via NGROK and creating a TCP session
  - Once you have this, you need to add the session IP into line 18 in your program where it says "127.0.0.1"
  - Now you also need to change the port in line 19 to the port you have port forwarded
  - Now build the solution and you have a .dll file that is ready to be deployed on your red team engagement
  
 
