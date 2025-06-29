from pymongo import MongoClient
from bson.objectid import ObjectId

class AnimalShelter(object):
	def __init__(self):
		USER = 'aacuser'
		PASS = 'SNHU1234'
		HOST = 'nv-desktop-services.apporto.com'
		PORT = 33952
		DB   = 'AAC'
		COL  = 'animals'

		self.client = MongoClient('mongodb://%s:%s@%s:%d' % (USER,PASS,HOST,PORT))
		self.database = self.client['%s' % (DB)]
		self.collection = self.database['%s' % (COL)]

	def create(self, data):
		try:
			if data:
				if isinstance(data, dict):
					self.database.animals.insert_one(data)
					return True
				else:
					raise ValueError("Incorrect data format")
			else:
				raise ValueError("Nothing to save. Data parameter is empty")
			return False
		except Exception as error:
			print("Error: " + repr(error))

	def read(self, lookup):
		try:
			if lookup:
				if isinstance(lookup, dict):
					result = self.database.animals.find(lookup)
					result_as_list = list(result)
					result.close()
					return result_as_list
				else:
					raise ValueError("Incorrect data format")
			else:
				raise ValueError("Nothing to search. Data parameter is empty")
			return []
		except Exception as error:
			print("Error: " + repr(error))
	
	def update(self, lookup, newData):
		try:
			if lookup and newData:
				if isinstance(lookup, dict) and isinstance(newData, dict):
				
					resultFind = self.database.animals.find(lookup)
					if resultFind.count() > 1:
						result = self.database.animals.update_many(lookup, newData)
					else:
						result = self.database.animals.update_one(lookup, newData)
					resultFind.close()
					return result.modified_count
				
				else:
					raise ValueError("Incorrect data format")
			else:
				raise ValueError("Nothing to search. Data parameter is empty")
		except Exception as error:
			print("Error: " + repr(error))
	
	def delete(self, lookup):
		try:
			if lookup:
				if isinstance(lookup, dict):
				
					resultFind = self.database.animals.find(lookup)
					if resultFind.count() > 1:
						result = self.database.animals.delete_many(lookup)
					else:
						result = self.database.animals.delete_one(lookup)
					resultFind.close()
					return result.deleted_count
				
				else:
					raise ValueError("Incorrect data format")
			else:
				raise ValueError("Nothing to search. Data parameter is empty")
		except Exception as error:
			print("Error: " + repr(error))
