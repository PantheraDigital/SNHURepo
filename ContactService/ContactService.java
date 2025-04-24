package ContactService;

import java.util.HashMap;
import java.util.Map;

public class ContactService {

    private final Map<String, Contact> contacts = new HashMap<>();

    public void addContact(Contact contact) {
        if (contact == null) {
            throw new IllegalArgumentException("Contact cannot be null.");
        }
        if (contacts.containsKey(contact.getContactID())) {
            throw new IllegalArgumentException("Contact with ID " + contact.getContactID() + " already exists.");
        }
        contacts.put(contact.getContactID(), contact);
    }

    public void deleteContact(String contactID) {
        if (contactID == null || contactID.trim().isEmpty()) {
            throw new IllegalArgumentException("Contact ID cannot be null or empty.");
        }
        if (!contacts.containsKey(contactID)) {
            throw new IllegalArgumentException("Contact with ID " + contactID + " does not exist.");
        }
        contacts.remove(contactID);
    }

    public void updateContact(String contactID, String firstName, String lastName, String phone, String address) {
        if (contactID == null || contactID.trim().isEmpty()) {
            throw new IllegalArgumentException("Contact ID cannot be null or empty.");
        }
        if (!contacts.containsKey(contactID)) {
            throw new IllegalArgumentException("Contact with ID " + contactID + " does not exist.");
        }
        Contact contact = contacts.get(contactID);
        if (firstName != null) {
            contact.setFirstName(firstName);
        }
        if (lastName != null) {
            contact.setLastName(lastName);
        }
        if (phone != null) {
            contact.setPhone(phone);
        }
        if (address != null) {
            contact.setAddress(address);
        }
    }

    public Contact getContact(String contactID) {
        return contacts.get(contactID);
    }
}