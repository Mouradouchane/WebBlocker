# WebBlocker v3 : *STABLE*


## about :
**lightweight** program for blocking websites to **the next formatting of pc** without step back .



## what's new in v3 :
[32bit] : removing all json usage for optimization program .
[64bit] : not supported yet , maybe become supported in v4 or above .




## requirement  :
- **windows operating system** 32bit or 64bit .
- **maybe** C++ runtime requirement .
- **Any** pc resource can make this program run .



## download :
- if you familiar with 'git version control' you can make a simple **clone** directly by using following command :
```
  =========================================================================
        git clone https://github.com/Mouradouchane/WebBlocker.git
  =========================================================================

   - then use .exe file in DEBUG folder directly .
```

- if you're not familiar with 'git version control' follow this steps :
1. click on **green button** has content **code** .
2. click on **Download ZIP** and wait downloading complet .

## usage :
  - after you extract zip file .
  
  - then you have to go to : **Debug folder** and open **WebBlocker.exe ' as admin '**
    or go to **WebBlocker** folder directlly and open **WebBlocker.exe**  both ways are the same.
    
  - then should open **WebBlocker.exe** as **console application** .

  - **for see all commands avalible in program you can use on of them :**
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
