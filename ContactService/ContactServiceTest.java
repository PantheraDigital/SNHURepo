package ContactService;

import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.BeforeEach;

public class ContactServiceTest {

    private ContactService service;

    @BeforeEach
    void setUp() {
    	service = new ContactService();
    }
    
    // add //
    @Test
    void testAddContactValid() {
        Contact contact = new Contact("123", "John", "Doe", "1234567890", "123 Main St");
        service.addContact(contact);
        assertEquals(contact, service.getContact("123"));
    }

    @Test
    void testAddContactDuplicateID() {
        Contact contact1 = new Contact("123", "John", "Doe", "1234567890", "123 Main St");
        Contact contact2 = new Contact("123", "Jane", "Smith", "0987654321", "456 Oak Ave");
        service.addContact(contact1);
        assertThrows(IllegalArgumentException.class, () -> service.addContact(contact2));
    }

    @Test
    void testAddContactNullContact() {
        assertThrows(IllegalArgumentException.class, () -> service.addContact(null));
    }

    // delete //
    @Test
    void testDeleteContactValid() {
        Contact contact = new Contact("123", "John", "Doe", "1234567890", "123 Main St");
        service.addContact(contact);
        service.deleteContact("123");
        assertNull(service.getContact("123"));
    }

    @Test
    void testDeleteContactNonExistingID() {
        assertThrows(IllegalArgumentException.class, () -> service.deleteContact("123"));
    }

    @Test
    void testDeleteContactNullID() {
        assertThrows(IllegalArgumentException.class, () -> service.deleteContact(null));
    }

    @Test
    void testDeleteContactEmptyID() {
        assertThrows(IllegalArgumentException.class, () -> service.deleteContact(""));
    }

    // update //
    @Test
    void testUpdateContactValid() {
        Contact contact = new Contact("123", "John", "Doe", "1234567890", "123 Main St");
        service.addContact(contact);
        service.updateContact("123", "Jane", "Smith", "0987654321", "456 Oak Ave");
        Contact updatedContact = service.getContact("123");
        assertEquals("Jane", updatedContact.getFirstName());
    }

    @Test
    void testUpdateContactNameOnlyValid() {
        Contact contact = new Contact("123", "John", "Doe", "1234567890", "123 Main St");
        service.addContact(contact);
        service.updateContact("123", "Robert", null, null, null);
        Contact updatedContact = service.getContact("123");
        assertEquals(updatedContact, new Contact("123", "Robert", "Doe", "1234567890", "123 Main St"));
    }

    @Test
    void testUpdateContactNonExistingID() {
        assertThrows(IllegalArgumentException.class, () -> service.updateContact("123", "John", "Doe", "1234567890", "123 Main St"));
    }

    @Test
    void testUpdateContactNullID() {
        assertThrows(IllegalArgumentException.class, () -> service.updateContact(null, "New", "Name", "9999999999", "33 Elm St"));
    }

    @Test
    void testUpdateContactEmptyID() {
        assertThrows(IllegalArgumentException.class, () -> service.updateContact("", "New", "Name", "9999999999", "33 Elm St"));
    }

    // get //
    @Test
    void testGetContactValid() {
        Contact contact = new Contact("123", "John", "Doe", "1234567890", "123 Main St");
        service.addContact(contact);
        Contact retrievedContact = service.getContact("123");
        assertEquals(contact, retrievedContact);
    }

    @Test
    void testGetContactNonExistingID() {
        assertNull(service.getContact("123"));
    }
}