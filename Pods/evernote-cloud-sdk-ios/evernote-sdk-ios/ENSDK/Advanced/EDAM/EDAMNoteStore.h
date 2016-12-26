/*
 * Copyright (c) 2015 by Evernote Corporation, All rights reserved.
 *
 * Use of the source code and binary libraries included in this package
 * is permitted under the following terms:
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * Autogenerated by Thrift Compiler (0.9.2)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

#import <Foundation/Foundation.h>

#import "ENTProtocol.h"
#import "ENTException.h"
#import "FATObject.h"
#import "EDAMUserStore.h"
#import "EDAMTypes.h"
#import "EDAMErrors.h"
#import "EDAMLimits.h"

enum EDAMUserSetting {
  UserSetting_RECEIVE_REMINDER_EMAIL = 1,
  UserSetting_TIMEZONE = 2
};

enum EDAMShareRelationshipPrivilegeLevel {
  ShareRelationshipPrivilegeLevel_READ_NOTEBOOK = 0,
  ShareRelationshipPrivilegeLevel_READ_NOTEBOOK_PLUS_ACTIVITY = 10,
  ShareRelationshipPrivilegeLevel_MODIFY_NOTEBOOK_PLUS_ACTIVITY = 20,
  ShareRelationshipPrivilegeLevel_FULL_ACCESS = 30
};

@interface EDAMSyncState : FATObject 
@property (nonatomic, strong) NSNumber * currentTime; // EDAMTimestamp
@property (nonatomic, strong) NSNumber * fullSyncBefore; // EDAMTimestamp
@property (nonatomic, strong) NSNumber * updateCount; // int32_t
@property (nonatomic, strong) NSNumber * uploaded; // int64_t
@property (nonatomic, strong) NSNumber * userLastUpdated; // EDAMTimestamp
@property (nonatomic, strong) NSNumber * userMaxMessageEventId; // EDAMMessageEventID
@end

@interface EDAMPreferences : FATObject 
@property (nonatomic, strong) NSNumber * updateSequenceNum; // int32_t
@property (nonatomic, strong) NSDictionary * preferences;
@end

@interface EDAMSyncChunk : FATObject 
@property (nonatomic, strong) NSNumber * currentTime; // EDAMTimestamp
@property (nonatomic, strong) NSNumber * chunkHighUSN; // int32_t
@property (nonatomic, strong) NSNumber * updateCount; // int32_t
@property (nonatomic, strong) NSArray * notes;
@property (nonatomic, strong) NSArray * notebooks;
@property (nonatomic, strong) NSArray * tags;
@property (nonatomic, strong) NSArray * searches;
@property (nonatomic, strong) NSArray * resources;
@property (nonatomic, strong) NSArray * expungedNotes;
@property (nonatomic, strong) NSArray * expungedNotebooks;
@property (nonatomic, strong) NSArray * expungedTags;
@property (nonatomic, strong) NSArray * expungedSearches;
@property (nonatomic, strong) NSArray * linkedNotebooks;
@property (nonatomic, strong) NSArray * expungedLinkedNotebooks;
@property (nonatomic, strong) EDAMPreferences * preferences;
@end

@interface EDAMSyncChunkFilter : FATObject 
@property (nonatomic, strong) NSNumber * includeNotes; // BOOL
@property (nonatomic, strong) NSNumber * includeNoteResources; // BOOL
@property (nonatomic, strong) NSNumber * includeNoteAttributes; // BOOL
@property (nonatomic, strong) NSNumber * includeNotebooks; // BOOL
@property (nonatomic, strong) NSNumber * includeTags; // BOOL
@property (nonatomic, strong) NSNumber * includeSearches; // BOOL
@property (nonatomic, strong) NSNumber * includeResources; // BOOL
@property (nonatomic, strong) NSNumber * includeLinkedNotebooks; // BOOL
@property (nonatomic, strong) NSNumber * includeExpunged; // BOOL
@property (nonatomic, strong) NSNumber * includeNoteApplicationDataFullMap; // BOOL
@property (nonatomic, strong) NSNumber * includeResourceApplicationDataFullMap; // BOOL
@property (nonatomic, strong) NSNumber * includeNoteResourceApplicationDataFullMap; // BOOL
@property (nonatomic, strong) NSNumber * includePreferences; // BOOL
@property (nonatomic, strong) NSNumber * includedSharedNotes; // BOOL
@property (nonatomic, strong) NSNumber * omitSharedNotebooks; // BOOL
@property (nonatomic, strong) NSString * requireNoteContentClass;
@property (nonatomic, strong) NSSet * notebookGuids;
@end

@interface EDAMNoteFilter : FATObject 
@property (nonatomic, strong) NSNumber * order; // int32_t
@property (nonatomic, strong) NSNumber * ascending; // BOOL
@property (nonatomic, strong) NSString * words;
@property (nonatomic, strong) EDAMGuid notebookGuid;
@property (nonatomic, strong) NSArray * tagGuids;
@property (nonatomic, strong) NSString * timeZone;
@property (nonatomic, strong) NSNumber * inactive; // BOOL
@property (nonatomic, strong) NSString * emphasized;
@property (nonatomic, strong) NSNumber * includeAllReadableNotebooks; // BOOL
@end

@interface EDAMNoteList : FATObject 
@property (nonatomic, strong) NSNumber * startIndex; // int32_t
@property (nonatomic, strong) NSNumber * totalNotes; // int32_t
@property (nonatomic, strong) NSArray * notes;
@property (nonatomic, strong) NSArray * stoppedWords;
@property (nonatomic, strong) NSArray * searchedWords;
@property (nonatomic, strong) NSNumber * updateCount; // int32_t
@end

@interface EDAMNoteMetadata : FATObject 
@property (nonatomic, strong) EDAMGuid guid;
@property (nonatomic, strong) NSString * title;
@property (nonatomic, strong) NSNumber * contentLength; // int32_t
@property (nonatomic, strong) NSNumber * created; // EDAMTimestamp
@property (nonatomic, strong) NSNumber * updated; // EDAMTimestamp
@property (nonatomic, strong) NSNumber * deleted; // EDAMTimestamp
@property (nonatomic, strong) NSNumber * updateSequenceNum; // int32_t
@property (nonatomic, strong) NSString * notebookGuid;
@property (nonatomic, strong) NSArray * tagGuids;
@property (nonatomic, strong) EDAMNoteAttributes * attributes;
@property (nonatomic, strong) NSString * largestResourceMime;
@property (nonatomic, strong) NSNumber * largestResourceSize; // int32_t
@end

@interface EDAMNotesMetadataList : FATObject 
@property (nonatomic, strong) NSNumber * startIndex; // int32_t
@property (nonatomic, strong) NSNumber * totalNotes; // int32_t
@property (nonatomic, strong) NSArray * notes;
@property (nonatomic, strong) NSArray * stoppedWords;
@property (nonatomic, strong) NSArray * searchedWords;
@property (nonatomic, strong) NSNumber * updateCount; // int32_t
@end

@interface EDAMNotesMetadataResultSpec : FATObject 
@property (nonatomic, strong) NSNumber * includeTitle; // BOOL
@property (nonatomic, strong) NSNumber * includeContentLength; // BOOL
@property (nonatomic, strong) NSNumber * includeCreated; // BOOL
@property (nonatomic, strong) NSNumber * includeUpdated; // BOOL
@property (nonatomic, strong) NSNumber * includeDeleted; // BOOL
@property (nonatomic, strong) NSNumber * includeUpdateSequenceNum; // BOOL
@property (nonatomic, strong) NSNumber * includeNotebookGuid; // BOOL
@property (nonatomic, strong) NSNumber * includeTagGuids; // BOOL
@property (nonatomic, strong) NSNumber * includeAttributes; // BOOL
@property (nonatomic, strong) NSNumber * includeLargestResourceMime; // BOOL
@property (nonatomic, strong) NSNumber * includeLargestResourceSize; // BOOL
@end

@interface EDAMNoteCollectionCounts : FATObject 
@property (nonatomic, strong) NSDictionary * notebookCounts;
@property (nonatomic, strong) NSDictionary * tagCounts;
@property (nonatomic, strong) NSNumber * trashCount; // int32_t
@end

@interface EDAMNoteResultSpec : FATObject 
@property (nonatomic, strong) NSNumber * includeContent; // BOOL
@property (nonatomic, strong) NSNumber * includeResourcesData; // BOOL
@property (nonatomic, strong) NSNumber * includeResourcesRecognition; // BOOL
@property (nonatomic, strong) NSNumber * includeResourcesAlternateData; // BOOL
@property (nonatomic, strong) NSNumber * includeSharedNotes; // BOOL
@end

@interface EDAMAdImpressions : FATObject 
@property (nonatomic, strong) NSNumber * adId; // int32_t
@property (nonatomic, strong) NSNumber * impressionCount; // int32_t
@property (nonatomic, strong) NSNumber * impressionTime; // int32_t
@end

@interface EDAMAdParameters : FATObject 
@property (nonatomic, strong) NSString * clientLanguage;
@property (nonatomic, strong) NSArray * impressions;
@property (nonatomic, strong) NSNumber * supportHtml; // BOOL
@property (nonatomic, strong) NSDictionary * clientProperties;
@end

@interface EDAMNoteEmailParameters : FATObject 
@property (nonatomic, strong) NSString * guid;
@property (nonatomic, strong) EDAMNote * note;
@property (nonatomic, strong) NSArray * toAddresses;
@property (nonatomic, strong) NSArray * ccAddresses;
@property (nonatomic, strong) NSString * subject;
@property (nonatomic, strong) NSString * message;
@end

@interface EDAMNoteVersionId : FATObject 
@property (nonatomic, strong) NSNumber * updateSequenceNum; // int32_t
@property (nonatomic, strong) NSNumber * updated; // EDAMTimestamp
@property (nonatomic, strong) NSNumber * saved; // EDAMTimestamp
@property (nonatomic, strong) NSString * title;
@property (nonatomic, strong) NSNumber * lastEditorId; // EDAMUserID
@end

@interface EDAMClientUsageMetrics : FATObject 
@property (nonatomic, strong) NSNumber * sessions; // int32_t
@property (nonatomic, strong) NSString * subjectConsumerKey;
@property (nonatomic, strong) NSString * subjectConsumerSecret;
@end

@interface EDAMRelatedQuery : FATObject 
@property (nonatomic, strong) NSString * noteGuid;
@property (nonatomic, strong) NSString * plainText;
@property (nonatomic, strong) EDAMNoteFilter * filter;
@property (nonatomic, strong) NSString * referenceUri;
@property (nonatomic, strong) NSString * context;
@property (nonatomic, strong) NSString * cacheKey;
@end

@interface EDAMRelatedResult : FATObject 
@property (nonatomic, strong) NSArray * notes;
@property (nonatomic, strong) NSArray * notebooks;
@property (nonatomic, strong) NSArray * tags;
@property (nonatomic, strong) NSArray * containingNotebooks;
@property (nonatomic, strong) NSString * debugInfo;
@property (nonatomic, strong) NSArray * experts;
@property (nonatomic, strong) NSArray * relatedContent;
@property (nonatomic, strong) NSString * cacheKey;
@property (nonatomic, strong) NSNumber * cacheExpires; // int32_t
@end

@interface EDAMRelatedResultSpec : FATObject 
@property (nonatomic, strong) NSNumber * maxNotes; // int32_t
@property (nonatomic, strong) NSNumber * maxNotebooks; // int32_t
@property (nonatomic, strong) NSNumber * maxTags; // int32_t
@property (nonatomic, strong) NSNumber * writableNotebooksOnly; // BOOL
@property (nonatomic, strong) NSNumber * includeContainingNotebooks; // BOOL
@property (nonatomic, strong) NSNumber * includeDebugInfo; // BOOL
@property (nonatomic, strong) NSNumber * maxExperts; // int32_t
@property (nonatomic, strong) NSNumber * maxRelatedContent; // int32_t
@property (nonatomic, strong) NSSet * relatedContentTypes;
@end

@interface EDAMSearchSuggestionQuery : FATObject 
@property (nonatomic, strong) NSString * prefix;
@property (nonatomic, strong) EDAMNoteFilter * contextFilter;
@end

@interface EDAMSearchSuggestionResultSpec : FATObject 
@property (nonatomic, strong) NSNumber * maxTypeAheadSuggestions; // int32_t
@end

@interface EDAMSearchSuggestion : FATObject 
@property (nonatomic, strong) NSString * suggestionText;
@end

@interface EDAMSearchSuggestionResult : FATObject 
@property (nonatomic, strong) NSArray * typeAheadSuggestions;
@end

@interface EDAMTimeZone : FATObject 
@property (nonatomic, strong) NSString * id;
@property (nonatomic, strong) NSString * displayName;
@property (nonatomic, strong) NSNumber * rawUTCOffsetMillis; // int32_t
@property (nonatomic, strong) NSNumber * dstSavingsAdjustmentMillis; // int32_t
@property (nonatomic, strong) NSNumber * nextEnterDaylightSavings; // EDAMTimestamp
@property (nonatomic, strong) NSNumber * nextLeaveDaylightSavings; // EDAMTimestamp
@end

@interface EDAMTimeZoneSpec : FATObject 
@property (nonatomic, strong) NSString * id;
@property (nonatomic, strong) NSNumber * rawUTCOffsetMillis; // int32_t
@property (nonatomic, strong) NSNumber * dstSavingsAdjustmentMillis; // int32_t
@property (nonatomic, strong) NSNumber * nextEnterDaylightSavings; // EDAMTimestamp
@property (nonatomic, strong) NSNumber * nextLeaveDaylightSavings; // EDAMTimestamp
@end

@interface EDAMContactsQuery : FATObject 
@property (nonatomic, strong) NSNumber * maxEntries; // int32_t
@property (nonatomic, strong) NSString * prefix;
@end

@interface EDAMBusinessQuery : FATObject 
@property (nonatomic, strong) EDAMNoteFilter * filter;
@property (nonatomic, strong) NSNumber * numExperts; // int32_t
@property (nonatomic, strong) NSNumber * includeNotebooks; // BOOL
@property (nonatomic, strong) NSNumber * includeNotesCounts; // BOOL
@end

@interface EDAMBusinessQueryResult : FATObject 
@property (nonatomic, strong) NSNumber * totalNotebooks; // int32_t
@property (nonatomic, strong) NSDictionary * totalNotesByNotebook;
@property (nonatomic, strong) NSArray * experts;
@property (nonatomic, strong) NSArray * matchingNotebooks;
@end

@interface EDAMNoteLockStatus : FATObject 
@property (nonatomic, strong) NSNumber * noteUpdateSequenceNumber; // int32_t
@property (nonatomic, strong) NSNumber * lockHolderUserId; // EDAMUserID
@property (nonatomic, strong) NSNumber * lockRenewBy; // EDAMTimestamp
@property (nonatomic, strong) NSArray * viewingUserIds;
@property (nonatomic, strong) NSNumber * viewIdleExpiration; // int32_t
@property (nonatomic, strong) NSDictionary * unknownUsers;
@end

@interface EDAMUpdateNoteIfUsnMatchesResult : FATObject 
@property (nonatomic, strong) EDAMNote * note;
@property (nonatomic, strong) NSNumber * updated; // BOOL
@end

@interface EDAMShareRelationshipRestrictions : FATObject 
@property (nonatomic, strong) NSNumber * noSetReadOnly; // BOOL
@property (nonatomic, strong) NSNumber * noSetReadPlusActivity; // BOOL
@property (nonatomic, strong) NSNumber * noSetModify; // BOOL
@property (nonatomic, strong) NSNumber * noSetFullAccess; // BOOL
@end

@interface EDAMInvitationShareRelationship : FATObject 
@property (nonatomic, strong) NSString * displayName;
@property (nonatomic, strong) EDAMUserIdentity * recipientUserIdentity;
@property (nonatomic, strong) NSNumber * privilege; // int
@property (nonatomic, strong) NSNumber * allowPreview; // BOOL
@property (nonatomic, strong) NSNumber * sharerUserId; // EDAMUserID
@end

@interface EDAMMemberShareRelationship : FATObject 
@property (nonatomic, strong) NSString * displayName;
@property (nonatomic, strong) NSNumber * recipientUserId; // EDAMUserID
@property (nonatomic, strong) NSNumber * bestPrivilege; // int
@property (nonatomic, strong) NSNumber * individualPrivilege; // int
@property (nonatomic, strong) EDAMShareRelationshipRestrictions * restrictions;
@property (nonatomic, strong) NSNumber * sharerUserId; // EDAMUserID
@end

@interface EDAMShareRelationships : FATObject 
@property (nonatomic, strong) NSArray * invitations;
@property (nonatomic, strong) NSArray * memberships;
@property (nonatomic, strong) EDAMShareRelationshipRestrictions * invitationRestrictions;
@end

@interface EDAMManageNotebookSharesParameters : FATObject 
@property (nonatomic, strong) NSString * notebookGuid;
@property (nonatomic, strong) NSString * inviteMessage;
@property (nonatomic, strong) NSArray * membershipsToUpdate;
@property (nonatomic, strong) NSArray * invitationsToCreateOrUpdate;
@property (nonatomic, strong) NSArray * unshares;
@end

@interface EDAMManageNotebookSharesError : FATObject 
@property (nonatomic, strong) EDAMUserIdentity * userIdentity;
@property (nonatomic, strong) EDAMUserException * userException;
@property (nonatomic, strong) EDAMNotFoundException * notFoundException;
@end

@interface EDAMManageNotebookSharesResult : FATObject 
@property (nonatomic, strong) NSArray * errors;
@end

@interface EDAMSharedNoteTemplate : FATObject 
@property (nonatomic, strong) EDAMGuid noteGuid;
@property (nonatomic, strong) NSNumber * recipientThreadId; // EDAMMessageThreadID
@property (nonatomic, strong) NSArray * recipientContacts;
@property (nonatomic, strong) NSNumber * privilege; // int
@end

@interface EDAMNotebookShareTemplate : FATObject 
@property (nonatomic, strong) EDAMGuid notebookGuid;
@property (nonatomic, strong) NSNumber * recipientThreadId; // EDAMMessageThreadID
@property (nonatomic, strong) NSArray * recipientContacts;
@property (nonatomic, strong) NSNumber * privilege; // int
@end

@interface EDAMCreateOrUpdateNotebookSharesResult : FATObject 
@property (nonatomic, strong) NSNumber * updateSequenceNum; // int32_t
@property (nonatomic, strong) NSArray * matchingShares;
@end

@interface EDAMNoteShareRelationshipRestrictions : FATObject 
@property (nonatomic, strong) NSNumber * noSetReadNote; // BOOL
@property (nonatomic, strong) NSNumber * noSetModifyNote; // BOOL
@property (nonatomic, strong) NSNumber * noSetFullAccess; // BOOL
@end

@interface EDAMNoteMemberShareRelationship : FATObject 
@property (nonatomic, strong) NSString * displayName;
@property (nonatomic, strong) NSNumber * recipientUserId; // EDAMUserID
@property (nonatomic, strong) NSNumber * privilege; // int
@property (nonatomic, strong) EDAMNoteShareRelationshipRestrictions * restrictions;
@property (nonatomic, strong) NSNumber * sharerUserId; // EDAMUserID
@end

@interface EDAMNoteInvitationShareRelationship : FATObject 
@property (nonatomic, strong) NSString * displayName;
@property (nonatomic, strong) NSNumber * recipientIdentityId; // EDAMIdentityID
@property (nonatomic, strong) NSNumber * privilege; // int
@property (nonatomic, strong) NSNumber * sharerUserId; // EDAMUserID
@end

@interface EDAMNoteShareRelationships : FATObject 
@property (nonatomic, strong) NSArray * invitations;
@property (nonatomic, strong) NSArray * memberships;
@property (nonatomic, strong) EDAMNoteShareRelationshipRestrictions * invitationRestrictions;
@end

@interface EDAMManageNoteSharesParameters : FATObject 
@property (nonatomic, strong) NSString * noteGuid;
@property (nonatomic, strong) NSArray * membershipsToUpdate;
@property (nonatomic, strong) NSArray * invitationsToUpdate;
@property (nonatomic, strong) NSArray * membershipsToUnshare;
@property (nonatomic, strong) NSArray * invitationsToUnshare;
@end

@interface EDAMManageNoteSharesError : FATObject 
@property (nonatomic, strong) NSNumber * identityID; // EDAMIdentityID
@property (nonatomic, strong) NSNumber * userID; // EDAMUserID
@property (nonatomic, strong) EDAMUserException * userException;
@property (nonatomic, strong) EDAMNotFoundException * notFoundException;
@end

@interface EDAMManageNoteSharesResult : FATObject 
@property (nonatomic, strong) NSArray * errors;
@end

@protocol EDAMNoteStore <NSObject>
- (EDAMSyncState *) getSyncState: (NSString *) authenticationToken;  // throws EDAMUserException *, EDAMSystemException *, TException
- (EDAMSyncState *) getSyncStateWithMetrics: (NSString *) authenticationToken clientMetrics: (EDAMClientUsageMetrics *) clientMetrics;  // throws EDAMUserException *, EDAMSystemException *, TException
- (EDAMSyncChunk *) getSyncChunk: (NSString *) authenticationToken afterUSN: (int32_t) afterUSN maxEntries: (int32_t) maxEntries fullSyncOnly: (BOOL) fullSyncOnly;  // throws EDAMUserException *, EDAMSystemException *, TException
- (EDAMSyncChunk *) getFilteredSyncChunk: (NSString *) authenticationToken afterUSN: (int32_t) afterUSN maxEntries: (int32_t) maxEntries filter: (EDAMSyncChunkFilter *) filter;  // throws EDAMUserException *, EDAMSystemException *, TException
- (EDAMSyncState *) getLinkedNotebookSyncState: (NSString *) authenticationToken linkedNotebook: (EDAMLinkedNotebook *) linkedNotebook;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (EDAMSyncChunk *) getLinkedNotebookSyncChunk: (NSString *) authenticationToken linkedNotebook: (EDAMLinkedNotebook *) linkedNotebook afterUSN: (int32_t) afterUSN maxEntries: (int32_t) maxEntries fullSyncOnly: (BOOL) fullSyncOnly;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (NSArray *) listNotebooks: (NSString *) authenticationToken;  // throws EDAMUserException *, EDAMSystemException *, TException
- (NSArray *) listPublishedBusinessNotebooks: (NSString *) authenticationToken;  // throws EDAMUserException *, EDAMSystemException *, TException
- (NSArray *) listAccessibleBusinessNotebooks: (NSString *) authenticationToken;  // throws EDAMUserException *, EDAMSystemException *, TException
- (EDAMNotebook *) getNotebook: (NSString *) authenticationToken guid: (EDAMGuid) guid;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (EDAMNotebook *) getDefaultNotebook: (NSString *) authenticationToken;  // throws EDAMUserException *, EDAMSystemException *, TException
- (EDAMNotebook *) createNotebook: (NSString *) authenticationToken notebook: (EDAMNotebook *) notebook;  // throws EDAMUserException *, EDAMSystemException *, TException
- (int32_t) updateNotebook: (NSString *) authenticationToken notebook: (EDAMNotebook *) notebook;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (int32_t) expungeNotebook: (NSString *) authenticationToken guid: (EDAMGuid) guid;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (NSArray *) listTags: (NSString *) authenticationToken;  // throws EDAMUserException *, EDAMSystemException *, TException
- (NSArray *) listTagsByNotebook: (NSString *) authenticationToken notebookGuid: (EDAMGuid) notebookGuid;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (EDAMTag *) getTag: (NSString *) authenticationToken guid: (EDAMGuid) guid;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (EDAMTag *) createTag: (NSString *) authenticationToken tag: (EDAMTag *) tag;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (int32_t) updateTag: (NSString *) authenticationToken tag: (EDAMTag *) tag;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (void) untagAll: (NSString *) authenticationToken guid: (EDAMGuid) guid;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (int32_t) expungeTag: (NSString *) authenticationToken guid: (EDAMGuid) guid;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (NSArray *) listSearches: (NSString *) authenticationToken;  // throws EDAMUserException *, EDAMSystemException *, TException
- (EDAMSavedSearch *) getSearch: (NSString *) authenticationToken guid: (EDAMGuid) guid;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (EDAMSavedSearch *) createSearch: (NSString *) authenticationToken search: (EDAMSavedSearch *) search;  // throws EDAMUserException *, EDAMSystemException *, TException
- (int32_t) updateSearch: (NSString *) authenticationToken search: (EDAMSavedSearch *) search;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (int32_t) expungeSearch: (NSString *) authenticationToken guid: (EDAMGuid) guid;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (EDAMNoteList *) findNotes: (NSString *) authenticationToken filter: (EDAMNoteFilter *) filter offset: (int32_t) offset maxNotes: (int32_t) maxNotes;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (int32_t) findNoteOffset: (NSString *) authenticationToken filter: (EDAMNoteFilter *) filter guid: (EDAMGuid) guid;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (EDAMNotesMetadataList *) findNotesMetadata: (NSString *) authenticationToken filter: (EDAMNoteFilter *) filter offset: (int32_t) offset maxNotes: (int32_t) maxNotes resultSpec: (EDAMNotesMetadataResultSpec *) resultSpec;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (EDAMNoteCollectionCounts *) findNoteCounts: (NSString *) authenticationToken filter: (EDAMNoteFilter *) filter withTrash: (BOOL) withTrash;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (EDAMNote *) getNoteWithResultSpec: (NSString *) authenticationToken guid: (EDAMGuid) guid resultSpec: (EDAMNoteResultSpec *) resultSpec;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (EDAMNote *) getNote: (NSString *) authenticationToken guid: (EDAMGuid) guid withContent: (BOOL) withContent withResourcesData: (BOOL) withResourcesData withResourcesRecognition: (BOOL) withResourcesRecognition withResourcesAlternateData: (BOOL) withResourcesAlternateData;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (EDAMPreferences *) getPreferences: (NSString *) authenticationToken preferenceNames: (NSArray *) preferenceNames;  // throws EDAMUserException *, EDAMSystemException *, TException
- (int32_t) updatePreferences: (NSString *) authenticationToken preferencesToUpdate: (NSDictionary *) preferencesToUpdate;  // throws EDAMUserException *, EDAMSystemException *, TException
- (EDAMLazyMap *) getNoteApplicationData: (NSString *) authenticationToken guid: (EDAMGuid) guid;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (NSString *) getNoteApplicationDataEntry: (NSString *) authenticationToken guid: (EDAMGuid) guid key: (NSString *) key;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (int32_t) setNoteApplicationDataEntry: (NSString *) authenticationToken guid: (EDAMGuid) guid key: (NSString *) key value: (NSString *) value;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (int32_t) unsetNoteApplicationDataEntry: (NSString *) authenticationToken guid: (EDAMGuid) guid key: (NSString *) key;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (NSString *) getNoteContent: (NSString *) authenticationToken guid: (EDAMGuid) guid;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (NSString *) getNoteSearchText: (NSString *) authenticationToken guid: (EDAMGuid) guid noteOnly: (BOOL) noteOnly tokenizeForIndexing: (BOOL) tokenizeForIndexing;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (NSString *) getResourceSearchText: (NSString *) authenticationToken guid: (EDAMGuid) guid;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (NSArray *) getNoteTagNames: (NSString *) authenticationToken guid: (EDAMGuid) guid;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (EDAMNote *) createNote: (NSString *) authenticationToken note: (EDAMNote *) note;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (EDAMNote *) updateNote: (NSString *) authenticationToken note: (EDAMNote *) note;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (int32_t) deleteNote: (NSString *) authenticationToken guid: (EDAMGuid) guid;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (int32_t) expungeNote: (NSString *) authenticationToken guid: (EDAMGuid) guid;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (int32_t) expungeNotes: (NSString *) authenticationToken noteGuids: (NSArray *) noteGuids;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (int32_t) expungeInactiveNotes: (NSString *) authenticationToken;  // throws EDAMUserException *, EDAMSystemException *, TException
- (EDAMNote *) copyNote: (NSString *) authenticationToken noteGuid: (EDAMGuid) noteGuid toNotebookGuid: (EDAMGuid) toNotebookGuid;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (NSArray *) listNoteVersions: (NSString *) authenticationToken noteGuid: (EDAMGuid) noteGuid;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (EDAMNote *) getNoteVersion: (NSString *) authenticationToken noteGuid: (EDAMGuid) noteGuid updateSequenceNum: (int32_t) updateSequenceNum withResourcesData: (BOOL) withResourcesData withResourcesRecognition: (BOOL) withResourcesRecognition withResourcesAlternateData: (BOOL) withResourcesAlternateData;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (EDAMResource *) getResource: (NSString *) authenticationToken guid: (EDAMGuid) guid withData: (BOOL) withData withRecognition: (BOOL) withRecognition withAttributes: (BOOL) withAttributes withAlternateData: (BOOL) withAlternateData;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (EDAMLazyMap *) getResourceApplicationData: (NSString *) authenticationToken guid: (EDAMGuid) guid;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (NSString *) getResourceApplicationDataEntry: (NSString *) authenticationToken guid: (EDAMGuid) guid key: (NSString *) key;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (int32_t) setResourceApplicationDataEntry: (NSString *) authenticationToken guid: (EDAMGuid) guid key: (NSString *) key value: (NSString *) value;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (int32_t) unsetResourceApplicationDataEntry: (NSString *) authenticationToken guid: (EDAMGuid) guid key: (NSString *) key;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (int32_t) updateResource: (NSString *) authenticationToken resource: (EDAMResource *) resource;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (NSData *) getResourceData: (NSString *) authenticationToken guid: (EDAMGuid) guid;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (EDAMResource *) getResourceByHash: (NSString *) authenticationToken noteGuid: (EDAMGuid) noteGuid contentHash: (NSData *) contentHash withData: (BOOL) withData withRecognition: (BOOL) withRecognition withAlternateData: (BOOL) withAlternateData;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (NSData *) getResourceRecognition: (NSString *) authenticationToken guid: (EDAMGuid) guid;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (NSData *) getResourceAlternateData: (NSString *) authenticationToken guid: (EDAMGuid) guid;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (EDAMResourceAttributes *) getResourceAttributes: (NSString *) authenticationToken guid: (EDAMGuid) guid;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (NSArray *) getAds: (NSString *) authenticationToken adParameters: (EDAMAdParameters *) adParameters;  // throws EDAMUserException *, EDAMSystemException *, TException
- (EDAMAd *) getRandomAd: (NSString *) authenticationToken adParameters: (EDAMAdParameters *) adParameters;  // throws EDAMUserException *, EDAMSystemException *, TException
- (EDAMNotebook *) getPublicNotebook: (EDAMUserID) userId publicUri: (NSString *) publicUri;  // throws EDAMSystemException *, EDAMNotFoundException *, TException
- (EDAMSharedNotebook *) createSharedNotebook: (NSString *) authenticationToken sharedNotebook: (EDAMSharedNotebook *) sharedNotebook;  // throws EDAMUserException *, EDAMNotFoundException *, EDAMSystemException *, TException
- (EDAMSharedNotebook *) shareNotebook: (NSString *) authenticationToken sharedNotebook: (EDAMSharedNotebook *) sharedNotebook message: (NSString *) message;  // throws EDAMUserException *, EDAMNotFoundException *, EDAMSystemException *, TException
- (EDAMCreateOrUpdateNotebookSharesResult *) createOrUpdateNotebookShares: (NSString *) authenticationToken shareTemplate: (EDAMNotebookShareTemplate *) shareTemplate;  // throws EDAMUserException *, EDAMNotFoundException *, EDAMSystemException *, EDAMInvalidContactsException *, TException
- (int32_t) updateSharedNotebook: (NSString *) authenticationToken sharedNotebook: (EDAMSharedNotebook *) sharedNotebook;  // throws EDAMUserException *, EDAMNotFoundException *, EDAMSystemException *, TException
- (int32_t) setSharedNotebookRecipientSettings: (NSString *) authenticationToken sharedNotebookId: (int64_t) sharedNotebookId recipientSettings: (EDAMSharedNotebookRecipientSettings *) recipientSettings;  // throws EDAMUserException *, EDAMNotFoundException *, EDAMSystemException *, TException
- (EDAMNotebook *) setNotebookRecipientSettings: (NSString *) authenticationToken notebookGuid: (NSString *) notebookGuid recipientSettings: (EDAMNotebookRecipientSettings *) recipientSettings;  // throws EDAMUserException *, EDAMNotFoundException *, EDAMSystemException *, TException
- (int32_t) sendMessageToSharedNotebookMembers: (NSString *) authenticationToken notebookGuid: (EDAMGuid) notebookGuid messageText: (NSString *) messageText recipients: (NSArray *) recipients;  // throws EDAMUserException *, EDAMNotFoundException *, EDAMSystemException *, TException
- (NSArray *) listSharedNotebooks: (NSString *) authenticationToken;  // throws EDAMUserException *, EDAMNotFoundException *, EDAMSystemException *, TException
- (int32_t) expungeSharedNotebooks: (NSString *) authenticationToken sharedNotebookIds: (NSArray *) sharedNotebookIds;  // throws EDAMUserException *, EDAMNotFoundException *, EDAMSystemException *, TException
- (EDAMLinkedNotebook *) createLinkedNotebook: (NSString *) authenticationToken linkedNotebook: (EDAMLinkedNotebook *) linkedNotebook;  // throws EDAMUserException *, EDAMNotFoundException *, EDAMSystemException *, TException
- (int32_t) updateLinkedNotebook: (NSString *) authenticationToken linkedNotebook: (EDAMLinkedNotebook *) linkedNotebook;  // throws EDAMUserException *, EDAMNotFoundException *, EDAMSystemException *, TException
- (NSArray *) listLinkedNotebooks: (NSString *) authenticationToken;  // throws EDAMUserException *, EDAMNotFoundException *, EDAMSystemException *, TException
- (int32_t) expungeLinkedNotebook: (NSString *) authenticationToken guid: (EDAMGuid) guid;  // throws EDAMUserException *, EDAMNotFoundException *, EDAMSystemException *, TException
- (EDAMAuthenticationResult *) authenticateToSharedNotebook: (NSString *) shareKeyOrGlobalId authenticationToken: (NSString *) authenticationToken;  // throws EDAMUserException *, EDAMNotFoundException *, EDAMSystemException *, TException
- (EDAMSharedNotebook *) getSharedNotebookByAuth: (NSString *) authenticationToken;  // throws EDAMUserException *, EDAMNotFoundException *, EDAMSystemException *, TException
- (void) emailNote: (NSString *) authenticationToken parameters: (EDAMNoteEmailParameters *) parameters;  // throws EDAMUserException *, EDAMNotFoundException *, EDAMSystemException *, TException
- (NSString *) shareNote: (NSString *) authenticationToken guid: (EDAMGuid) guid;  // throws EDAMUserException *, EDAMNotFoundException *, EDAMSystemException *, TException
- (void) stopSharingNote: (NSString *) authenticationToken guid: (EDAMGuid) guid;  // throws EDAMUserException *, EDAMNotFoundException *, EDAMSystemException *, TException
- (EDAMAuthenticationResult *) authenticateToSharedNote: (NSString *) guid noteKey: (NSString *) noteKey authenticationToken: (NSString *) authenticationToken;  // throws EDAMUserException *, EDAMNotFoundException *, EDAMSystemException *, TException
- (EDAMRelatedResult *) findRelated: (NSString *) authenticationToken query: (EDAMRelatedQuery *) query resultSpec: (EDAMRelatedResultSpec *) resultSpec;  // throws EDAMUserException *, EDAMSystemException *, EDAMNotFoundException *, TException
- (EDAMBusinessQueryResult *) findInBusiness: (NSString *) authenticationToken query: (EDAMBusinessQuery *) query;  // throws EDAMUserException *, EDAMSystemException *, TException
@end

// !!! The inProtocol and outProtocol getters are manual additions to the autogenerated file. These allow owners to hook the protocols
// and add upload/download progress to them. All that's been added is the accessor declarations and trivial implementation. -BZ.
@interface EDAMNoteStoreClient : NSObject <EDAMNoteStore> 
- (id) initWithProtocol: (id <ENTProtocol>) protocol;
- (id) initWithInProtocol: (id <ENTProtocol>) inProtocol outProtocol: (id <ENTProtocol>) outProtocol;
- (id<ENTProtocol>)inProtocol;
- (id<ENTProtocol>)outProtocol;
@end

@interface EDAMNoteStoreConstants : NSObject 
@end