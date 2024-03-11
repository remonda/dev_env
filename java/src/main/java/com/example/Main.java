package com.example;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

public class Main {

    private static final Logger logger = LogManager.getLogger("myLogger");

    public static void main(String[] args) {
        logger.debug("it is a debug message");
        logger.info("this is the start of kafka");
    }
}
