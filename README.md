# WebBlocker Beta v2 : *stable*



## what's new in v2 :
[32bit] aadding dll's supporting for making webBlocker worked correctly without problems 
        if your windows have missing some dlls in system32 .
[64bit] not supported yet , supporte in 64bit come with version 3 .



## about :
it's a **small and fast** program for blocking web sites to **the next formatting of pc** without step back .



## requirement  :
- **windows operating system** 32bit or 64bit .
- **maybe** C++ runtime requirement .



## download :
- if you familiar with 'git version control' you can make a simple **clone** directly by using following command :
```
  =========================================================================
        git clone https://github.com/Mouradouchane/WebBlocker.git
  =========================================================================
```

- if you're not familiar with 'git version control' follow this steps :
1. click on **green button** has content **code** .
2. click on **Download ZIP** and wait downloading complet .

## usage :
  - after you extract zip file .
  
  - if you have **windows 32bit** go to : **Debug folder** and open **WebBlocker.exe ' as admin '**
    or go to **WebBlocker** folder directlly and open **WebBlocker.exe**  both ways are the same.
    
  - then should open **WebBlocker v2** as **console application** .

  - **for see all commands avalible in program try enter :**
  ``` 
  =========================================================================
        $ help
        $ webBlocker --help
        $ webBlocker -h 
  =========================================================================
  ```
  - for **block website or multiple websites** :
  NOTE! : don't use : **www.** or **http:** or **https:** or **special charachters** just 'address.domain'
  ```
  =========================================================================
        $ webBlocker -b address.domain address.domain ... 
        $ webBlocker --block addres.domain address.domain ...
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
        [webBlocker] : blocking web => address.domain
  =========================================================================
  ```
  - else you see **warning message** probably this message content is invalid format .
  
