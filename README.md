# SNHURepo
Artemis Financial is a consulting company that develops individualized financial plans for its customers. The financial plans include savings, retirement, investments, and insurance. They use a custom software that they would like to make sure is secure for their clients to use. 

Secure coding is important since bugs or even poor error handling can lead to vulnerabilities that attackers can leverage to either gain access to sensitive data or prevent users from using a service. If this happens it can damage a company’s reputation and possibly make them lose clients. 

During this project I found it difficult to fully understand the Maven dependency report as there are many dependencies, each with their own list of vulnerabilities that need handling, but not all are necessary as they could be false positives. 

Security for Artemis Financial was improved by using an HTTPS connection to clients, using SHA-256 for a checksum to validate data, performing code reviews to find any weaknesses in code architecture, and by performing dependency checks to find weaknesses that may have been introduced through the use of other libraries. The use of static testing was also useful in making sure the code was secure throughout the development of the code as checks could be done quickly after changes were made, making sure vulnerabilities were dealt with. 

