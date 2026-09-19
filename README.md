# Smart Hospital & Resource Allocation System #

## Project Overview

The Smart Hospital Patient & Resource Allocation System is a modular, menu-driven application designed to simulate daily patient intake, bed allocation, emergency triage sorting, and medical billing estimations. This project is developed in C and incorporates fundamental programming concepts including arrays, custom functions, string handling, loops, conditionals, and basic file handling.

## Objectives

- To implement a patient intake system with data collection for various parameters.
- To utilize algorithms to calculate estimated waiting times and billing.
- Generate performance reports and analytics on patient admissions and hospital resources.

## Features

Patient Registration : Collects patient details including name, age, specialty selection, and admission status.
Billing Calculations : Calculates gross total, emergency surcharges, and final payable amounts based on patient demographics.
Bed Management : Monitors bed occupancy status across different wards.
Emergency Triage Sorting : Organizes registered patients based on urgency levels and registration order.
Performance Reporting : Generates reports on total patients, revenue, discounts, and bed occupancy rates.
File Handling : Maintains permanent records of patient billing logs and bed statuses.

## File Structure
Modularity was used well to build the program readably, maintain ably and memory friendly. Each function does a well-planned task. Function prototypes are written in the header file. All functions are called in the main function and are defined in the c file of hospital_body.
So many 1D and 2D arrays are implemented to store all the data in the system mostly comes from inputs. Various types of data are passed into function callings. The logical and syntax precision of variables and arrays was very important to succeed all the required tasks.
Structures have done a great job to store and print basic data in tables such as Doctor Specialties Data and Hospital Wards Data.
Text files are used for file handling. It was a new experience to store a program's data in non-volatile memory rather than volatile memory.
