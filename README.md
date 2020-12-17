# CS460 Project: Machine Learning for Fractionally-Charged Particle Searches

Project submitted in partial fulfillment of the requirements for the CS460 Course, NISER.([Link](http://www.niser.ac.in/~smishra/teach/cs460/project20/group9/))

Project by Group 9

Submitted by Aman Upadhyay | N K U Sarada Anoushka
Guided by Dr. Subhankar Mishra | School of Computer Sciences | NISER, Bhubaneswar
We thank Dr. Bedangadas Mohanty and the team from his lab for extending their help and support towards this project.

Feel free to drop in issues.

### Requirements
- Root ([Link](https://root.cern.ch/))
- .cpp (C++)
- .html (HTML)(opens in default browser)


### Usage
Download the complete repository on your system, some data files are missing here because of the GitHub file size limitations. Please find the files ([here](https://drive.google.com/drive/folders/1Ct1OufrJWz0Fs2-kToG3khRpST4_-32S?usp=sharing)).

#### Folders
- 1.Data
    This folder contains the data file from 3 datasets we created. For more information on the dataset please visit the project website.
- train1_xxx to train7_xxx
    Each of these folders contains 
  - train.cxx file which is used for training the model. 
  - a data file named in the format "CDMSlite_LIP.root".
  - a preprocessing.cxx file which takes in the CDMSlite_LIP.root file and creates the feature vector and saves it in XXX_organise.root file. One can use TBrouwser to check out the file.
  - plot.cxx that generates the input variable histogram plot saved as c1.png
  - weights stored in dataset/weight
- application_on_trX 
  This folder is for the application of the trained model on testing data for further analysis. Each of these folders contains 
  - Data files in format "CDMSlite_LIP_XX.root"
  - app.cxx for application of the trained model.
  - weights of the model stored in dataset/weight
  - app_to_csv.cxx to save the sample data in csv format for getting a feel of the model without installing root.
  - predicted_dataset.csv this file contains 3 columns. First is a PID label, the legend is: 
  
Label | particle
--- | --- 
22 | Gamma
-13 | Muon
2| FCP with charge 1/2
5 | FCP with charge 1/5
10 | FCP with charge 1/10
100 | FCP with charge 1/100
1000 | FCP with charge 1/1000

  - Second is the predicted label and the third is the true label 
  
**Thank You**
