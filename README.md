# Full Stack Development

In this course I have learned about containerization through the use of Docker and how to move a website to the cloud, specifically with AWS. This has given me a better understanding of cloud based architecture and how different services are brought together to make web apps.

Using the knowledge from this class I am more prepared to become a web developer.


Exploring our final project further, I don't see scaling becoming an issue as the use of AWS resources will automatically handle that. Cost prediction can be achieved by watching the cost of the website over time to find an average, then factor in any expected advertisements and large updates that may draw in more users. 

Between containers and serverless, containers seem to be the most predictable for costs assuming they are on local servers. Serverless is directly tied to use which can fluctuate but having physical servers may be more predictable as cost of bills and maintenance would keep expenses steady. 

For expansion of the serverless website, one con would be potentially having to consider the structure of the DynamoDB if it were to become more heavily used for a wider array of data. Another would be unforeseen costs from the services due to mistakes in development or spikes in users from unexpected popularity. This would be a con as planning around keys could become a problem in order to maintain the key value structure. Pros however are that the foundation has be established and the use of AWS resources makes it easy to ad more to the site, like expanding the API or updating the S3 bucket with the website. Another pro is the security and infrastructure AWS provides, which inherently improves the strength of the website under high user traffic or possible attack.

While planing for expansion, elasticity and pay-for-service do need to be considered for future growth. Elasticity allows the site to gain the resources it needs to run as the traffic increases and the site grows. The pay-for-service model will also grow as the site grows due to increased resource usage. Something to consider would be limiting growth to prevent debt. This could be through limiting the number if users at any time or by optimizing the site and preventing additions for a while to reduce complexity and service usage. 

AWS services used: S3 bucket, Lambda, DynamoDB, API Gateway
