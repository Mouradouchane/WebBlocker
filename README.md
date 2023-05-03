# WebBlocker v3 : *STABLE*


## about :
**lightweight** program for blocking websites .



## what's new in v3 :
[32bit] : remove all json complexity .



## requirement  :
- windows 7 or up **32bit** .
- **maybe** C++ runtime requirement .



## download :
- if you familiar with 'git version control' you can make a simple **clone** directly by using following command :
```
  =========================================================================
        git clone https://github.com/Mouradouchane/WebBlocker.git
  =========================================================================

   - then build sln prject .
```

- if you're not familiar with 'git version control' follow this steps :
1. click on **green button** has content **code** .
2. click on **Download ZIP** and wait downloading complet .

## usage :
  - after you extract zip file .
  
  - then you have to go to : **Debug folder** or **Release folder** and open **WebBlocker.exe ' as admin '** .
    
  - then **WebBlocker.exe** should open as **console application** .

  - help command in order to see all avalible commands .
  ``` 
  =========================================================================
        $ help
        $ webBlocker --help
        $ webBlocker -h 
  =========================================================================
  ```
  - for **block website or multiple websites** :
  NOTE! : don't use : **www.** or **http:** or **https:** or **special charachters** just 'address.extension 

  ```
  =========================================================================
        $ webBlocker -b address.extension address.extension ... 
        $ webBlocker --block address.extension address.extension  ...
  =========================================================================
  ```
  
  ### example :
  ```
  =========================================================================
        $ webBlocker -b example1.com example2.net example3.tv  
        $ webBlocker --block example1.com example2.net example3.tv  
  =========================================================================
  ```

  - **if** your command written and **worked correctly** you should get message from WebBlocker say :
  ```
  =========================================================================
        [webBlocker] : blocking web => address.extension
  =========================================================================
  ```
  - else you see **warning message** probably this message content is invalid format .
