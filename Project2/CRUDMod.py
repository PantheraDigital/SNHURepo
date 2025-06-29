from pymongo import MongoClient
from bson.objectid import ObjectId

class AnimalShelter(object):
	def __init__(self, username, password):
		USER = username#'aacuser'
		PASS = password#'SNHU1234'
		HOST = 'nv-desktop-services.apporto.com'
		PORT = 33952
		DB   = 'AAC'
		COL  = 'animals'

		self.client = MongoClient('mongodb://%s:%s@%s:%d' % (USER,PASS,HOST,PORT))
		self.database = self.client['%s' % (DB)]
		self.collection = self.database['%s' % (COL)]

	def create(self, data):
		try:
			if self.client is None:
				return False
			if data:
				if isinstance(data, dict):
					self.collection.insert_one(data)
					return True
				else:
					raise ValueError("Incorrect data format")
			else:
				raise ValueError("Nothing to save. Data parameter is empty")
			return False
		except Exception as error:
			print("Error: " + repr(error))
			return False

	def read(self, lookup):
		try:
			if self.client is None:
				return []
			if isinstance(lookup, dict):
				result = self.collection.find(lookup)
				result_as_list = list(result)
				result.close()
				return result_as_list
			else:
				raise ValueError("Incorrect data format")
			return []
		except Exception as error:
			print("Error: " + repr(error))
			return []
	
	def update(self, lookup, newData):
		try:
			if self.client is None:
				return 0
			if lookup and newData:
				if isinstance(lookup, dict) and isinstance(newData, dict):
				
					resultFind = self.collection.find(lookup)
					if resultFind.count() > 1:
						result = self.collection.update_many(lookup, {'$set':newData})
					else:
						result = self.collection.update_one(lookup, {'$set':newData})
					resultFind.close()
					return result.modified_count
				
				else:
					raise ValueError("Incorrect data format")
			else:
				raise ValueError("Nothing to search. Data parameter is empty")
		except Exception as error:
			print("Error: " + repr(error))
			return 0
	
	def delete(self, lookup):
		try:
			if self.client is None:
				return 0
			if lookup:
				if isinstance(lookup, dict):
				
					try:
						result = self.collection.delete_many(lookup)
						return result.deleted_count
					except OperationFailure as error:
						print(f"Delete failed: {error}")
						return 0
				
				else:
					raise ValueError("Incorrect data format")
			else:
				raise ValueError("Nothing to search. Data parameter is empty")
		except Exception as error:
			print("Error: " + repr(error))
			return 0
